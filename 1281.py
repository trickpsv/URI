# -*- coding: utf-8 -*-

dic = {}
n = int(input())

for i in range(n):
	m = int(input())
	dic = {}
	for j in range(m):
		entrada = input().split()
		fruta = entrada[0]
		preco = float(entrada[1])
		dic[fruta] = preco
	p = int(input())
	
	total = 0
	for i in range(p):
		entrada = input().split()
		fruta = entrada[0]
		quantidade = int(entrada[1])
		total+= dic[fruta]*quantidade
	total = "%.2f" % (total)
	print("R$ " + total)
