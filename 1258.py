dic = {'P':1 , 'M':2 , 'G':3}
tam = [ ' ' ,'P' ,'M','G']

n = int(input())

while(1):
	l = []
	

	
	for i in range(n):
		nome = input()
		camisa = input().split(' ')
		l.append([camisa[0],dic[camisa[1]],nome])
		
	l.sort()
	for i in l:
		print(i[0] +' ' +  tam[i[1]] +' '+ i[2])
	
	n = int(input())
	if n == 0 :
		break
	print('')
		
