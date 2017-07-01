dic = {}

x = input().split()

M = int(x[0])
N = int(x[1])

for i in range(M):
	x = input().split()
	dic[x[0]] = int(x[1])

for i in range(N):
	cont = 0
	while(1):
		x = input()
		if x == '.':
			break;
		x = x.split()
		
		for i in x:
			if i in dic:
				cont += dic[i]
	print(cont)	


