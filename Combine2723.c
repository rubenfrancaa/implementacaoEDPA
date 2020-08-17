#include <stdio.h>
#include <stdlib.h>

struct noh {
    int somaEsq;
    int somaDir;
    struct noh *esq, *dir;
};
typedef struct noh *TREEh;

//Definindo funções
void PesqIn(TREEh arv);
void PesqLeaf(TREEh arv);
int Verifica(TREEh arv, int total);
int alturaArvore(TREEh arv);
void criaArvore(TREEh *arv, int vr);
void insArvore(TREEh *arv, int vr);
void insArvoreEsq(TREEh *arv, int vr, int esqPai, int dirPai);
void insArvoreDir(TREEh *arv, int vr, int esqPai, int dirPai);
void apagaArvore (TREEh arv);

//Programa principal
int main() {
    TREEh arvore = NULL;
    int testes, quantPresentes, i, pesoPresente, total, altura;
    scanf("%d", &testes);

    //Laço para rodar o programa a quantidade de testes escolhida
    while (testes > 0) {

        //Resetando árvore toda vez que inica um teste e definindo valor 0.
        arvore = NULL;
        total = 0;

        //Cria a árvore com raíz zero.
        criaArvore(&arvore, 0);

        scanf("%d", &quantPresentes);

        /* * * Laço para percorrer todos os pesos do presente de 1 teste.
         * A quantidade de pesos de presentes representa a altura da árvore.
         * * */
        for (i = 1; i <= quantPresentes; i++) {

            //Recebe os valores do presente a cada iteração.
            scanf("%d", &pesoPresente);
            insArvore(&arvore, pesoPresente);
            total = total + pesoPresente;

        }
            altura = alturaArvore(arvore);
        //printf ("Altura arvore: [%d] | Quantidade de presentes: [%d]\n", altura, quantPresentes);
         if (altura == quantPresentes){
             printf("Feliz Natal!\n");
         } else {
             printf("Ho Ho Ho!\n");
         }
    apagaArvore(arvore);
    testes -= 1;

    }
    return 0;
}


void criaArvore(TREEh *arv, int vr) {
    if (*arv == NULL) {
        *arv = (TREEh) malloc(sizeof(struct noh));
        (*arv)->somaEsq = vr;
        (*arv)->somaDir = vr;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
//        printf("Arvore criada com sucesso.\n");
    } else {
//        printf("Erro: Árvore já criada.\n");
    }
}

void insArvore(TREEh *arv, int vr) {
    if (*arv != NULL) {
        insArvoreEsq(&((*arv)->esq), vr, 0, 0);
        //insArvoreDir(&((*arv)->dir), vr, 0, 0);
    }
}


void insArvoreEsq(TREEh *arv, int vr, int esqPai, int dirPai) {
    if (*arv == NULL) {
        //printf("InsereEsquerda:\n vr: %d, esqPai: %d, dirPai: %d\n", vr, esqPai, dirPai);
        if( abs(esqPai + vr - dirPai) <= 5) { //Condição para inserir apenas quando o balanço é atingido
            *arv = (TREEh) malloc(sizeof(struct noh));
            (*arv)->somaEsq = esqPai + vr;
            (*arv)->somaDir = dirPai;
            (*arv)->esq = NULL;
            (*arv)->dir = NULL;
        }
    } else {
        insArvoreEsq(&((*arv)->esq), vr, ((*arv)->somaEsq), ((*arv)->somaDir));
        insArvoreDir(&((*arv)->dir), vr, ((*arv)->somaEsq), ((*arv)->somaDir));
    }
}

void insArvoreDir(TREEh *arv, int vr, int esqPai, int dirPai) {
    if (*arv == NULL) {
        //printf("InsereDireita:\n vr: %d, esqPai: %d, dirPai: %d\n", vr, esqPai, dirPai);
        if( abs(dirPai + vr - esqPai) <= 5) {
            *arv = (TREEh) malloc(sizeof(struct noh));
            (*arv)->somaEsq = esqPai;
            (*arv)->somaDir = dirPai + vr;
            (*arv)->esq = NULL;
            (*arv)->dir = NULL;
        }
    } else {
        insArvoreEsq(&((*arv)->esq), vr, ((*arv)->somaEsq), ((*arv)->somaDir));
        insArvoreDir(&((*arv)->dir), vr, ((*arv)->somaEsq), ((*arv)->somaDir));
    }
}

int alturaArvore (TREEh arv) {
    if (!arv)
        return -1;
    else {
        int he = alturaArvore(arv->esq);
        int hd = alturaArvore(arv->dir);

        if (he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

void apagaArvore (TREEh arv) {
    if (arv == NULL)
        return;

    apagaArvore(arv->esq);
    apagaArvore(arv->dir);

    free(arv);
}