.section .iwram
.arm
.align

.global udiv64_arm

udiv64_arm:

/*
    Tweaked version of 64/32 division found in
    section 7.3.1.3 of
    ARM System Developer’s Guide
    Designing and Optimizing System Software

    ISBN: 1-55860-874-5

    r0 = numerator high, return quotient
    r1 = numerator low
    r2 = denominator
    r3 = scratch
*/

    cmp r0, r2
    bcs .overflow_32
    rsb r2, r2, #0
    adds r3, r1, r1
    adcs r1, r2, r0, LSL#1
    subcc r1, r1, r2

    .rept 31
        adcs r3, r3, r3
        adcs r1, r2, r1, LSL#1
        subcc r1,r1, r2
    .endr

    adcs r0, r3, r3
    bx lr

    .overflow_32:
    mov r0, #-1
    bx lr




.global udiv32_arm

udiv32_arm:

/*
    Tweaked version of 32/32 division found in
    section 7.3.1.1 of
    ARM System Developer’s Guide
    Designing and Optimizing System Software

    ISBN: 1-55860-874-5

    r0 = numerator, return quotient
    r1 = denominator
    r2, r3 = scratch
*/

    mov r3, #0
    rsbs r2, r1, r0, LSR#3
    bcc .div_3bits

    rsbs r2, r1, r0, LSR#8
    bcc .div_8bits

    mov r1, r1, LSL#8
    orr r3, r3, #0xFF000000
    rsbs r2, r1, r0, LSR#4
    bcc .div_4bits

    rsbs r2, r1, r0, LSR#8
    bcc .div_8bits

    mov r1, r1, LSL#8
    orr r3, r3, #0x00FF0000
    rsbs r2, r1, r0, LSR#8
    movcs r1, r1, LSL#8
    orrcs r3, r3, #0x0000FF00
    rsbs r2, r1, r0, LSR#4
    bcc .div_4bits

    rsbs r2, r1, #0
    bcs .div_by_0

.div_loop:

    movcs r1, r1, LSR#8

.div_8bits:

    rsbs r2, r1, r0, LSR#7
    subcs r0, r0, r1, LSL#7
    adc r3, r3, r3

    rsbs r2, r1, r0, LSR#6
    subcs r0, r0, r1, LSL#6
    adc r3, r3, r3

    rsbs r2, r1, r0, LSR#5
    subcs r0, r0, r1, LSL#5
    adc r3, r3, r3

    rsbs r2, r1, r0, LSR#4
    subcs r0, r0, r1, LSL#4
    adc r3, r3, r3

.div_4bits:

    rsbs r2, r1, r0, LSR#3
    subcs r0, r0, r1, LSL#3
    adc r3, r3, r3

.div_3bits:

    rsbs r2, r1, r0, LSR#2
    subcs r0, r0, r1, LSL#2
    adc r3, r3, r3

    rsbs r2, r1, r0, LSR#1
    subcs r0, r0, r1, LSL#1
    adc r3, r3, r3

    rsbs r2, r1, r0
    subcs r0, r0, r1
    adcs r3, r3, r3

.div_next:
    bcs .div_loop

    mov r0, r3
    bx lr

.div_by_0:
    mov r0, #-1
    bx lr
