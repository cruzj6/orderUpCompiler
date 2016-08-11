L1:
FUNC outString:
	t1 = "You Entered: "
	len 13
	buffer t1
	sys_write
L4:
	t2 = str1
	len 20
	buffer t2
	sys_write
L5:
	t3 = " and "
	len 5
	buffer t3
	sys_write
L6:
	t4 = str2
	len 30
	buffer t4
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
	t5 = instString
	len 50
	buffer t5
	sys_write
L9:
	t6 = sys_read
	string1 = t6
L10:
	t7 = inst2String
	len 25
	buffer t7
	sys_write
L11:
	t8 = sys_read
	string2 = t8
L12:
	result t9
	call getString, 0
	string1 = t9
L13:
	t10 = 0
	g = t10
	t11 = 19
L15:
	if g >= t11 goto L14
L17:
	t12 = g * 20
	t13 = g * 40
	t14 = string1[t13]
	passString [ t12 ] = t14
L16:
	g = g + 1
	goto L15
L14:
	t15 = p
	len 4
	buffer t15
	sys_write
L18:
	param passString
	param string2
	call outString
L19:
	return 0
END FUNC
L2:
