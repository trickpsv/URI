dic = {'GR':1 , 'GB': 2 , 'BR': 2,'BG': 1 , 'RG': 2,'RB': 1}
times = {'B':0 ,  'G':0 , 'R':0}

T = int(input())

for i in range(T):
	times = {'B':0 ,  'G':0 , 'R':0}
	
	n = int(input())
	for j in range(n):
		a = input().split(' ')
		times[a[0]]+=dic[a[0]+a[1]]
	
	if (times['B'] == times['G'] and times['B'] == times['R'] ):
		print('trempate')
	elif((times['B'] == times['G'] and times['B'] > times['R'] )or (times['B'] == times['R'] and times['B'] >times['G']) or (times['G'] == times['R'] and times['R'] >times['B'])):
		print('empate');
	elif(times['B'] > times['R'] and times['B'] > times['G']):
		print('blue')
	elif(times['R'] > times['B'] and times['R'] > times['G']):
		print('red')
	elif(times['G'] > times['R'] and times['G'] > times['B']):
		print('green')
	
