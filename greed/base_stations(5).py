'''
Instala o menor número de estacoes possível que cobrem todas as casas

No caminho 
	Encontre a primeira casa fora da cobertura
	Ande 4 milhas
		Instale uma torre
'''
def main():
	casas = [] #Distancias das casas ao ínicio da estrada(origem) em milhas
	estacoes = [] #Distancias de estacoes em relação a origem

	quantidade_casas = int(input('Digite a quantidade de casas no caminho: '))
	#Recebe o conjunto de casas como entrada
	for i in range(quantidade_casas):
		entrada = int(input('Casa %s: ' % i))
		casas.append(entrada)

	print('Casas: \n%s' % casas)

	casas.sort()
	print('Casas ordenadas: \n%s' % casas)

	estacoes.append(casas[0] + 4) #Adicionando primeira estação
	#Para todas as casas 
	for casa in casas: 
		#Se a casa não está coberta por alguma estação, instala uma nova torre
		if casa > estacoes[-1]: 
			estacoes.append(casa + 4)

	print('Estações: \n%s' % estacoes)

main()