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


//Programa principal
int main () {
    TREE arvore=NULL;
    int testes, quantPresentes, i, pesoPresente;

    scanf("%d", &testes);

    //Laço para rodar o programa a quantidade de testes escolhida
    while(testes > 0){

        //Resetando árvore toda vez que inica um teste e definindo valor 0.
        arvore = NULL;
        insArvoreIN(&arvore, 0);

        scanf("%d", &quantPresentes);

        //Laço principal do programa, onde irá inserir valores do vetor e verificar o balanço da árvore
        for(i = 1 ; i <= quantPresentes ; i++ ){

            scanf("%d", &pesoPresente);

            //Caso o valor inserido não derrube a arvore para a esquerda, insere a esquerda
            if((pesoPresente + arvore->info) <= 5 && (pesoPresente + arvore->info) > -5){
                insArvoreIN(&arvore->esq, pesoPresente);
            }
                //se não, insere a direita
            else{
                insArvoreIN(&arvore->dir, pesoPresente);
            }

            //Atualiza valor do balanço após inserção
            /*
             *  Alterar a soma dos lados da árvore para serem realizados sempre apenas do lado da inserção.
             *
             * */
            arvore->info = somaNoh(arvore->esq) - somaNoh(arvore->dir);
            printf("[%d]\n", arvore->info);

            //Após inserção, verifica se foi quebrado o balanço
            if(arvore->info < -5 || arvore->info > 5){
                //Resultado negativo após inserção
                printf("Ho Ho Ho!\n");
                //Finaliza o teste atual caso não obedeça o balanço
                break;
            } else if (i == (pesoPresente - 1) && arvore->info >=0 && arvore->info <=5 ){
                printf("Feliz Natal!\n");
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