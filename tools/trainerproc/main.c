/* trainerprpc
 * Parses teams in the competitive format (as used by Showdown) and
 * converts them into the internal team format. */

/* To add a new member to 'TrainerMon':
 * 1. Add the same member to 'Pokemon'.
 * 2. Parse that member in 'parse_trainer', probably in the 'parse_attribute' loop.
 * 3. Format that member in 'fprint_trainers'. */
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_TRAINER_AI_FLAGS 32
#define MAX_TRAINER_ITEMS 4
#define PARTY_SIZE 6
#define MAX_MON_MOVES 4

struct String
{
    const unsigned char *string;
    int string_n;
};

struct Stats
{
    int hp, attack, defense, special_attack, special_defense, speed;
};

enum Gender
{
    GENDER_ANY,
    GENDER_MALE,
    GENDER_FEMALE,
};

// TODO: Support Hidden Power.
struct Pokemon
{
    struct String nickname;
    struct String species;
    enum Gender gender;
    struct String item;
    int header_line;

    struct Stats evs;
    int evs_line;

    struct Stats ivs;
    int ivs_line;

    struct String ability;
    int ability_line;

    int level;
    int level_line;

    struct String ball;
    int ball_line;

    int friendship;
    int friendship_line;

    struct String nature;
    int nature_line;

    bool shiny;
    int shiny_line;

    int dynamax_level;
    int dynamax_level_line;

    bool gigantamax_factor;
    bool gigantamax_factor_line;

    struct String tera_type;
    int tera_type_line;

    struct String moves[MAX_MON_MOVES];
    int moves_n;
    int move1_line;
};

struct Trainer
{
    struct String id;
    int id_line;

    struct String ai_flags[MAX_TRAINER_AI_FLAGS];
    int ai_flags_n;
    int ai_flags_line;

    struct String items[MAX_TRAINER_ITEMS];
    int items_n;
    int items_line;

    struct String class;
    int class_line;

    struct String encounter_music;
    int encounter_music_line;

    enum Gender gender;
    int gender_line;

    struct String pic;
    int pic_line;

    struct String name;
    int name_line;

    bool double_battle;
    int double_battle_line;

    struct Pokemon pokemon[PARTY_SIZE];
    int pokemon_n;

    struct String mugshot;
    int mugshot_line;

    struct String starting_status;
    int starting_status_line;
};

static bool is_empty_string(struct String s)
{
    return s.string_n == 0;
}

static bool is_literal_string(struct String s1, const char *s2)
{
    for (int i = 0;; i++)
    {
        if (i == s1.string_n && s2[i] == '\0')
            return true;
        else if (i == s1.string_n || s2[i] == '\0')
            return false;
        else if (s1.string[i] != s2[i])
            return false;
    }
}

static bool starts_with(struct String s, const char *prefix)
{
    int n = strlen(prefix);
    return strncmp((const char *)s.string, prefix, n) == 0;
}

static bool ends_with(struct String s, const char *suffix)
{
    int n = strlen(suffix);
    if (n > s.string_n)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s.string[s.string_n - i - 1] != suffix[n - i - 1])
                return false;
        }
        return true;
    }
}

static struct String literal_string(const char *s)
{
    return (struct String) {
        .string = (const unsigned char *)s,
        .string_n = strlen(s),
    };
}

struct Source
{
    const char *path;
    const unsigned char *buffer;
    int buffer_n;
};

struct SourceLocation
{
    int line;
    int column;
};

struct Token
{
    const struct Source *source;
    struct SourceLocation location;
    int begin;
    int end;
};

static bool is_empty_token(const struct Token *t)
{
    return t->begin == t->end;
}

// TODO: Make case-insensitive?
static bool is_literal_token(const struct Token *t, const char *s)
{
    int i = t->begin;
    for (;;)
    {
        if (*s == '\0' && i == t->end)
            return true;
        else if (*s == '\0' || i == t->end)
            return false;
        else if (*s != t->source->buffer[i])
            return false;
        i++;
        s++;
    }
}

struct Parser
{
    struct Source *source;
    struct SourceLocation location;
    int offset;
    struct SourceLocation error_location;
    const char *error;
    bool fatal_error;
};

struct Parsed
{
    const struct Source *source;

    struct Trainer *trainers;
    int trainers_n;

    struct Stats default_ivs;
    int default_ivs_line;
    bool default_ivs_off;

    int default_level;
    int default_level_line;
    bool default_level_off;
};

static bool set_parse_error(struct Parser *p, struct SourceLocation location, const char *error)
{
    p->error = error;
    p->error_location = location;
    return false;
}

static bool show_parse_error(struct Parser *p)
{
    // Print error message.
    int n = fprintf(stderr, "%s:%d: ", p->source->path, p->error_location.line);
    fprintf(stderr, "error: %s\n", p->error);

    // Seek to the line.
    int line, begin, end;
    for (line = 1, begin = 0; begin < p->source->buffer_n; begin++)
    {
        if (p->error_location.line == line)
            break;
        if (p->source->buffer[begin] == '\n')
            line++;
    }
    for (end = begin; end < p->source->buffer_n; end++)
    {
        if (p->source->buffer[end] == '\n')
            break;
    }

    // Print the source line.
    fprintf(stderr, "%s:%d: %.*s\n", p->source->path, p->error_location.line, end - begin, &p->source->buffer[begin]);

    // Print caret pointing at the column.
    fprintf(stderr, "%*s", n, "");
    for (int column = 1; column < p->error_location.column && begin + column < end; column++)
    {
        unsigned char c = p->source->buffer[begin + column];
        fputc(c == '\t' ? c : ' ', stderr);
    }
    fprintf(stderr, "^\n");

    p->error = NULL;
    p->fatal_error = true;

    return false;
}

static bool set_show_parse_error(struct Parser *p, struct SourceLocation location, const char *error)
{
    set_parse_error(p, location, error);
    return show_parse_error(p);
}

__attribute__((warn_unused_result))
static bool peek_char(struct Parser *p, unsigned char *c)
{
    assert(p && c);
    if (p->offset == p->source->buffer_n)
        return false;
    *c = p->source->buffer[p->offset];
    return true;
}

__attribute__((warn_unused_result))
static bool pop_char(struct Parser *p, unsigned char *c)
{
    assert(p && c);
    if (p->offset == p->source->buffer_n)
        return false;
    *c = p->source->buffer[p->offset++];
    if (*c == '\n')
    {
        p->location.line++;
        p->location.column = 1;
    }
    else
    {
        p->location.column++;
    }
    return true;
}

static void skip_whitespace(struct Parser *p)
{
    assert(p);
    unsigned char c;
    for (;;)
    {
        if (!peek_char(p, &c))
            break;
        if (c != ' ' && c != '\t')
            break;
        if (!pop_char(p, &c))
            assert(false);
    }
}

