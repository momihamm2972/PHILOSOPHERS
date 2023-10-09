	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_my_turn                ## -- Begin function my_turn
	.p2align	4, 0x90
_my_turn:                               ## @my_turn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$4, %edi
	callq	_malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$47, (%rax)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$8, -12(%rbp)
	jge	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$1, %edi
	callq	_sleep
	movq	-8(%rbp), %rcx
	movl	(%rcx), %esi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	-12(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -12(%rbp)
	movq	-8(%rbp), %rcx
	movl	(%rcx), %edx
	addl	$1, %edx
	movl	%edx, (%rcx)
	jmp	LBB0_1
LBB0_3:
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_your_turn              ## -- Begin function your_turn
	.p2align	4, 0x90
_your_turn:                             ## @your_turn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -4(%rbp)
	jge	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	$1, %edi
	callq	_sleep
	leaq	L_.str.1(%rip), %rdi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	-4(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -4(%rbp)
	jmp	LBB1_1
LBB1_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
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
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_my_turn(%rip), %rdx
	leaq	-8(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_your_turn
	movq	-8(%rbp), %rdi
	leaq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_pthread_join
	movq	-16(%rbp), %rcx
	movl	(%rcx), %esi
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"my_turn>>>%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"your_turn\n"

L_.str.2:                               ## @.str.2
	.asciz	"finish <++%d++>\n"

.subsections_via_symbols
