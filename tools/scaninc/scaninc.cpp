// Copyright (c) 2015 YamaArashi

#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
#include <string>

#ifdef _MSC_VER

#define FATAL_INPUT_ERROR(format, ...)                                        \
do {                                                                          \
    fprintf(stderr, "%s:%d " format, m_path.c_str(), m_lineNum, __VA_ARGS__); \
    exit(1);                                                                  \
} while (0)

#define FATAL_ERROR(format, ...)          \
do {                                      \
    fprintf(stderr, format, __VA_ARGS__); \
    exit(1);                              \
} while (0)

#else

#define FATAL_INPUT_ERROR(format, ...)                                          \
do {                                                                            \
    fprintf(stderr, "%s:%d " format, m_path.c_str(), m_lineNum, ##__VA_ARGS__); \
    exit(1);                                                                    \
} while (0)

#define FATAL_ERROR(format, ...)            \
do {                                        \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (0)

#endif // _MSC_VER

#define SCANINC_MAX_PATH 255

enum class IncDirectiveType {
	None,
	Include,
	Incbin
};

class AsmFile
{
public:
	AsmFile(std::string path);
	~AsmFile();
	IncDirectiveType ReadUntilIncDirective(std::string &path);

private:
	char *m_buffer;
	int m_pos;
	int m_size;
	int m_lineNum;
	std::string m_path;

	int GetChar()
	{
		if (m_pos >= m_size)
			return -1;

		int c = m_buffer[m_pos++];

		if (c == '\r') {
			if (m_pos < m_size && m_buffer[m_pos++] == '\n') {
				m_lineNum++;
				return '\n';
			} else {
				FATAL_INPUT_ERROR("CR line endings are not supported\n");
			}
		}

		if (c == '\n')
			m_lineNum++;

		return c;
	}

	// No newline translation because it's not needed for any use of this function.
	int PeekChar()
	{
		if (m_pos >= m_size)
			return -1;

		return m_buffer[m_pos];
	}

	void SkipTabsAndSpaces()
	{
		while (m_pos < m_size && (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' '))
			m_pos++;
	}

	bool MatchIncDirective(std::string directiveName, std::string &path)
	{
		int length = directiveName.length();
		int i;

		for (i = 0; i < length && m_pos + i < m_size; i++)
			if (directiveName[i] != m_buffer[m_pos + i])
				return false;

		if (i < length)
			return false;

		m_pos += length;

		SkipTabsAndSpaces();

		if (GetChar() != '"')
			FATAL_INPUT_ERROR("no path after \".%s\" directive\n", directiveName.c_str());

		path = ReadPath();

		return true;
	}
	
	std::string ReadPath();
	void SkipEndOfLineComment();
	void SkipMultiLineComment();
	void SkipString();
};

AsmFile::AsmFile(std::string path)
{
	m_path = path;

	FILE *fp = fopen(path.c_str(), "rb");

	if (fp == NULL)
		FATAL_ERROR("Failed to open \"%s\" for reading.\n", path.c_str());

	fseek(fp, 0, SEEK_END);

	m_size = ftell(fp);

	m_buffer = new char[m_size];

	rewind(fp);

	if (fread(m_buffer, m_size, 1, fp) != 1)
		FATAL_ERROR("Failed to read \"%s\".\n", path.c_str());

	fclose(fp);

	m_pos = 0;
	m_lineNum = 1;
}

AsmFile::~AsmFile()
{
	delete[] m_buffer;
}

IncDirectiveType AsmFile::ReadUntilIncDirective(std::string &path)
{
	// At the beginning of each loop iteration, the current file position
	// should be at the start of a line or at the end of the file.
	for (;;) {
		SkipTabsAndSpaces();

		IncDirectiveType incDirectiveType = IncDirectiveType::None;

		if (PeekChar() == '.') {
			m_pos++;

			if (MatchIncDirective("incbin", path))
				incDirectiveType = IncDirectiveType::Incbin;
			else if (MatchIncDirective("include", path))
				incDirectiveType = IncDirectiveType::Include;
		}

		for (;;) {
			int c = GetChar();

			if (c == -1)
				return incDirectiveType;

			if (c == ';') {
				SkipEndOfLineComment();
				break;
			} else if (c == '/' && PeekChar() == '*') {
				m_pos++;
				SkipMultiLineComment();
			} else if (c == '"') {
				SkipString();
			} else if (c == '\n') {
				break;
			}
		}

		if (incDirectiveType != IncDirectiveType::None)
			return incDirectiveType;
	}
}

std::string AsmFile::ReadPath()
{
	int length = 0;
	int startPos = m_pos;

	for (;;) {
		int c = GetChar();

		if (c == '"')
			break;

		if (c == -1)
			FATAL_INPUT_ERROR("unexpected EOF in include string\n");

		if (c == 0)
			FATAL_INPUT_ERROR("unexpected NUL character in include string\n");

		if (c == '\n')
			FATAL_INPUT_ERROR("unexpected end of line character in include string\n");

		if (c == '\\') {
			c = GetChar();

			if (c != '"')
				FATAL_INPUT_ERROR("unknown escape \"\\%c\" in include string\n", c);
		}

		length++;

		if (length > SCANINC_MAX_PATH)
			FATAL_INPUT_ERROR("path is too long");
	}

	return std::string(m_buffer, startPos, length);
}

void AsmFile::SkipEndOfLineComment()
{
	int c;

	do {
		c = GetChar();
	} while (c != -1 && c != '\n');
}

void AsmFile::SkipMultiLineComment()
{
	for (;;) {
		int c = GetChar();

		if (c == '*') {
			if (PeekChar() == '/') {
				m_pos++;
				return;
			}
		} else if (c == -1) {
			return;
		}
	}
}

void AsmFile::SkipString()
{
	for (;;) {
		int c = GetChar();

		if (c == '"')
			break;

		if (c == -1)
			FATAL_INPUT_ERROR("unexpected EOF in string\n");

		if (c == '\\') {
			c = GetChar();
		}
	}
}

bool CanOpenFile(std::string path)
{
	FILE *fp = fopen(path.c_str(), "rb");

	if (fp == NULL)
		return false;

	fclose(fp);
	return true;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		FATAL_ERROR("Usage: scaninc ASM_FILE_PATH\n");

	std::stack<std::string> filesToProcess;
	std::set<std::string> dependencies;

	filesToProcess.push(std::string(argv[1]));

	while (!filesToProcess.empty()) {
		AsmFile file(filesToProcess.top());

		filesToProcess.pop();

		IncDirectiveType incDirectiveType;
		std::string path;

		while ((incDirectiveType = file.ReadUntilIncDirective(path)) != IncDirectiveType::None) {
			bool inserted = dependencies.insert(path).second;
			if (inserted
			 && incDirectiveType == IncDirectiveType::Include
			 && CanOpenFile(path))
				filesToProcess.push(path);
		}
	}

	for (const std::string &path : dependencies) {
		printf("%s\n", path.c_str());
	}
}