static void skip_line(struct Parser *p)
{
    assert(p);
    unsigned char c;
    for (;;)
    {
        if (!pop_char(p, &c))
            break;
        if (c == '\n')
            break;
    }
}

__attribute__((warn_unused_result))
static bool match_eof(struct Parser *p)
{
    return p->offset == p->source->buffer_n;
}

__attribute__((warn_unused_result))
static bool match_exact(struct Parser *p, const char *s)
{
    assert(p && s);
    struct Parser p_ = *p;
    unsigned char c;

    for (; *s != '\0'; s++)
    {
        if (!pop_char(&p_, &c))
            return false;
        if (*s != c)
            return false;
    }

    *p = p_;
    return true;
}

static void match_until_eol(struct Parser *p, struct Token *t)
{
    assert(p && t);
    unsigned char c;

    skip_whitespace(p);

    t->source = p->source;
    t->location = p->location;
    t->begin = p->offset;
    t->end = p->offset;

    for (;;)
    {
        if (!peek_char(p, &c))
            break;
        if (c == '\n')
            break;
        if (!pop_char(p, &c))
            assert(false);
        if (c != ' ' && c != '\t')
            t->end = p->offset;
    }
}

__attribute__((warn_unused_result))
static bool match_eol(struct Parser *p)
{
    struct Parser p_ = *p;
    unsigned char c;

    skip_whitespace(&p_);
    for (;;)
    {
        if (!pop_char(&p_, &c))
            return false;

        if (c == '\n')
            break;
        else
            return false;
    }

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool match_empty_line(struct Parser *p)
{
    return match_eol(p);
}

__attribute__((warn_unused_result))
static bool match_int(struct Parser *p, int *i)
{
    assert(p && i);
    struct Parser p_ = *p;
    unsigned char c;

    *i = 0;
    for (;;)
    {
        if (!peek_char(&p_, &c))
            break;
        if (!('0' <= c && c <= '9'))
            break;
        *i = *i * 10 + (c - '0');
        if (!pop_char(&p_, &c))
            assert(false);
    }

    if (p->offset == p_.offset)
        return false;

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool match_identifier(struct Parser *p, struct Token *t)
{
    assert(p && t);
    struct Parser p_ = *p;
    unsigned char c;

    t->source = p->source;
    t->location = p->location;
    t->begin = p->offset;

    for (;;)
    {
        if (!peek_char(&p_, &c))
            break;

        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_')
            ;
        else
            break;

        if (!pop_char(&p_, &c))
            assert(false);
    }

    t->end = p_.offset;
    if (t->begin == t->end)
        return false;

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool match_human_identifier(struct Parser *p, struct Token *t)
{
    assert(p && t);
    struct Parser p_ = *p, q = *p;
    unsigned char c;

    t->source = p->source;
    t->location = p->location;
    t->begin = p->offset;
    t->end = p->offset;

    for (;;)
    {
        if (!peek_char(&p_, &c))
            break;

        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_' || c == '-' || c == ' ')
            ;
        else if (p_.offset > t->begin && ('0' <= c && c <= '9'))
            ;
        else
            break;

        if (!pop_char(&p_, &c))
            assert(false);

        if (c != ' ')
            q = p_;
    }

    t->end = q.offset;
    if (t->begin == t->end)
        return false;

    *p = q;
    return true;
}

// Like 'match_human_identifier' but parses ':', for 'Type: Null', among
// other exceptions.
__attribute__((warn_unused_result))
static bool match_species_identifier(struct Parser *p, struct Token *t)
{
    assert(p && t);
    struct Parser p_ = *p, q = *p;
    unsigned char c;

    t->source = p->source;
    t->location = p->location;
    t->begin = p->offset;
    t->end = p->offset;

    for (;;)
    {
        if (!peek_char(&p_, &c))
            break;

        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_' || c == '-' || c == ' ' || c == ':' || c == '.' || c == '\'' || c >= 0x80)
            ;
        else
            break;

        if (!pop_char(&p_, &c))
            assert(false);

        if (c != ' ')
            q = p_;
    }

    t->end = q.offset;
    if (t->begin == t->end)
        return false;

    *p = q;
    return true;
}

// Like 'match_human_identifier' but parses '10,000,000 Volt Thunderbolt'
// among other exceptions.
__attribute__((warn_unused_result))
static bool match_move_identifier(struct Parser *p, struct Token *t)
{
    assert(p && t);
    struct Parser p_ = *p, q = *p;
    unsigned char c;

    t->source = p->source;
    t->location = p->location;
    t->begin = p->offset;
    t->end = p->offset;

    for (;;)
    {
        if (!peek_char(&p_, &c))
            break;

        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_' || c == '-' || c == ' ' || c == ',')
            ;
        else
            break;

        if (!pop_char(&p_, &c))
            assert(false);

        if (c != ' ')
            q = p_;
    }

    t->end = q.offset;
    if (t->begin == t->end)
        return false;

    *p = q;
    return true;
}

__attribute__((warn_unused_result))
static bool parse_section(struct Parser *p, struct Token *section)
{
    assert(p && section);
    struct Parser p_ = *p;

    if (!match_exact(&p_, "==="))
        return false;

    skip_whitespace(&p_);
    if (!match_identifier(&p_, section))
        return set_parse_error(p, p_.location, "expected identifier");

    skip_whitespace(&p_);
    if (!match_exact(&p_, "==="))
        return set_parse_error(p, p_.location, "expected '==='");

    skip_whitespace(&p_);
    if (!match_eol(&p_))
        return set_parse_error(p, p_.location, "unexpected character in section");

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool parse_pokemon_header(struct Parser *p, struct Token *nickname, struct Token *species, struct Token *gender, struct Token *item)
{
    assert(p && nickname && species && gender && item);
    struct Parser p_ = *p;
    struct Token first = {}, second = {}, third = {};

    if (!match_species_identifier(&p_, &first))
        return false;

    skip_whitespace(&p_);
    if (match_exact(&p_, "("))
    {
        if (!match_species_identifier(&p_, &second))
            return set_parse_error(p, p_.location, "expected species or gender");
        if (!match_exact(&p_, ")"))
            return set_parse_error(p, p_.location, "expected ')'");

        skip_whitespace(&p_);
        if (match_exact(&p_, "("))
        {
            if (!match_human_identifier(&p_, &third))
                return set_parse_error(p, p_.location, "expected gender");
            if (!match_exact(&p_, ")"))
                return set_parse_error(p, p_.location, "expected ')'");

            *nickname = first;
            *species = second;
            *gender = third;
        }
        else
        {
            if (second.begin + 1 == second.end) // Single letter.
            {
                *nickname = (struct Token) {};
                *species = first;
                *gender = second;
            }
            else
            {
                *nickname = first;
                *species = second;
                *gender = (struct Token) {};
            }
        }
    }
    else
    {
        *nickname = (struct Token) {};
        *species = first;
        *gender = (struct Token) {};
    }

    skip_whitespace(&p_);
    if (match_exact(&p_, "@"))
    {
        skip_whitespace(&p_);
        if (!match_human_identifier(&p_, item))
            return set_parse_error(p, p_.location, "expected item");
    }
    else
    {
        *item = (struct Token) {};
    }

    skip_whitespace(&p_);
    if (!match_eol(&p_))
        return set_parse_error(p, p_.location, "unexpected character in Pokemon header");

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool parse_pokemon_nature(struct Parser *p, struct Token *nature)
{
    assert(p && nature);
    struct Parser p_ = *p;

    if (!match_identifier(&p_, nature))
        return false;

    skip_whitespace(&p_);
    if (!match_exact(&p_, "Nature"))
        return false;

    skip_whitespace(&p_);
    if (!match_eol(&p_))
        return set_parse_error(p, p_.location, "unexpected character in nature");

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool parse_attribute(struct Parser *p, struct Token *key, struct Token *value)
{
    assert(p && key && value);

    if (parse_pokemon_nature(p, value))
    {
        static const struct Source nature_source = { .path=NULL, .buffer=(unsigned char *)"Nature", .buffer_n=6 };
        key->source = &nature_source;
        key->location = p->location;
        key->begin = 0;
        key->end = nature_source.buffer_n;
        return true;
    }

    struct Parser p_ = *p;

    if (!match_human_identifier(&p_, key))
        return false;

    skip_whitespace(&p_);
    if (match_exact(&p_, ":"))
    {
        skip_whitespace(&p_);
        match_until_eol(&p_, value);
        if (!match_eol(&p_))
            return set_parse_error(p, p_.location, "unexpected character in attribute");
    }
    else
    {
        return set_parse_error(p, p_.location, "expected ':' or 'Nature'");
    }

    *p = p_;
    return true;
}

__attribute__((warn_unused_result))
static bool parse_pokemon_move(struct Parser *p, struct Token *move)
{
    assert(p && move);
    struct Parser p_ = *p;

    if (!match_exact(&p_, "-"))
        return false;
    skip_whitespace(&p_);
    if (!match_move_identifier(&p_, move))
        return set_parse_error(p, p_.location, "expected move");
    skip_whitespace(&p_);
    if (!match_eol(&p_))
        return set_parse_error(p, p_.location, "unexpected character in move");

    *p = p_;
    return true;
}

static struct String token_string(const struct Token *t)
{
    if (t->source)
    {
        return (struct String) {
            .string = &t->source->buffer[t->begin],
            .string_n = t->end - t->begin,
        };
    }
    else
    {
        return (struct String) {
            .string = NULL,
            .string_n = 0,
        };
    }
}

static bool token_gender(struct Parser *p, const struct Token *t, enum Gender *g)
{
    if (is_empty_token(t))
    {
        *g = GENDER_ANY;
        return true;
    }
    else if (is_literal_token(t, "M") || is_literal_token(t, "Male"))
    {
        *g = GENDER_MALE;
        return true;
    }
    else if (is_literal_token(t, "F") || is_literal_token(t, "Female"))
    {
        *g = GENDER_FEMALE;
        return true;
    }
    else
    {
        return set_parse_error(p, t->location, "invalid gender");
    }
}

static bool token_stats(struct Parser *p, const struct Token *t, struct Stats *stats, bool require_all)
{
    struct Source source = {
        .path = p->source->path,
        .buffer = p->source->buffer,
        .buffer_n = t->end,
    };
    struct Parser p_ = {
        .source = &source,
        .location = t->location,
        .offset = t->begin,
    };
    bool has_hp = false, has_atk = false, has_def = false, has_spa = false, has_spd = false, has_spe = false;
    for (;;)
    {
        int value;
        skip_whitespace(&p_);
        if (!match_int(&p_, &value))
            return set_parse_error(p, p_.location, "expected integer");

        struct Token stat;
        skip_whitespace(&p_);
        struct SourceLocation stat_location = p_.location;
        if (!match_identifier(&p_, &stat))
            return set_parse_error(p, p_.location, "expected 'HP', 'Atk', 'Def', 'SpA', 'SpD', or 'Spe'");
        if (is_literal_token(&stat, "HP"))
        {
            stats->hp = value;
            has_hp = true;
        }
        else if (is_literal_token(&stat, "Atk"))
        {
            stats->attack = value;
            has_atk = true;
        }
        else if (is_literal_token(&stat, "Def"))
        {
            stats->defense = value;
            has_def = true;
        }
        else if (is_literal_token(&stat, "SpA"))
        {
            stats->special_attack = value;
            has_spa = true;
        }
        else if (is_literal_token(&stat, "SpD"))
        {
            stats->special_defense = value;
            has_spd = true;
        }
        else if (is_literal_token(&stat, "Spe"))
        {
            stats->speed = value;
            has_spe = true;
        }
        else
        {
            return set_parse_error(p, stat_location, "expected 'HP', 'Atk', 'Def', 'SpA', 'SpD', or 'Spe'");
        }

        skip_whitespace(&p_);
        if (match_eof(&p_))
            break;
        else if (!match_exact(&p_, "/"))
            return set_parse_error(p, p_.location, "expected '/' or newline");
    }
    if (require_all && !(has_hp && has_atk && has_def && has_spa && has_spd && has_spe))
        return set_parse_error(p, p_.location, "expected all of 'HP', 'Atk', 'Def', 'SpA', 'SpD', and 'Spe'");
    return true;
}

// '/'-separated strings.
static bool token_human_identifiers(struct Parser *p, const struct Token *t, struct String *ids, int *ids_n, int max_ids_n)
{
    struct Source source = {
        .path = p->source->path,
        .buffer = p->source->buffer,
        .buffer_n = t->end,
    };
    struct Parser p_ = {
        .source = &source,
        .location = t->location,
        .offset = t->begin,
    };
    int n = 0;
    while (*ids_n < max_ids_n)
    {
        skip_whitespace(&p_);
        struct Token id;
        if (!match_human_identifier(&p_, &id))
            return set_parse_error(p, p_.location, "expected identifier");
        ids[n++] = token_string(&id);
        skip_whitespace(&p_);
        if (match_eof(&p_))
            break;
        else if (!match_exact(&p_, "/"))
            return set_parse_error(p, p_.location, "expected '/' or newline");
    }
    *ids_n = n;
    return true;
}

static bool token_int(struct Parser *p, const struct Token *t, int *i)
{
    char *end;
    long l = strtol((const char *)&t->source->buffer[t->begin], &end, 10);
    if ((unsigned char *)end != &t->source->buffer[t->end])
        return set_parse_error(p, t->location, "invalid integer");
    if (!(INT_MIN <= l && l <= INT_MAX))
        return set_parse_error(p, t->location, "integer too large");
    *i = l;
    return true;
}

static bool token_bool(struct Parser *p, const struct Token *t, bool *b)
{
    if (is_literal_token(t, "Yes"))
    {
        *b = true;
        return true;
    }
    else if (is_literal_token(t, "No"))
    {
        *b = false;
        return true;
    }
    else
    {
        return set_parse_error(p, t->location, "invalid boolean");
    }
}

static bool parse_pragma(struct Parser *p, struct Parsed *parsed)
{
    assert(p && parsed);
    struct Parser p_ = *p;

    if (!match_exact(&p_, "#pragma"))
        return false;

    // TODO: Require _a_ space between #pragma and trainerproc.
    struct Token id;
    skip_whitespace(&p_);
    if (!match_identifier(&p_, &id))
        return set_show_parse_error(p, p_.location, "expected 'trainerproc'");
    if (!is_literal_token(&id, "trainerproc"))
        return set_show_parse_error(p, id.location, "expected 'trainerproc'");

    skip_whitespace(&p_);
    if (!match_identifier(&p_, &id))
    {
        return set_show_parse_error(p, p_.location, "expected identifier");
    }
    else if (is_literal_token(&id, "ivs"))
    {
        if (parsed->default_ivs_line)
            return set_show_parse_error(p, p_.location, "duplicate #pragma trainerproc ivs");
        parsed->default_ivs_line = p_.location.line;
        skip_whitespace(&p_);
        struct Token t;
        match_until_eol(&p_, &t);
        if (is_literal_token(&t, "explicit"))
            parsed->default_ivs_off = true;
        else if (!token_stats(p, &t, &parsed->default_ivs, true))
            return show_parse_error(p);
    }
    else if (is_literal_token(&id, "level"))
    {
        if (parsed->default_level_line)
            return set_show_parse_error(p, p_.location, "duplicate #pragma trainerproc level");
        parsed->default_level_line = p_.location.line;
        skip_whitespace(&p_);
        struct Token t;
        match_until_eol(&p_, &t);
        if (is_literal_token(&t, "explicit"))
            parsed->default_level_off = true;
        else if (!token_int(p, &t, &parsed->default_level))
            return show_parse_error(p);
    }
    else
    {
        return set_show_parse_error(p, id.location, "unknown pragma");
    }

    if (!match_eol(&p_))
        return set_show_parse_error(p, p_.location, "expected newline");

    *p = p_;
    return true;
}

// Species that are selected based on the explicit gender.
// e.g. 'Nidoran (M)' becomes 'Nidoran-M'.
static const struct {
    const char *species;
    const char *male_species;
    const char *female_species;
} gendered_species[] = {
    { "Basculegion", "Basculegion-M", "Basculegion-F" },
    { "Indeedee", "Indeedee-M", "Indeedee-F" },
    { "Oinkologne", "Oinkologne-M", "Oinkologne-F" },
    { "Meowstic", "Meowstic-M", "Meowstic-F" },
    { "Nidoran", "Nidoran-M", "Nidoran-F" },
    { NULL, NULL, NULL }
};

// Items that are selected based on the explicit form.
// e.g. 'Arceus-Fire' becomes 'Arceus @ Flame Plate'.
static const struct {
    const char *form;
    const char *species;
    const char *item;
} itemed_species[] = {
    { "Arceus-Bug", "Arceus", "Insect Plate" },
    { "Arceus-Dark", "Arceus", "Dread Plate" },
    { "Arceus-Dragon", "Arceus", "Draco Plate" },
    { "Arceus-Electric", "Arceus", "Zap Plate" },
    { "Arceus-Fairy", "Arceus", "Pixie Plate" },
    { "Arceus-Fighting", "Arceus", "Fist Plate" },
    { "Arceus-Fire", "Arceus", "Flame Plate" },
    { "Arceus-Flying", "Arceus", "Sky Plate" },
    { "Arceus-Ghost", "Arceus", "Spooky Plate" },
    { "Arceus-Grass", "Arceus", "Meadow Plate" },
    { "Arceus-Ground", "Arceus", "Earth Plate" },
    { "Arceus-Ice", "Arceus", "Icicle Plate" },
    { "Arceus-Poison", "Arceus", "Toxic Plate" },
    { "Arceus-Psychic", "Arceus", "Mind Plate" },
    { "Arceus-Rock", "Arceus", "Stone Plate" },
    { "Arceus-Steel", "Arceus", "Iron Plate" },
    { "Arceus-Water", "Arceus", "Splash Plate" },
    { "Genesect-Burn", "Genesect", "Burn Drive" },
    { "Genesect-Chill", "Genesect", "Chill Drive" },
    { "Genesect-Douse", "Genesect", "Douse Drive" },
    { "Genesect-Shock", "Genesect", "Shock Drive" },
    { "Silvally-Bug", "Silvally", "Bug Memory" },
    { "Silvally-Dark", "Silvally", "Dark Memory" },
    { "Silvally-Dragon", "Silvally", "Dragon Memory" },
    { "Silvally-Electric", "Silvally", "Electric Memory" },
    { "Silvally-Fairy", "Silvally", "Fairy Memory" },
    { "Silvally-Fighting", "Silvally", "Fighting Memory" },
    { "Silvally-Fire", "Silvally", "Fire Memory" },
    { "Silvally-Flying", "Silvally", "Flying Memory" },
    { "Silvally-Ghost", "Silvally", "Ghost Memory" },
    { "Silvally-Grass", "Silvally", "Grass Memory" },
    { "Silvally-Ground", "Silvally", "Ground Memory" },
    { "Silvally-Ice", "Silvally", "Ice Memory" },
    { "Silvally-Poison", "Silvally", "Poison Memory" },
    { "Silvally-Psychic", "Silvally", "Psychic Memory" },
    { "Silvally-Rock", "Silvally", "Rock Memory" },
    { "Silvally-Steel", "Silvally", "Steel Memory" },
    { "Silvally-Water", "Silvally", "Water Memory" },
    { NULL, NULL, NULL }
};

static bool parse_trainer(struct Parser *p, const struct Parsed *parsed, struct Trainer *trainer)
{
    bool any_error = false;
    *trainer = (struct Trainer) {};

    while (match_empty_line(p)) {}
    struct Token id;
    struct Token nickname, species, gender, item;
    if (!parse_section(p, &id))
    {
        if (!p->error)
            set_parse_error(p, p->location, "expected '==='");
        show_parse_error(p);
        return false;
    }
    trainer->id = token_string(&id);
    trainer->id_line = id.location.line;

    // Parse trainer attributes.
    struct Token key, value;
    while (parse_attribute(p, &key, &value))
    {
        if (is_literal_token(&key, "AI"))
        {
            if (trainer->ai_flags_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'AI'");
            trainer->ai_flags_line = value.location.line;
            if (!token_human_identifiers(p, &value, trainer->ai_flags, &trainer->ai_flags_n, MAX_TRAINER_AI_FLAGS))
                any_error = !show_parse_error(p);
        }
        else if (is_literal_token(&key, "Items"))
        {
            if (trainer->items_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Items'");
            trainer->items_line = value.location.line;
            if (!token_human_identifiers(p, &value, trainer->items, &trainer->items_n, MAX_TRAINER_ITEMS))
                any_error = !show_parse_error(p);
        }
        else if (is_literal_token(&key, "Class"))
        {
            if (trainer->class_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Class'");
            trainer->class_line = value.location.line;
            trainer->class = token_string(&value);
        }
        else if (is_literal_token(&key, "Music"))
        {
            if (trainer->encounter_music_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Music'");
            trainer->encounter_music_line = value.location.line;
            trainer->encounter_music = token_string(&value);
        }
        else if (is_literal_token(&key, "Gender"))
        {
            if (trainer->gender_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Gender'");
            trainer->gender_line = value.location.line;
            if (!token_gender(p, &value, &trainer->gender))
                any_error = !show_parse_error(p);
        }
        else if (is_literal_token(&key, "Pic"))
        {
            if (trainer->pic_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Pic'");
            trainer->pic_line = value.location.line;
            trainer->pic = token_string(&value);
        }
        else if (is_literal_token(&key, "Name"))
        {
            if (trainer->name_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Name'");
            trainer->name_line = value.location.line;
            trainer->name = token_string(&value);
        }
        else if (is_literal_token(&key, "Double Battle"))
        {
            if (trainer->double_battle_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Double Battle'");
            trainer->double_battle_line = value.location.line;
            if (!token_bool(p, &value, &trainer->double_battle))
                any_error = !show_parse_error(p);
        }
        else if (is_literal_token(&key, "Mugshot"))
        {
            if (trainer->mugshot_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Mugshot'");
            trainer->mugshot_line = value.location.line;
            trainer->mugshot = token_string(&value);
        }
        else if (is_literal_token(&key, "Starting Status"))
        {
            if (trainer->starting_status_line)
                any_error = !set_show_parse_error(p, key.location, "duplicate 'Starting Status'");
            trainer->starting_status_line = value.location.line;
            trainer->starting_status = token_string(&value);
        }
        else
        {
            any_error = !set_show_parse_error(p, key.location, "expected one of 'Name', 'Class', 'Pic', 'Gender', 'Music', 'Items', 'Double Battle', or 'AI'");
        }
    }
    if (!trainer->pic_line)
        any_error = !set_show_parse_error(p, p->location, "expected 'Pic' before Pokemon");
    if (!trainer->name_line)
        any_error = !set_show_parse_error(p, p->location, "expected 'Name' before Pokemon");
    if (!match_empty_line(p))
    {
        set_show_parse_error(p, p->location, "expected empty line");

        // Continue if the line is the start of a new Pokemon.
        struct Parser p_ = *p;
        if (!parse_pokemon_header(&p_, &nickname, &species, &gender, &item))
            return false;
    }

    for (int i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = &trainer->pokemon[i];

        // Parse first line.
        while (match_empty_line(p)) {}
        if (!parse_pokemon_header(p, &nickname, &species, &gender, &item))
        {
            if (i > 0 || ends_with(trainer->id, "_NONE"))
                break;
            if (!p->error)
                set_parse_error(p, p->location, "expected nickname or species");
            show_parse_error(p);

            // TODO: Continue if a Pokemon starts before the next section.
            // This is difficult to do, because 'Type: Null' is the name
            // of a species, and so 'X: Y' is being parsed as a Pokemon
            // header.
            return false;
        }
        trainer->pokemon_n++;

        pokemon->nickname = token_string(&nickname);
        pokemon->species = token_string(&species);
        if (!token_gender(p, &gender, &pokemon->gender))
            any_error = !show_parse_error(p);
        pokemon->item = token_string(&item);
        pokemon->header_line = species.location.line;

        for (int i = 0; gendered_species[i].species; i++)
        {
            if (is_literal_string(pokemon->species, gendered_species[i].species))
            {
                switch (pokemon->gender)
                {
                case GENDER_ANY:
                    break;
                case GENDER_MALE:
                    pokemon->species = literal_string(gendered_species[i].male_species);
                    break;
                case GENDER_FEMALE:
                    pokemon->species = literal_string(gendered_species[i].female_species);
                    break;
                }
                pokemon->gender = GENDER_ANY;
                break;
            }
        }

        for (int i = 0; itemed_species[i].species; i++)
        {
            if (is_literal_string(pokemon->species, itemed_species[i].form)
             && is_empty_string(pokemon->item))
            {
                pokemon->species = literal_string(itemed_species[i].species);
                pokemon->item = literal_string(itemed_species[i].item);
            }
        }

        // Parse Pokemon attributes.
        while (parse_attribute(p, &key, &value))
        {
            if (is_literal_token(&key, "EVs"))
            {
                if (pokemon->evs_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'EVs'");
                pokemon->evs_line = value.location.line;
                if (!token_stats(p, &value, &pokemon->evs, false))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "IVs"))
            {
                if (pokemon->ivs_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'IVs'");
                pokemon->ivs_line = value.location.line;
                pokemon->ivs = parsed->default_ivs;
                if (!token_stats(p, &value, &pokemon->ivs, parsed->default_ivs_off))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Ability"))
            {
                if (pokemon->ability_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Ability'");
                pokemon->ability_line = value.location.line;
                pokemon->ability = token_string(&value);
            }
            else if (is_literal_token(&key, "Level"))
            {
                if (pokemon->level_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Level'");
                pokemon->level_line = value.location.line;
                if (!token_int(p, &value, &pokemon->level))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Ball"))
            {
                if (pokemon->ball_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Ball'");
                pokemon->ball_line = value.location.line;
                pokemon->ball = token_string(&value);
            }
            else if (is_literal_token(&key, "Happiness"))
            {
                if (pokemon->friendship_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Happiness'");
                pokemon->friendship_line = value.location.line;
                if (!token_int(p, &value, &pokemon->friendship))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Nature"))
            {
                if (pokemon->nature_line)
                    any_error = !set_show_parse_error(p, value.location, "duplicate 'Nature'");
                pokemon->nature_line = value.location.line;
                pokemon->nature = token_string(&value);
            }
            else if (is_literal_token(&key, "Shiny"))
            {
                if (pokemon->shiny_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Shiny'");
                pokemon->shiny_line = value.location.line;
                if (!token_bool(p, &value, &pokemon->shiny))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Dynamax Level"))
            {
                if (pokemon->dynamax_level_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Dynamax Level'");
                pokemon->dynamax_level_line = value.location.line;
                if (!token_int(p, &value, &pokemon->dynamax_level))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Gigantamax"))
            {
                if (pokemon->gigantamax_factor_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Gigantamax'");
                pokemon->gigantamax_factor_line = value.location.line;
                if (!token_bool(p, &value, &pokemon->gigantamax_factor))
                    any_error = !show_parse_error(p);
            }
            else if (is_literal_token(&key, "Tera Type"))
            {
                if (pokemon->tera_type_line)
                    any_error = !set_show_parse_error(p, key.location, "duplicate 'Tera Type'");
                pokemon->tera_type_line = value.location.line;
                pokemon->tera_type = token_string(&value);
            }
            else
            {
                any_error = !set_show_parse_error(p, key.location, "expected one of 'EVs', 'IVs', 'Ability', 'Level', 'Ball', 'Happiness', 'Nature', 'Shiny', 'Dynamax Level', 'Gigantamax', or 'Tera Type'");
            }
        }

        if (!pokemon->level_line)
        {
            if (!parsed->default_level_off)
            {
                pokemon->level = parsed->default_level;
                pokemon->level_line = p->location.line;
            }
            else
            {
                any_error = !set_show_parse_error(p, p->location, "expected 'Level' before moves");
            }
        }
        if (!pokemon->ivs_line)
        {
            if (!parsed->default_ivs_off)
            {
                pokemon->ivs = parsed->default_ivs;
                pokemon->ivs_line = p->location.line;
            }
            else
            {
                any_error = !set_show_parse_error(p, p->location, "expected 'IVs' before moves");
            }
        }

        // Parse moves.
        for (int j = 0; j < MAX_MON_MOVES; j++)
        {
            struct Token move;
            if (!parse_pokemon_move(p, &move))
            {
                struct Parser p_ = *p;
                if (match_eof(&p_) || match_empty_line(&p_))
                    break;
            }
            else
            {
                if (pokemon->moves_n == 0)
                    pokemon->move1_line = move.location.line;
                pokemon->moves[pokemon->moves_n] = token_string(&move);
                pokemon->moves_n++;
            }
        }

        if (match_eof(p))
            break;
        if (!match_empty_line(p))
        {
            set_show_parse_error(p, p->location, "expected empty line");

            // Continue if the line is the start of a new Pokemon.
            struct Parser p_ = *p;
            if (!parse_pokemon_header(&p_, &nickname, &species, &gender, &item))
                return false;
        }
    }

    return !any_error;
}

static void parse(struct Parser *p, struct Parsed *parsed)
{
    parsed->source = p->source;
    int trainers_c = 256;
    parsed->trainers = malloc(sizeof(*parsed->trainers) * trainers_c);
    parsed->trainers_n = 0;
    assert(parsed->trainers);
    for (;;)
    {
        while (match_empty_line(p)) {}
        if (!parse_pragma(p, parsed))
            break;
    }
    for (;;)
    {
        if (parsed->trainers_n == trainers_c)
        {
            trainers_c *= 2;
            struct Trainer *trainers_ = realloc(parsed->trainers, sizeof(*parsed->trainers) * trainers_c);
            assert(trainers_);
            parsed->trainers = trainers_;
        }
        struct Trainer *trainer = &parsed->trainers[parsed->trainers_n];
        while (match_empty_line(p)) {}
        if (match_eof(p))
            break;
        if (!parse_trainer(p, parsed, trainer))
        {
            struct Token t;
            // Skip to the next trainer.
            for (;;)
            {
                struct Parser p_ = *p;
                if (match_eof(&p_) || parse_section(&p_, &t))
                    break;
                skip_line(p);
            }
        }
        else
        {
            parsed->trainers_n++;
        }
    }
}

static void fprint_string(FILE *f, struct String s)
{
    fprintf(f, "%.*s", s.string_n, s.string);
}

static void fprint_bool(FILE *f, bool b)
{
    fprintf(f, b ? "TRUE" : "FALSE");
}

static void fprint_stats(FILE *f, const char *macro, struct Stats stats)
{
    fprintf(f, "%s(%d, %d, %d, %d, %d, %d)", macro, stats.hp, stats.attack, stats.defense, stats.speed, stats.special_attack, stats.special_defense);
}

static bool is_constant(struct String s, const char *prefix)
{
    for (int i = 0;; i++)
    {
        if (i == s.string_n)
            return false;
        else if (prefix[i] == '\0')
            return s.string[i] == '_';
        else if (prefix[i] != s.string[i])
            return false;
    }
}

static void fprint_constant(FILE *f, const char *prefix, struct String s)
{
    if (!is_constant(s, prefix)) fprintf(f, "%s_", prefix);
    if (s.string_n > 0)
    {
        for (int i = 0; i < s.string_n; i++)
        {
            unsigned char c = s.string[i];
            if (('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
                fputc(c, f);
            else if ('a' <= c && c <= 'z')
                fputc(c - 'a' + 'A', f);
            else
                fputc('_', f);
        }
    }
    else
    {
        fprintf(f, "NONE");
    }
}

// This is a really stupid helper for 'fprint_species'.
static bool is_utf8_character(struct String s, int *i, const unsigned char *utf8)
{
    for (int j = *i;; j++, utf8++)
    {
        if (*utf8 == '\0')
        {
            *i = j - 1; // '- 1' because of the '++' in 'fprint_species'.
            return true;
        }
        else if (j == s.string_n || s.string[j] != *utf8)
        {
            return false;
        }
    }
}

static void fprint_species(FILE *f, const char *prefix, struct String s)
{
    if (!is_constant(s, prefix)) fprintf(f, "%s_", prefix);

    if (s.string_n == 0)
    {
        fprintf(f, "NONE");
    }
    else
    {
        bool underscore = false;
        static const unsigned char *male = (unsigned char *)u8"♂";
        static const unsigned char *female = (unsigned char *)u8"♀";
        static const unsigned char *e_diacritic = (unsigned char *)u8"é";
        for (int i = 0; i < s.string_n; i++)
        {
            unsigned char c = s.string[i];
            if (('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
            {
                if (underscore)
                    fputc('_', f);
                underscore = false;
                fputc(c, f);
            }
            else if ('a' <= c && c <= 'z')
            {
                if (underscore)
                    fputc('_', f);
                underscore = false;
                fputc(c - 'a' + 'A', f);
            }
            else if (c == '\'' || c == '%')
            {
                // Do nothing.
            }
            else if (is_utf8_character(s, &i, male))
            {
                underscore = false;
                fprintf(f, "_M");
            }
            else if (is_utf8_character(s, &i, female))
            {
                underscore = false;
                fprintf(f, "_F");
            }
            else if (is_utf8_character(s, &i, e_diacritic))
            {
                if (underscore)
                    fputc('_', f);
                underscore = false;
                fputc('E', f);
            }
            else
            {
                underscore = true;
            }
        }
    }
}

static void fprint_trainers(const char *output_path, FILE *f, struct Parsed *parsed)
{
    fprintf(f, "//\n");
    fprintf(f, "// DO NOT MODIFY THIS FILE! It is auto-generated from %s\n", parsed->source->path);
    fprintf(f, "//\n");
    fprintf(f, "// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE\n");
    fprintf(f, "// in include/config.h and remove this notice.\n");
    fprintf(f, "// Use sed -i '/^#line/d' '%s' to remove #line markers.\n", output_path);
    fprintf(f, "//\n");
    fprintf(f, "\n");

    fprintf(f, "#line 1 \"%s\"\n", parsed->source->path);
    fprintf(f, "\n");

    for (int i = 0; i < parsed->trainers_n; i++)
    {
        struct Trainer *trainer = &parsed->trainers[i];
        fprintf(f, "#line %d\n", trainer->id_line);
        fprintf(f, "    [");
        fprint_string(f, trainer->id);
        fprintf(f, "] =\n");
        fprintf(f, "    {\n");

        if (!is_empty_string(trainer->name))
        {
            fprintf(f, "#line %d\n", trainer->name_line);
            fprintf(f, "        .trainerName = _(\"");
            fprint_string(f, trainer->name);
            fprintf(f, "\"),\n");
        }

        if (!is_empty_string(trainer->class))
        {
            fprintf(f, "#line %d\n", trainer->class_line);
            fprintf(f, "        .trainerClass = ");
            fprint_constant(f, "TRAINER_CLASS", trainer->class);
            fprintf(f, ",\n");
        }

        if (!is_empty_string(trainer->pic))
        {
            fprintf(f, "#line %d\n", trainer->pic_line);
            fprintf(f, "        .trainerPic = ");
            if (starts_with(trainer->id, "PARTNER_"))
                fprint_constant(f, "TRAINER_BACK_PIC", trainer->pic);
            else
                fprint_constant(f, "TRAINER_PIC", trainer->pic);
            fprintf(f, ",\n");
        }

        fprintf(f, "        .encounterMusic_gender = \n");
        if (trainer->gender == GENDER_FEMALE)
        {
            fprintf(f, "#line %d\n", trainer->gender_line);
            fprintf(f, "F_TRAINER_FEMALE | \n");
        }
        if (!is_empty_string(trainer->encounter_music))
        {
            fprintf(f, "#line %d\n", trainer->encounter_music_line);
            fprintf(f, "            ");
            fprint_constant(f, "TRAINER_ENCOUNTER_MUSIC", trainer->encounter_music);
        }
        else
        {
            fprintf(f, "0");
        }
        fprintf(f, ",\n");

        if (trainer->items_n > 0)
        {
            fprintf(f, "#line %d\n", trainer->items_line);
            fprintf(f, "        .items = { ");
            for (int i = 0; i < trainer->items_n; i++)
            {
                if (i > 0)
                    fprintf(f, ", ");
                fprint_constant(f, "ITEM", trainer->items[i]);
            }
            fprintf(f, " },\n");
        }

        if (trainer->double_battle_line)
        {
            fprintf(f, "#line %d\n", trainer->double_battle_line);
            fprintf(f, "        .doubleBattle = ");
            fprint_bool(f, trainer->double_battle);
            fprintf(f, ",\n");
        }

        if (trainer->ai_flags_n > 0)
        {
            fprintf(f, "#line %d\n", trainer->ai_flags_line);
            fprintf(f, "        .aiFlags = ");
            for (int i = 0; i < trainer->ai_flags_n; i++)
            {
                if (i > 0)
                    fprintf(f, " | ");
                fprint_constant(f, "AI_FLAG", trainer->ai_flags[i]);
            }
            fprintf(f, ",\n");
        }

        if (!is_empty_string(trainer->mugshot))
        {
            fprintf(f, "#line %d\n", trainer->mugshot_line);
            fprintf(f, "        .mugshotEnabled = TRUE,\n");
            fprintf(f, "        .mugshotColor = ");
            fprint_constant(f, "MUGSHOT_COLOR", trainer->mugshot);
            fprintf(f, ",\n");
        }

        if (!is_empty_string(trainer->starting_status))
        {
            fprintf(f, "#line %d\n", trainer->starting_status_line);
            fprintf(f, "        .startingStatus = ");
            fprint_constant(f, "STARTING_STATUS", trainer->starting_status);
            fprintf(f, ",\n");
        }

        fprintf(f, "        .partySize = %d,\n", trainer->pokemon_n);
        fprintf(f, "        .party = (const struct TrainerMon[])\n");
        fprintf(f, "        {\n");
        for (int j = 0; j < trainer->pokemon_n; j++)
        {
            struct Pokemon *pokemon = &trainer->pokemon[j];
            fprintf(f, "            {\n");

            if (!is_empty_string(pokemon->nickname))
            {
                fprintf(f, "#line %d\n", pokemon->header_line);
                fprintf(f, "            .nickname = COMPOUND_STRING(\"");
                fprint_string(f, pokemon->nickname);
                fprintf(f, "\"),\n");
            }

            fprintf(f, "#line %d\n", pokemon->header_line);
            fprintf(f, "            .species = ");
            fprint_species(f, "SPECIES", pokemon->species);
            fprintf(f, ",\n");

            switch (pokemon->gender)
            {
            case GENDER_ANY:
                fprintf(f, "            .gender = TRAINER_MON_RANDOM_GENDER,\n");
                break;
            case GENDER_MALE:
                fprintf(f, "#line %d\n", pokemon->header_line);
                fprintf(f, "            .gender = TRAINER_MON_MALE,\n");
                break;
            case GENDER_FEMALE:
                fprintf(f, "#line %d\n", pokemon->header_line);
                fprintf(f, "            .gender = TRAINER_MON_FEMALE,\n");
                break;
            }

            if (!is_empty_string(pokemon->item))
            {
                fprintf(f, "#line %d\n", pokemon->header_line);
                fprintf(f, "            .heldItem = ");
                fprint_constant(f, "ITEM", pokemon->item);
                fprintf(f, ",\n");
            }

            if (pokemon->evs_line)
            {
                fprintf(f, "#line %d\n", pokemon->evs_line);
                fprintf(f, "            .ev = ");
                fprint_stats(f, "TRAINER_PARTY_EVS", pokemon->evs);
                fprintf(f, ",\n");
            }

            if (pokemon->ivs_line)
            {
                fprintf(f, "#line %d\n", pokemon->ivs_line);
                fprintf(f, "            .iv = ");
                fprint_stats(f, "TRAINER_PARTY_IVS", pokemon->ivs);
                fprintf(f, ",\n");
            }

            if (pokemon->ability_line)
            {
                fprintf(f, "#line %d\n", pokemon->ability_line);
                fprintf(f, "            .ability = ");
                fprint_constant(f, "ABILITY", pokemon->ability);
                fprintf(f, ",\n");
            }

            if (pokemon->level_line)
            {
                fprintf(f, "#line %d\n", pokemon->level_line);
                fprintf(f, "            .lvl = %d,\n", pokemon->level);
            }

            if (pokemon->ball_line)
            {
                fprintf(f, "#line %d\n", pokemon->ball_line);
                fprintf(f, "            .ball = ");
                fprint_constant(f, "ITEM", pokemon->ball);
                fprintf(f, ",\n");
            }

            if (pokemon->friendship_line)
            {
                fprintf(f, "#line %d\n", pokemon->friendship_line);
                fprintf(f, "            .friendship = %d,\n", pokemon->friendship);
            }

            if (pokemon->nature_line)
            {
                fprintf(f, "#line %d\n", pokemon->nature_line);
                fprintf(f, "            .nature = ");
                fprint_constant(f, "NATURE", pokemon->nature);
                fprintf(f, ",\n");
            }
            else
            {
                fprintf(f, "            .nature = NATURE_HARDY,\n");
            }

            if (pokemon->shiny_line)
            {
                fprintf(f, "#line %d\n", pokemon->shiny_line);
                fprintf(f, "            .isShiny = ");
                fprint_bool(f, pokemon->shiny);
                fprintf(f, ",\n");
            }

            if (pokemon->dynamax_level_line)
            {
                fprintf(f, "#line %d\n", pokemon->dynamax_level_line);
                fprintf(f, "            .dynamaxLevel = %d,\n", pokemon->dynamax_level);
            }
            else
            {
                fprintf(f, "            .dynamaxLevel = MAX_DYNAMAX_LEVEL,\n");
            }

            if (pokemon->gigantamax_factor_line)
            {
                fprintf(f, "#line %d\n", pokemon->gigantamax_factor_line);
                fprintf(f, "            .gigantamaxFactor = ");
                fprint_bool(f, pokemon->gigantamax_factor);
                fprintf(f, ",\n");
            }

            if (pokemon->dynamax_level_line || pokemon->gigantamax_factor_line)
            {
                fprintf(f, "            .shouldDynamax = TRUE,\n");
            }

            if (pokemon->tera_type_line)
            {
                fprintf(f, "#line %d\n", pokemon->tera_type_line);
                fprintf(f, "            .teraType = ");
                fprint_constant(f, "TYPE", pokemon->tera_type);
                fprintf(f, ",\n");
                fprintf(f, "            .shouldTerastal = TRUE,\n");
            }

            if (pokemon->moves_n > 0)
            {
                fprintf(f, "            .moves = {\n");
                fprintf(f, "#line %d\n", pokemon->move1_line);
                for (int k = 0; k < pokemon->moves_n; k++)
                {
                    fprintf(f, "                ");
                    fprint_constant(f, "MOVE", pokemon->moves[k]);
                    fprintf(f, ",\n");
                }
                fprintf(f, "            },\n");
            }

            fprintf(f, "            },\n");
        }
        fprintf(f, "        },\n");
        fprintf(f, "    },\n");
    }
}

static void usage(FILE *file, char *argv0)
{
    fprintf(file, "Usage: %s -o <output> <source>\n", argv0);
}

int main(int argc, char *argv[])
{
    int status = 1;
    FILE *source_file = NULL;
    FILE *output_file = NULL;
    unsigned char *source_buffer = NULL;
    struct Parsed parsed = {
        .default_ivs = { 31, 31, 31, 31, 31, 31 },
        .default_level = 100,
    };

    const char *source_path = NULL;
    const char *output_path = NULL;
    const char *real_source_path = NULL;

    int opt;
    while ((opt = getopt(argc, argv, "i:o:")) != -1)
    {
        switch (opt)
        {
        case 'i':
            real_source_path = optarg;
            break;
        case 'o':
            output_path = optarg;
            break;
        default:
            fprintf(stderr, "unknown option '%c'\n", opt);
            usage(stderr, argv[0]);
            goto exit;
        }
    }

    if (!output_path)
    {
        usage(stderr, argv[0]);
        goto exit;
    }

    if (optind != argc - 1)
    {
        usage(stderr, argv[0]);
        goto exit;
    }
    source_path = argv[optind++];

    int source_buffer_n;
    if (strcmp(source_path, "-") == 0)
    {
        source_file = stdin;
        source_path = "<stdin>";

        int source_buffer_c = 4096;
        source_buffer_n = 0;
        for (;;)
        {
            if (!(source_buffer = realloc(source_buffer, source_buffer_c)))
            {
                fprintf(stderr, "could not allocate %d bytes\n", source_buffer_c);
                goto exit;
            }

            source_buffer_n += fread(&source_buffer[source_buffer_n], 1, source_buffer_c - source_buffer_n, source_file);
            if (source_buffer_n < source_buffer_c)
                break;

            source_buffer_c += source_buffer_n / 2; // 1.5x growth rate.
        }
    }
    else
    {
        source_file = fopen(source_path, "r");
        if (source_file == NULL)
        {
            fprintf(stderr, "could not open '%s' for reading\n", source_path);
            goto exit;
        }

        fseek(source_file, 0, SEEK_END);
        long source_buffer_n_ = ftell(source_file);
        if (source_buffer_n_ > INT_MAX)
        {
            fprintf(stderr, "could not read '%s': too big\n", source_path);
            goto exit;
        }

        source_buffer_n = source_buffer_n_;

        if (!(source_buffer = malloc(source_buffer_n)))
        {
            fprintf(stderr, "could not allocate %d bytes\n", source_buffer_n);
            goto exit;
        }
        rewind(source_file);
        if (fread(source_buffer, 1, source_buffer_n, source_file) < source_buffer_n)
        {
            fprintf(stderr, "could not read '%s'\n", source_path);
            goto exit;
        }
    }

    struct Source source = {
        .path = real_source_path ? real_source_path : source_path,
        .buffer = source_buffer,
        .buffer_n = source_buffer_n,
    };
    struct Parser parser = {
        .source = &source,
        .location = { .line = 1, .column = 1 },
        .offset = 0,
    };
    parse(&parser, &parsed);
    if (parser.fatal_error)
    {
        goto exit;
    }

    if (strcmp(output_path, "-") == 0)
    {
        source_file = stdout;
        output_path = "<stdout>";
    }
    else
    {
        output_file = fopen(output_path, "w");
        if (output_file == NULL)
        {
            fprintf(stderr, "could not open '%s' for writing\n", output_path);
            goto exit;
        }
    }
    fprint_trainers(output_path, output_file, &parsed);

    status = 0;

exit:
    if (output_file) fclose(output_file);
    if (parsed.trainers) free(parsed.trainers);
    if (source_buffer) free(source_buffer);
    if (source_file) fclose(source_file);
    return status;
}
