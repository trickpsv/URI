while(1):
	try:
		x = input().split(' ')
	except EOFError:
		break
	
	if (x[0] == '' ):
		break
	
	n = int(x[0])
	m = int(x[1])

	dic = {}

	x = input().split(' ')

	cont = 1
	for i in x:
		if int(i) in dic:
			dic[int(i)].append(cont)
		else:
			dic[int(i)] = [cont]
		cont +=1
		
	for i in range(m):
		x = input().split(' ')
		k = int(x[0])
		v = int(x[1])
		
		if v in dic and k <= len(dic[v]) :
			print(dic[v][k-1])
		else:
			print(0)
