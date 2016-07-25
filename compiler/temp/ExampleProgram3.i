L1:
FUNC testFunc:
	bOrS = bacon
L4:
	i = 0
L5:
	t1 = 0
	i = t1
	t2 = b * 3 + 4
L7:
	if i >= t2 goto L6
L9:
	iffalse i <==> 2 goto L11
L10:
	iffalse b <==> 3 goto L8
L12:
	goto L6
	goto L8
L11:
	iffalse i <==> 3 goto L14
L13:
	t3 = sys_read
	inString = t3
	goto L8
L14:
	iffalse bOrS goto L8
L15:
	goto L6
L8:
	i = i + 1
	goto L7
L6:
	return
END FUNC
L3:
FUNC meow:
	return "MEOW"
END FUNC
L16:
FUNC main:
	param 'n'
	t4 = 3 - 2
	param t4 * 5
	call testFunc
L17:
	call meow
L18:
	return 0
END FUNC
L2:
