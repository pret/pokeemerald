#ifndef GUARD_FIELD_POISON_H
#define GUARD_FIELD_POISON_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

enum {
    FLDPSN_NONE,
    FLDPSN_PSN,
    FLDPSN_FNT
};

void sub_80F972C(void);
int DoPoisonFieldEffect(void);

#endif //GUARD_FIELD_POISON_H
