L1:
FUNC main:
	t1 = 2 * 8
	nums [ t1 ] = 5
L3:
	loopCount = 10
L4:
	loopString = "i is even or 0!
"
L5:
	t2 = 5 * 50
	loopString [ t2 ] = '2'
L6:
	t3 = 0
	i = t3
	t4 = loopCount - 1
L8:
	if i >= t4 goto L7
L10:
	t5 = i % 2
	iffalse t5 <==> 0 goto L13
L12:
	t6 = i + 3
	i = t6 * 2
L14:
	iffalse i <==> 6 goto L15
L16:
	goto L7
L15:
	i = 4
	goto L11
L13:
	iffalse i <=!=> 12 goto L18
L17:
	t7 = sys_read
	b = t7
	goto L11
L18:
L19:
L11:
	testNum = 12
L9:
	i = i + 1
	goto L8
L7:
	return 0
END FUNC
L2:
