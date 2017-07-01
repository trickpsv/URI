for i in range(int(input())):
	s = input()
	menor = 0
	diamante = 0
	for i in s:
		if i == '<':
			menor += 1
		if i == '>' and menor > 0:
			diamante += 1
			menor -= 1
	print(diamante)
