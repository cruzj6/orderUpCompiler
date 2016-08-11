.text

.globl main


.data


str1:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
str2:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
str1: .asciiz "You Entered: "
str2: .asciiz " and "
str3: .asciiz "Hello World"
string1:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
string2:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
instString:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
inst2String:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
g:	.halfword 0
p:	.word 0
passString:	.byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
L1:


main:
FUNC outString:
	$t1 = "You Entered: "
	len 13
	buffer $t1
	sys_write
L4:
	$t2 = str1
	len 20
	buffer $t2
	sys_write
L5:
	$t3 = " and "
	len 5
	buffer $t3
	sys_write
L6:
	$t4 = str2
	len 30
	buffer $t4
	sys_write
L7:
	return
END FUNC
L3:
FUNC getString:
	return "Hello World"
END FUNC
L8:
FUNC main:
	$t5 = instString
	len 50
	buffer $t5
	sys_write
L9:
	$t7 = sys_read
	$t8 = sys_read
	$t9 = sys_read
	move $t6,$t9
	sw $t6, string1
L10:
	$t10 = inst2String
	len 25
	buffer $t10
	sys_write
L11:
	$t12 = sys_read
	$t13 = sys_read
	$t14 = sys_read
	move $t11,$t14
	sw $t11, string2
L12:
	result $t16
	call getString, 0
	result $t17
	call getString, 0
	result $t18
	call getString, 0
	move $t15,$t18
	sw $t15, string1
L13:
	li $t19, 0
	move g, $t19
	li $t20, 19
L15:
	if g >= $t20 goto L14
L17:
	lw $t22, g
	lw $t24, 20
	mult $t22, $t24
	mflo $t23
	li $t21, $t23
	lw $t26, g
	lw $t28, 40
	mult $t26, $t28
	mflo $t27
	li $t25, $t27
	li $t29, string1[$t25]
	passString [ $t21 ] = $t29
L16:
	add g, g, 1
	j L15
L14:
	$t30 = p
	len 4
	buffer $t30
	sys_write
L18:
	param passString
	param string2
	call outString
L19:
	return 0
END FUNC
L2:
