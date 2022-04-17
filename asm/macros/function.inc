	.macro arm_func_start name:req
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name:req
	.size \name, .-\name
	.endm

	.macro thumb_func_start name:req
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name:req
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name:req
	.size \name, .-\name
	.endm
