.data
first: .word 0
second: .word 0
counter: .word 0
str1: .asciiz "Loop!
"
str2: .asciiz "Even Counter: "
str3: .asciiz "
"
str4: .asciiz "Odd Counter: "
str5: .asciiz "
"
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
	lw $t4, first
	lw $t6, second
	mult $t4, $t6
	mflo $t5
	move $t3, $t5
	sw $t3, second
L5:
	li $t7, 0
	lw $t9, counter
	move $t9, $t7
	sw $t9, counter
L7:
	lw $t8, second
	lw $t2, counter
	bge $t2, $t8, L6
L9:
	li $v0, 4
	la $a0, str1
	syscall
L10:
	lw $t6, counter
	li $t8, 2
	move $t7, $t6
	rem $t7, $t7, $t8
	lw $t9, counter
	li $t2, 2
	move $t1, $t9
	rem $t1, $t1, $t2
	move $t5, $t1
	move $t3, $t5
	bne $t3, 0, L12
L11:
	li $v0, 4
	la $a0, str2
	syscall
L13:
	li $v0, 1
	lw, $a0 counter
	syscall
L14:
	li $v0, 4
	la $a0, str5
	syscall
	j L8
L12:
L15:
	li $v0, 4
	la $a0, str4
	syscall
L16:
	li $v0, 1
	lw, $a0 counter
	syscall
L17:
	li $v0, 4
	la $a0, str5
	syscall
L8:
	lw $t2, counter
	add $t2, $t2, 1
	sw $t2, counter
	j L7
L6:
L2:
li $v0,10
syscall
