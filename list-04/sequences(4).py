
def receber_entrada(vetor):
	while True:
	   entrada = input('Digite um elemento (ou digite n para terminar): ')
	   if entrada == 'n':
	      break
	   vetor.append(entrada)
	return vetor

'''
Define se um conjunto candidato é ou não subconjunto de um conjunto de eventos dados em tempo O(m+n)
   
Para todo elemento do provavel subconjunto:
	ande no conjunto a procura do elemento no conjunto
		se elemento == 
        	procure esse elemento em S
	            se não existe: não é subconjunto
	            se existe: loop
'''
def main():
	conjunto = []
	print('Digite os elementos do conjunto')
	conjunto = receber_entrada(conjunto)

	candidato_a_subconjunto = []
	print('Digite os elementos do candidato a subconjunto')
	candidato_a_subconjunto = receber_entrada(candidato_a_subconjunto)
	tamanho_inicial_candidato = len(candidato_a_subconjunto)

	count = 0
	while len(candidato_a_subconjunto) > 0  and len(conjunto) > 0:
		if candidato_a_subconjunto[0] == conjunto[0]:
			count +=1
			candidato_a_subconjunto.pop(0)
			conjunto.pop(0)
		else:
			conjunto.pop(0)

	if(count == tamanho_inicial_candidato):
		print('subconjunto')
	else:
		print('não subconjunto')

main()