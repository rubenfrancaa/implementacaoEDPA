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
TREE tPesq (TREE *arv,int vr);
int tRemove (TREE *arv, int vr);
static TREE maiorABB (TREE *abb);

//Programa principal
int main () {
    TREE arvore=NULL;
    int testes, quantPresentes, i, j, pesoPresente, balanco, somaArvEsq, somaArvDir, auxDir, auxEsq ,max, equilibrio, remove;
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
        max = 0;

        for(i = 1 ; i <= quantPresentes ; i++ ){

            auxDir = 0;
            auxEsq = 0;
            remove = 0;

            scanf("%d", &pesoPresente);
            printf("\nPesoPresente: %d\n", pesoPresente);

//            printf("Max: %d\n", max);

            printf("Balanço: %d\n", balanco);
            //Simulação inserção esquerda
            auxEsq = balanco + pesoPresente;
            printf("auxEsq: %d\n", auxEsq);

            //Simulação inserção direita
            auxDir = balanco - pesoPresente;
            printf("auxDir: %d\n", auxDir);

            printf("auxEsq: %d\n", auxEsq);
            printf("auxDir: %d\n", auxDir);

//            Tentativa de equilibrar árvore
            if(abs(auxDir) > 5 && abs(auxEsq) > 5 ){
                if(balanco >= 0){
                    printf("Tentativa balanceamento tirando da esquerda.\n");
                    equilibrio = pesoPresente - 5;
                    printf("equilibrio: %d\n", equilibrio);

                    for(j=equilibrio ; j<=max ; j++){
                        printf("Remove: j = %d\n", j);
                        if(tRemove(&arvore->esq, j) != 1){
                            insArvoreIN(&arvore->dir, j);
                            printf("SomaEsq: %d\n", somaArvEsq);
                            printf("SomaDir: %d\n", somaArvDir);
                            //Atualiza soma de árvores
                            somaArvEsq = somaArvEsq - j;
                            somaArvDir = somaArvDir + j;
                            auxEsq = somaArvEsq;
                            auxDir = somaArvDir;
                            break;
                        }
                    }
                }
                else{
                    printf("Tentativa balanceamento tirando da direita.\n");
                    equilibrio = pesoPresente - 5;
                    printf("equilibrio: %d\n", equilibrio);

                    for(j=equilibrio ; j<=max ; j++){
                        printf("Remove: j = %d\n", j);
                        if(tRemove(&arvore->dir, j) != 1){
                            insArvoreIN(&arvore->esq, j);
                            printf("SomaEsq: %d\n", somaArvEsq);
                            printf("SomaDir: %d\n", somaArvDir);
                            //Atualiza soma de árvores
                            somaArvEsq = somaArvEsq + j;
                            somaArvDir = somaArvDir - j;
                            auxEsq = somaArvEsq;
                            auxDir = somaArvDir;
                            break;
                        }
                    }
                }
            }

            //Caso o valor inserido não derrube a arvore para a esquerda, insere a esquerda
            if (pesoPresente == 0){
                printf("Pula inserção.\n");
            }
            else if(abs(auxDir) >= abs(auxEsq)){
                    insArvoreIN(&arvore->esq, pesoPresente);
                    somaArvEsq += pesoPresente;
                    printf("Inseriu a esquerda\n");
//                    printf("SomaArvEsq: %d\n", somaArvEsq);
            }

            //se não, insere a direita
            else{
                insArvoreIN(&arvore->dir, pesoPresente);
                somaArvDir += pesoPresente;
                printf("Inseriu a direita\n");
//                printf("SomaArvDir: %d\n", somaArvDir);
            }

            //Atualização do Balanço
            balanco = somaArvEsq - somaArvDir;
            printf("balanco: %d\n", balanco);

            //Após inserção, verifica se foi quebrado o balanço
            if(abs(balanco) > 5){
                //Resultado negativo após inserção
                printf("Ho Ho Ho!\n");

                j = i;
                //Laço para terminar de ler todos valores do vetor
                while(j < quantPresentes){
                    scanf("%d", &pesoPresente);
                    j++;
                }
                //Finaliza o teste atual caso não obedeça o balanço
                break;
            } else {
                arvore->info = balanco;
            }

            if(max < pesoPresente){
                max = pesoPresente;
            }
            printf ("\nArvore esquerda: ");
            PesqIn (arvore->esq);
            printf ("\nArvore direita: ");
            PesqIn (arvore->dir);
            printf ("\n");
            printf("balanco: %d\n", balanco);

        }

        if (abs(balanco) <= 5){
            printf("Feliz Natal!\n");
            //printf("teste %d. Feliz Natal!\n", testes2 - testes + 1);
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

TREE tPesq (TREE *arv,int vr){
    if (!*arv)   //Elemento n�o encontrado
        return (NULL);
    else
    if (vr == (*arv)->info) // Elemento encontrado na raiz
        return (*arv);
    else
    if (vr < (*arv)->info)
        return (tPesq(&((*arv)->esq),vr));
    else
        return (tPesq(&((*arv)->dir), vr));
}

int tRemove (TREE *arv, int vr){
    TREE p;
    if (!*arv) {
        printf("Elemento não encontrado.\n");
        return 1; //Elemento n�o encontrado
    }
    if ((vr == (*arv)->info) == 1){
        p = *arv;
        if (!(*arv)->esq)
            *arv = (*arv)->dir; // a raiz n�o tem filho esquerdo
        else
        if (!(*arv)->dir)
            *arv = (*arv)->esq; // a raiz n�o tem filho direito
        else{
            p = maiorABB (&((*arv)->esq));
            (*arv)->info = p->info;
        }
        free(p);
        printf ("Elemento encontrado e Removido\n");
    }
    else
    if ((vr < (*arv)->esq)==1) //Procura na subarvore esquerda
        tRemove (& ((*arv)->esq),vr);
    else
        tRemove (& ((*arv)->dir),vr);
}

static TREE maiorABB (TREE *abb){
    TREE p = *abb;
    if (*abb)
        if (p->dir == NULL){
            *abb = (*abb)->esq;
            return p;
        }
    return maiorABB(&((*abb)->dir));
}
