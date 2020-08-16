#include <stdio.h>
#include <stdlib.h>

struct noh {
    int info;
    struct noh *esq, *dir;
};
typedef struct noh *TREE;

//Definindo funções
void PesqIn(TREE arv);

void insArvoreIN(TREE *arv, int vr);

TREE tPesq(TREE *arv, int vr);

int tRemove(TREE *arv, int vr);

static TREE maiorABB(TREE *abb);

//Programa principal
int main() {
    TREE arvore = NULL;
    int testes, quantPresentes, i, j, pesoPresente, balanco, somaArvEsq, somaArvDir, auxDir, auxEsq, maiorValorEsq, maiorValorDir, equilibrio;
    scanf("%d", &testes);

    //Laço para rodar o programa a quantidade de testes escolhida
    while (testes > 0) {

        //Resetando árvore toda vez que inica um teste e definindo valor 0.
        arvore = NULL;
        insArvoreIN(&arvore, 0);

        scanf("%d", &quantPresentes);

        balanco = 0;
        somaArvEsq = 0;
        somaArvDir = 0;
        maiorValorEsq = 0;
        maiorValorDir = 0;

        for (i = 1; i <= quantPresentes; i++) {

            //Recebe os valores do presente a cada iteração.
            scanf("%d", &pesoPresente);

            //Testa inserção do lado direito
            auxDir = balanco - pesoPresente;

            //Testa inserção do lado esquerdo
            auxEsq = balanco + pesoPresente;

            /*
             * Caso o peso do presente inserido seja muito grande, tenta rebalancear a árvore de forma que a inserção
             * do presente não faça com que a árvore caia. Isso quer dizer que presentes sejam trocados de lado para que
             * a inserção possa ser feita.
             * A tentativa de rebalancear a árvore será feita em caso os testes de inserção a dir e esq resultem em valores
             * (em módulo) maiores que 5.
             * */
            if (arvore->esq != NULL && arvore->dir != NULL && (somaArvDir+somaArvEsq) > 5) {
                if (abs(auxEsq) > 5 && abs(auxDir) > 5) {

                    /*
                     * Neste ponto vemos a necessidade de rebalancear a árvore esquerda ou direita. Por definição das árvores
                     * binárias de busca, iniciaremos os teste sempre da esquerda para direita.
                     *
                     * @equilibrio : Variável que carregará o valor mínimo necessário para retirar da árvore para que
                     * possa ser inserido o presente.
                     * */

                    if (balanco >= 0) { //Significa que a árvore esquerda está mais pesada que a da direita.
                        //Busca pelo valor na árvore.
                        equilibrio = pesoPresente - 5;
                        while (equilibrio != maiorValorEsq) {
                            if (tRemove(&arvore->esq, equilibrio) == 1) {
                                //Elemento não encontrado, valor ao próximo.
                                equilibrio++;
                            } else {
                                //Inserção do presente na árvore da direita.
                                insArvoreIN(&arvore->dir, equilibrio);
                                //Atualiza soma de árvores
                                somaArvEsq = somaArvEsq - j;
                                somaArvDir = somaArvDir + j;
                                auxEsq = somaArvEsq;
                                auxDir = somaArvDir;
                                break;
                            }
                        }
                    } else if (balanco < 0) { //Significa que a árovre direita está mais pesada que a esquerda.
                        equilibrio = pesoPresente - 5;
                        while (equilibrio != maiorValorDir) {
                            if (tRemove(&arvore->dir, equilibrio) == 1) {
                                //Elemento não encontrado, valor ao próximo.
                                equilibrio++;
                            } else {
                                //Presente encontrado e removido.
                                //Inserção do presente na árvore da direita.
                                insArvoreIN(&arvore->esq, equilibrio);
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
            }
            /*
             * Com a árvore equilibrida de forma a ser possível que o presente seja colocado, passamos a inserção do mesmo.
             *
             * */

            if (pesoPresente == 0) { //Ignora caso o peso do presente seja 0.
                //Ignora a inserção
            } else if (abs(auxDir) >= abs(auxEsq)) { //Inserção a esquerda
                insArvoreIN(&arvore->esq, pesoPresente);
                somaArvEsq += pesoPresente;
                if (pesoPresente > maiorValorEsq) {
                    maiorValorEsq = pesoPresente;
                }
            } else { //Inserção a Direita
                insArvoreIN(&arvore->dir, pesoPresente);
                somaArvDir += pesoPresente;
                if (pesoPresente > maiorValorDir) {
                    maiorValorDir = pesoPresente;
                }
            }

            //Atualização do balanço
            balanco = somaArvEsq - somaArvDir;

            if (abs(balanco) > 5) {
                printf("Ho Ho Ho!\n");

                j = i;
                //Laço para terminar a leitua dos presentes
                while (j < quantPresentes) {
                    scanf("%d", &pesoPresente);
                    j++;
                }
                i = quantPresentes + 1;
            } else {
                arvore->info = balanco;
            }
        }

        if (abs(balanco) <= 5) {
            printf("Feliz Natal!\n");
        }

        testes -= 1;

    }
    return 0;
}

void PesqIn(TREE arv) {
//Infixa
    if (arv != NULL) {
        PesqIn(arv->esq);
        printf("%i ", arv->info);
        PesqIn(arv->dir);
    }
}

void insArvoreIN(TREE *arv, int vr) {
    if (*arv == NULL) {
        *arv = (TREE) malloc(sizeof(struct noh));
        (*arv)->info = vr;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
    } else {
        if (vr < (*arv)->info)
            insArvoreIN(&((*arv)->esq), vr);
        else
            insArvoreIN(&((*arv)->dir), vr);
    }
}

int tRemove(TREE *arv, int vr) {
    TREE p;
    if (!*arv) {
//        printf("Elemento não encontrado.\n");
        return 1; //Elemento não encontrado
    }
    if (vr == (*arv)->info) { //caso o valor esteja na raiz
        p = *arv;
        if (!(*arv)->esq)
            *arv = (*arv)->dir; // a raiz não tem filho esquerdo
        else if (!(*arv)->dir)
            *arv = (*arv)->esq; // a raiz não tem filho direito
        else {
            p = maiorABB(&((*arv)->esq));
            (*arv)->info = p->info;
        }
        free(p);
//        printf ("Elemento encontrado e Removido\n");
    } else if ((vr < (*arv)->info) == 1) {
        tRemove(&((*arv)->esq), vr); //Procura na subarvore Esquerda
    } else { //Procura na subarvore Direita
        tRemove(&((*arv)->dir), vr);
    }
}

static TREE maiorABB(TREE *abb) {
    TREE p = *abb;
    if (*abb)
        if (p->dir == NULL) {
            *abb = (*abb)->esq;
            return p;
        }
    return maiorABB(&((*abb)->dir));
}

