L1:outString:
	t1 = You Entered: 
	sys_write
L4:	t2 = str1
	sys_write
L5:	t3 =  and 
	sys_write
L6:	t4 = str2
	sys_write
L7:END
L3:getString:
END
L8:main:
	t5 = instString
	sys_write
L9:	t6 = sys_read
	string1 = t6
L10:	t7 = inst2String
	sys_write
L11:	t8 = sys_read
	string2 = t8
L12:	string1 = getString
L13:L14:	t9 = p
	sys_write
L15:L16:END
L2: