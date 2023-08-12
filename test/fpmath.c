#include "global.h"
#include "test/test.h"

TEST("uq4_12_add adds 4.12 numbers") {
    EXPECT_EQ(uq4_12_add(UQ_4_12(3.5), UQ_4_12(2.5)), UQ_4_12(6.0));
}

TEST("uq4_12_subtract subtracts 4.12 numbers") {
    EXPECT_EQ(uq4_12_subtract(UQ_4_12(3.5), UQ_4_12(2.0)), UQ_4_12(1.5));
}

TEST("uq4_12_multiply multiplies 4.12 numbers") {
    EXPECT_EQ(uq4_12_multiply(UQ_4_12(3.5), UQ_4_12(2.0)), UQ_4_12(7.0));
}

TEST("uq4_12_divide divides 4.12 numbers") {
    EXPECT_EQ(uq4_12_divide(UQ_4_12(5.0), UQ_4_12(2.0)), UQ_4_12(2.5));
}
