	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 15
	.globl	_mtx_init               ## -- Begin function mtx_init
	.p2align	4, 0x90
_mtx_init:                              ## @mtx_init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movslq	(%rdi), %rdi
	movl	$64, %esi
	callq	_ft_calloc
	movq	-8(%rbp), %rsi
	movq	%rax, 24(%rsi)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	(%rcx), %eax
	jge	LBB0_5
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-8(%rbp), %rcx
	movq	24(%rcx), %rcx
	movslq	-12(%rbp), %rdx
	shlq	$6, %rdx
	addq	%rdx, %rcx
	movq	%rcx, %rdi
	callq	_pthread_mutex_init
	cmpl	$0, %eax
	je	LBB0_4
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	callq	_err_message
	movl	%eax, -16(%rbp)         ## 4-byte Spill
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB0_1
LBB0_5:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-8(%rbp), %rcx
	addq	$32, %rcx
	movq	%rcx, %rdi
	callq	_pthread_mutex_init
	cmpl	$0, %eax
	je	LBB0_7
## %bb.6:
	leaq	L_.str(%rip), %rdi
	callq	_err_message
	movl	%eax, -20(%rbp)         ## 4-byte Spill
LBB0_7:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ph_init                ## -- Begin function ph_init
	.p2align	4, 0x90
_ph_init:                               ## @ph_init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %esi
	movq	-8(%rbp), %rdi
	movq	104(%rdi), %rdi
	movslq	-12(%rbp), %rax
	imulq	$88, %rax, %rax
	addq	%rax, %rdi
	movl	%esi, (%rdi)
	movq	-8(%rbp), %rax
	movq	104(%rax), %rax
	movslq	-12(%rbp), %rdi
	imulq	$88, %rdi, %rdi
	addq	%rdi, %rax
	movl	$1, 4(%rax)
	movq	-8(%rbp), %rax
	movq	104(%rax), %rax
	movslq	-12(%rbp), %rdi
	imulq	$88, %rdi, %rdi
	addq	%rdi, %rax
	movl	$0, 64(%rax)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movq	-8(%rbp), %rdi
	movq	104(%rdi), %rdi
	movslq	-12(%rbp), %rcx
	imulq	$88, %rcx, %rcx
	addq	%rcx, %rdi
	movq	%rax, 16(%rdi)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	-8(%rbp), %rcx
	movq	104(%rcx), %rcx
	movslq	-12(%rbp), %rdi
	imulq	$88, %rdi, %rdi
	addq	%rdi, %rcx
	movq	%rax, 24(%rcx)
	movq	-8(%rbp), %rax
	addq	$12, %rax
	movq	-8(%rbp), %rcx
	movq	104(%rcx), %rcx
	movslq	-12(%rbp), %rdi
	imulq	$88, %rdi, %rdi
	addq	%rdi, %rcx
	movq	%rax, 32(%rcx)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movslq	-12(%rbp), %rcx
	shlq	$6, %rcx
	addq	%rcx, %rax
	movq	-8(%rbp), %rcx
	movq	104(%rcx), %rcx
	movslq	-12(%rbp), %rdi
	imulq	$88, %rdi, %rdi
	addq	%rdi, %rcx
	movq	%rax, 40(%rcx)
	movl	-12(%rbp), %esi
	addl	$1, %esi
	movq	-8(%rbp), %rax
	cmpl	(%rax), %esi
	jne	LBB1_2
## %bb.1:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	104(%rcx), %rcx
	movslq	-12(%rbp), %rdx
	imulq	$88, %rdx, %rdx
	addq	%rdx, %rcx
	movq	%rax, 48(%rcx)
	jmp	LBB1_3
LBB1_2:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movl	-12(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	shlq	$6, %rdx
	addq	%rdx, %rax
	movq	-8(%rbp), %rdx
	movq	104(%rdx), %rdx
	movslq	-12(%rbp), %rsi
	imulq	$88, %rsi, %rsi
	addq	%rsi, %rdx
	movq	%rax, 48(%rdx)
LBB1_3:
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	-8(%rbp), %rcx
	movq	104(%rcx), %rcx
	movslq	-12(%rbp), %rdx
	imulq	$88, %rdx, %rdx
	addq	%rdx, %rcx
	movq	%rax, 56(%rcx)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_arr_ph_init            ## -- Begin function arr_ph_init
	.p2align	4, 0x90
_arr_ph_init:                           ## @arr_ph_init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movslq	(%rdi), %rdi
	movl	$88, %esi
	callq	_ft_calloc
	movq	-8(%rbp), %rsi
	movq	%rax, 104(%rsi)
	movl	$0, -12(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	cmpl	(%rcx), %eax
	jge	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	callq	_ph_init
	movl	-12(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -12(%rbp)
	jmp	LBB2_1
LBB2_3:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$1, %edi
	movl	$112, %esi
	callq	_ft_calloc
	movq	%rax, -24(%rbp)
	movl	-8(%rbp), %edi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	callq	_prsr
	cmpl	$0, %eax
	je	LBB3_2
## %bb.1:
	movl	$1, %edi
	leaq	L_.str.1(%rip), %rsi
	movl	$13, %edx
	callq	_write
	movq	-24(%rbp), %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_mtx_init
	movq	-24(%rbp), %rdi
	callq	_arr_ph_init
	movq	-24(%rbp), %rdi
	callq	_launch_threads
	movq	-24(%rbp), %rdi
	callq	_monitor
	jmp	LBB3_3
LBB3_2:
	leaq	L_.str.2(%rip), %rsi
	movl	$1, %eax
	movl	$17, %edx
	movl	%eax, %edi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_write
	movl	-36(%rbp), %edi         ## 4-byte Reload
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	callq	_exit
LBB3_3:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Mutex was not initialised"

L_.str.1:                               ## @.str.1
	.asciz	"args are OK!\n"

L_.str.2:                               ## @.str.2
	.asciz	"args are not OK!\n"


.subsections_via_symbols
