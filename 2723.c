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
    int testes, quantPresentes, i, pesoPresente, balanco=0, somaArvEsq = 0,somaArvDir = 0, auxDir=0, auxEsq=0;

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

            //Simulação inserção direita
            auxDir = abs(balanco - pesoPresente);
            //Simulação inserção esquerda
            auxEsq = abs(balanco + pesoPresente);

            //Caso o valor inserido não derrube a arvore para a esquerda, insere a esquerda
            if(auxDir > auxEsq){
                insArvoreIN(&arvore->esq, pesoPresente);
                somaArvEsq += pesoPresente;
            }
                //se não, insere a direita
            else if (auxDir > auxEsq){
                insArvoreIN(&arvore->dir, pesoPresente);
                somaArvDir += pesoPresente;
            }

            //Atualização do Balanço
            balanco = abs(somaArvEsq - somaArvDir);

            //Após inserção, verifica se foi quebrado o balanço
            if(balanco > 5){
                //Resultado negativo após inserção
                printf("Ho Ho Ho!\n");
                //Finaliza o teste atual caso não obedeça o balanço
                break;
            } else {
                arvore->info = balanco;
            }

        }
        if (balanco <= 5 ){
            printf("Feliz Natal!\n");
            balanco = 0;
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