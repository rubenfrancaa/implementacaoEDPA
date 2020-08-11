#include <stdio.h>
#include <stdlib.h>

//Definindo estrutura da árvore
struct noh {
	int info;
	struct noh *esq, *dir;
};
typedef struct noh *TREE;

//Definindo funções
void PesqIn (TREE arv);
void insArvoreIN (TREE *arv, int vr);
int somaNoh (TREE arv);

/*
* Alteração programada: inserir os dados em um vetor de tamanho variável. O preenchimento total do vetor se dá antes da inserção em árvore.
* A partir da inserção em árvore os testes são para cada teste (árvore cai ou não)
*/

//Programa principal
int main () {
	TREE arvore=NULL;
	int testes, tam, i, valor, balanco;

   // printf("Insira a quantidade de testes: ");
    scanf("%d", &testes);

    //Laço para rodar o programa a quantidade de testes escolhida
    while(testes > 0){

        //Resetando árvore toda vez que inica um teste e definindo valor 0.
        arvore = NULL;
        insArvoreIN(&arvore, 0);

        //O balanço sempre inicia vazio
        balanco = 0;

        //printf("Insira o tamanho do vetor: ");
        scanf("%d", &tam);

        //Laço principal do programa, onde irá inserir valores do vetor e verificar o balanço da árvore
        for(i = 0 ; i  < tam ; i++ ){
           // printf("Digite o %d valor do vetor: ",i+1);
            scanf("%d", &valor);

            //Caso o valor inserido não derrube a arvore para a esquerda, insere a esquerda
            if(valor + balanco < 5 && valor + balanco > -5){
                insArvoreIN(&arvore->esq, valor);
            }
            //se não, insere a direita e logo após, verifica se a árvore permanece em pé
            else{
                insArvoreIN(&arvore->dir, valor);
            }

            //Atualiza valor do balando após inserção
            //R: Esse valor não deveria atualizar o valor da raiz do nó ?
            balanco = somaNoh(arvore->esq) - somaNoh(arvore->dir);
            arvore->info = balanco;

            //Após inserção, verifica se foi quebrado o balanço
            if(arvore->info < -5 || arvore->info > 5){
                //Resultado negativo após inserção
                printf("Ho Ho Ho!\n");
                //Finaliza o teste atual caso não obedeça o balanço
                break;
            }

            /*
            //Impressões de teste
            printf ("A soma da arvore esquerda e: %d\n",somaNoh(arvore->esq));
            printf ("A soma da arvore direita e: %d\n",somaNoh(arvore->dir));
            printf ("A diferenca entre a arvore esquerda e direita e: %d\n", balanco);

            //Resultado positivo após inserção
            printf("Balanca mas nao cai!\n\n");

            //Impressão da árvore para teste
            printf ("Infixa: ");
            PesqIn (arvore);
            printf ("\n");
			*/
        }
        
        if (balanco >=0 || balanco <= 5){
        	printf("Feliz Natal!\n");
        }

        //printf("--- --- --- --- --- --- --- --- --- --- --- --- \n");

        testes -= 1;

    }

    return 0;

}

void PesqIn (TREE arv){
//Infixa
	if (arv != NULL){
		PesqIn (arv->esq);
		printf ("%i ",arv->info);
		PesqIn (arv->dir);
	}
}

void insArvoreIN (TREE *arv, int vr){
//Infixa
	if (*arv == NULL){
		*arv = (TREE) malloc (sizeof (struct noh));
		(*arv)->info = vr;
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
	}else{
		if (vr < (*arv)->info)
			insArvoreIN (&((*arv)->esq),vr);
		else
			insArvoreIN (&((*arv)->dir),vr);
	}
}

int somaNoh (TREE arv) {

    if (!arv)
    	return 0;
   return somaNoh(arv->esq) + somaNoh(arv->dir) + (0+arv->info);
}
