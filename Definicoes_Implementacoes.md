Definições para implementação

- Fator de balanceamento e valor raiz.
	- Um valor inteiro resultado de sum_esq - sum_dir
	- Raiz inicia com 0
	- Se a árvore não cair
		- raiz deve ser atualizada a cada inserção.
		
- A cada inserção, deve ser verificada se a árvore cai
	- Cai se
		|sum_esq - sum_dir| > 5
	- Fica se
		|sum_esq - sum_dir| <= 5


- Ordem de execução do algoritmo
	- Insere o valor na árove
	- Soma os lados
		- Se a soma de um lado for null, considerar 0
	- Verificar se árvore cai
		- se cair acaba
		- se ficar de pé 
			- altera a raiz
			- volta na inserção	
			
- Ordem de inserção em nós folhas
	- Não há balanceamento neste ponto
		- Nó deve ser inserido sempre no lado que estiver vazio. 
	- Prioridade de inserção sempre a esquerda
	
** Verificar como será construída a árvore após a decisão de lado (esq, dir).
