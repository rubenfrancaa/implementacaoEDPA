#include <stdio.h>
#include <stdlib.h>

//Definindo estrutura da árvore
struct node {
  int num;
  struct node* esq;
  struct node* dir;
};
typedef struct node Node;

//Definindo estrutura da fila
struct queue {
  int num;
  struct queue* rear;
  struct queue* front;
} ;
typedef struct queue Queue;

//Função para iniciar a fila (não está retornando pra main os valores, não sei por que.
void Insert_Queue(Queue *queue, int valor){
    
    if (queue){
        printf("Entrou Create_Queue \n");
     
        queue = (Queue *) malloc(sizeof(Queue));
        queue->num = valor;
        queue->rear = NULL;
        queue->front = NULL;
     
        printf("num [%d] \n",queue->num);
        //printf("\nrear %d",queue->rear);
        //printf("\nfront %d",queue->front);
    } else {
        printf("Error: queue already created.");
    }
}

//Função para inserir elemento na fila
void PushInQueue(Queue *queue, int valor){
    if(queue == NULL){
        printf("ERROR: Queue not created already.");
    }
    else{
        if(queue->rear == NULL){
            Queue *next = NULL;
            next = (Queue *) malloc(sizeof(Queue));
            next->front = queue;
            next->rear = NULL;
            next->num = valor;
            queue->rear = next;
        }
        else{
            PushInQueue(queue->rear, valor);
        }
    }
}

//Função para remover elemento da fila
void PopFromQueue(Queue *queue){
    if(queue->front == NULL){
        queue->rear->front = NULL;
        free(queue);
    }
    else{
        PopFromQueue(queue->front);
    }
}

//Função para imprimir fila
void PrintQueue(Queue queue){
	Queue aux;
	aux = queue
	if (queue != NULL){
		printf ("[/|");
		while (queue->front != NULL){
			printf ("%d] -> [",queue->num);
			queue = queue->front;
		}
		printf ("%d|/]\n",queue->num);
	}else{
		printf ("Lista Nula\n");
	}
}

/*
//AINDA NÃO ESTÁ FUNCIONANDO NÃO SEI POR QUE.
//Concatenando vetor de zeros com vetor original
void concat_tree(int vetor, int n){
    int i;
    int *vetor_completo;
    vetor_completo = (int *)malloc(n+n-1);

    //Inserindo valores zero antes do vetor de entrada
    for(i=0;i<n-1;i++){
        vetor_completo[i] = 0;
    }

    //Inserindo valores após os zeros
    for(i=0;i<n;i++){
        vetor_completo[i+n-1] = vetor[i];
    }

    printf("Vetor completo: ");
    for(i=0;i<n+n-1;i++){
        printf("%d", vetor_completo[i]);
    }
    return vetor_completo;
}
*/

//Criar função inverte jogadores

//Criar função de árvores (solucionar, imprimir, etc)


/*Função principal*/
int main(){

    Node *root = NULL;
    Queue *queue = NULL;

    char p1[] = "sanches";
    char p2[] = "rusa";

    printf("player 1: %s \n", p1);
    printf("player 2: %s \n", p2);

    int *vetor;
    int t, n, q;
    int indice;
    int valor;
    int i, j, k, l;

    //A primeira linha de entrada se refere a quantidade testes a ser feita (não inclui nessa conta, as substituições, só testes no vetor original)
    printf("Quantos testes voce deseja fazer? ");
    t = 1;
    printf("1");
    //scanf("%d", &t);
    printf("\nNesta execucao serao realizados %d testes \n", t);

    //A segunda linha da entrada refere-se a N (tamanho do vetor a testar) e Q (quantidade de substituições que serão feitas dentro do vetor para testar).
    for(i=0;i<t;i++){
    
        printf("\nTeste numero %d\n", i+1);
        printf("Entre com os parametros N (tamanho do vetor) e Q (numero de substituicoes): ");
        n = 3;
        q = 0;
        printf("3 0");
        //scanf("%d %d",&n, &q);
        printf("\nO tamanho do vetor sera %d.\n", n);
        printf("\nSerao feitas %d substituicoes.\n", q);

        vetor = (int *)malloc(n);

        vetor[0] = 5;
        vetor[1] = 2;
        vetor[2] = 3;

        /*for(j=0;j<n;j++){
            printf("Entre com cada elemento do vetor de teste: ");
            scanf("%d", &vetor[j]);
        }*/

        printf("\nVetor adicionado:\n");
        for(j=0;j<n;j++){
            printf("%d - ", vetor[j]);
        }
 	printf("\n");
 	
        //CRIAR FUNÇÃO QUE INSERE (N-1) ZEROS ANTES DO VETOR ORIGINAL
        
        for(j = 0; j < n; j++){
     		Insert_Queue(&queue, vetor[j]);       
        }
        printf("Fora. \n");

        //NÃO CONSIGO ACESSAR OS VALORES FORA DA FUNÇÃO CREATE_QUEUE
        //printf("num %d \n",queue->num);
        //printf("\nrear %d",queue->rear);
        //printf("\nfront %d",queue->front);

        //FUNÇÃO DE IMPRESSÃO NÃO ESTÁ FUNCIONANDO (ACHO QUE PQ NÃO CONSIGO ACESSAR QUEUE NA MAIN)
        //PrintQueue(queue);
        printf("Fim. \n");

        //Chamar funcao para preencher arvore, solucionar e imprimir resposta (passar nome do player1 e player2)

        /* ESSE LAÇO SÓ SERÁ NECESSÁRIO QUANDO EXISTIREM SUBSTITUIÇÕES PARA SEREM FEITAS
        //Caso tenha substituições, o vetor tem que ser modificado, e resolver o problema novamente, imprimindo resultados, porém sem alternar entre jogadores.
        if(q>0){
          for(k=0;k<q;k++){
            printf("\nSubstituicao de numero %d", k+1);
            printf("\nEntre com o indice (A) a ser substituido no vetor e o valor (B) que deseja inserir no lugar: ");
            scanf("%d %d", &indice, &valor);
            printf("\nSubstituiremos o valor do indice %d pelo valor %d", indice, valor);
            printf("\nValor antigo: %d", vetor[indice-1]);
            printf("\nValor novo: %d", valor);
            vetor[indice-1]=valor;

            printf("\nNovo vetor: ");
            for(l=0;l<n;l++){
                printf("%d", vetor[l]);
            }
            //Chamar funcao para preencher arvore, solucionar e imprimir resposta
          }
        }
        //Ao final de cada rodada alternam-se os jogadores
        Fazer função pra alternar jogadores (copiar strings)
        swap = p1;
        p1 = p2;
        p2 = swap;
        */
    }
    return 0;
}
