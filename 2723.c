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
    int testes, quantPresentes, i, j, pesoPresente, balanco, somaArvEsq, somaArvDir, auxDir, auxEsq;

    scanf("%d", &testes);

    //Laço para rodar o programa a quantidade de testes escolhida
    while(testes > 0){

        //Resetando árvore toda vez que inica um teste e definindo valor 0.
        arvore = NULL;
        insArvoreIN(&arvore, 0);

        scanf("%d", &quantPresentes);

        balanco = 0;
        somaArvEsq = 0;
        somaArvDir = 0;

        for(i = 1 ; i <= quantPresentes ; i++ ){

            auxDir = 0;
            auxEsq = 0;

            scanf("%d", &pesoPresente);

            //Simulação inserção direita
            auxDir = balanco - pesoPresente;
            //printf("auxDir: %d\n", auxDir);

            //Simulação inserção esquerda
            auxEsq = balanco + pesoPresente;
            //printf("auxEsq: %d\n", auxEsq);

            //Caso o valor inserido não derrube a arvore para a esquerda, insere a esquerda
            if(abs(auxDir) >= abs(auxEsq)){
                insArvoreIN(&arvore->esq, pesoPresente);
                somaArvEsq += pesoPresente;
                //printf("SomaArvEsq: %d\n", somaArvEsq);
            }

            //se não, insere a direita
            else{
                insArvoreIN(&arvore->dir, pesoPresente);
                somaArvDir += pesoPresente;
                //printf("SomaArvDir: %d\n", somaArvDir);
            }

            //Atualização do Balanço
            balanco = somaArvEsq - somaArvDir;
            //printf("balanco: %d\n", balanco);

            //Após inserção, verifica se foi quebrado o balanço
            if(abs(balanco) > 5){
                //Resultado negativo após inserção
                printf("Ho Ho Ho!\n");
                
                j = i;
                //Laço para terminar de ler todos valores do vetor
                while(j < quantPresentes){
                    //printf("For hohoho, %d vez", j);
                    scanf("%d", &pesoPresente);
                    j++;
                }
                //Finaliza o teste atual caso não obedeça o balanço
                break;
            } else {
                arvore->info = balanco;
            }

        }

        if (abs(balanco) <= 5){
            printf("Feliz Natal!\n");
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
