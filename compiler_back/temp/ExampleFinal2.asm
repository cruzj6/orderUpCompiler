.data
first: .word 0
second: .word 0
counter: .word 0
str1: .asciiz "Result: "
str2: .asciiz "
"
remainder: .word 0
str3: .asciiz "Remainder: "
str4: .asciiz "
"
test: .word 0
str5: .asciiz "
That Number is Even"
str6: .asciiz "
That Number is 72"
str7: .asciiz "
That Number is Odd"
.text
.globl main


main:
L1:
	li $t1, 2
	sw $t1, first
L3:
	li $t2, 5
	sw $t2, second
L4:
	lw $t5, first
	lw $t7, second
	mult $t5, $t7
	mflo $t6
	lw $t8, first
	lw $t1, second
	mult $t8, $t1
	mflo $t9
	move $t4, $t9
	move $t2, $t4
	li $t4, 2
	move $t3, $t2
	add $t3, $t3, $t4
	move $t3, $t3
	sw $t3, second
L5:
	li $v0, 4
	la $a0, str1
	syscall
L6:
	li $v0, 1
	lw, $a0 second
	syscall
L7:
	li $v0, 4
	la $a0, str4
	syscall
L8:
	li $t9, 12
	li $t2, 5
	move $t1, $t9
	rem $t1, $t1, $t2
	move $t8, $t1
	sw $t8, remainder
L9:
	li $v0, 4
	la $a0, str3
	syscall
L10:
	li $v0, 1
	lw, $a0 remainder
	syscall
L11:
	li $v0, 4
	la $a0, str4
	syscall
L12:
	li $t8, 3
	li $t1, 2
	div $t8, $t1
	mflo $t9
	li $t2, 3
	li $t4, 2
	div $t2, $t4
	mflo $t3
	move $t7, $t3
	li $t6, 1
	move $t8, $t7
	move $t7, $t6
	add $t7, $t7, $t8
	li $t9, 1
	move $t2, $t7
	move $t1, $t9
	add $t1, $t1, $t2
	move $t5, $t1
	lw $t4, remainder
	move $t6, $t5
	mult $t4, $t6
	mflo $t5
	lw $t7, remainder
	move $t9, $t5
	mult $t7, $t9
	mflo $t8
	move $t3, $t8
	lw $t2, second
	li $t4, 3
	mult $t2, $t4
	mflo $t3
	lw $t5, second
	li $t7, 3
	mult $t5, $t7
	mflo $t6
	move $t1, $t6
	move $t8, $t3
	move $t1, $t1
	move $t9, $t8
	add $t9, $t9, $t1
	move $t6, $t9
	sw $t6, test
L13:
	li $v0, 1
	lw, $a0 test
	syscall
L14:
	lw $t4, test
	li $t6, 2
	move $t5, $t4
	rem $t5, $t5, $t6
	lw $t7, test
	li $t9, 2
	move $t8, $t7
	rem $t8, $t8, $t9
	move $t3, $t8
	move $t1, $t3
	bne $t1, 0, L17
L16:
	li $v0, 4
	la $a0, str5
	syscall
	j L15
L17:
	lw $t4, test
	bne $t4, 72, L19
L18:
	li $v0, 4
	la $a0, str6
	syscall
	j L15
L19:
L20:
	li $v0, 4
	la $a0, str7
	syscall
L15:
L2:
li $v0,10
syscall
