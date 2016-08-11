L1:
FUNC main:
	i = 2
L3:
	j = 5
L4:
	j = i * j
L5:
	t1 = 0
	f = t1
	t2 = j
L7:
	if f >= t2 goto L6
L9:
	t3 = "Count"
	len 5
	buffer t3
	sys_write
L8:
	f = f + 1
	goto L7
L6:
	return 0
END FUNC
L2:
