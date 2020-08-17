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

void criaArvore(TREEh *arv, int vr);
void insArvore(TREEh *arv, int vr);
void insArvoreEsq(TREEh *arv, int vr, int esqPai, int dirPai);
void insArvoreDir(TREEh *arv, int vr, int esqPai, int dirPai);

//Programa principal
int main() {
    TREEh arvore = NULL;
    int testes, quantPresentes, i, pesoPresente, total, resposta;
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
            total += pesoPresente;

            resposta = Verifica(arvore, total);

            PesqIn(arvore);

            if(resposta == 1){
                printf("Hohoho!\n");
            }

        }

        printf("Feliz Natal!\n");


        printf("\n");

//        printf("Contemple os nós folhas.\n");
//        PesqLeaf(arvore);
//        resposta = Verifica(arvore, total);

        printf("\n");

        testes -= 1;

    }
    return 0;
}

/*Falta retornar pra main que essas respotas impressas
 * representam "Feliz Natal", caso não haja respostas => Hohoho!
*/

 int Verifica(TREEh arv, int total) {
//Infixa
//    if(arv->somaDir == 0 && arv->somaEsq == 0){
//        Verifica(arv->esq, total);
//        Verifica(arv->dir, total);
//    }
    if(arv) {
        if (arv->somaEsq + arv->somaDir == total) {
            return 0;
        } else {
            Verifica(arv->esq, total);
            Verifica(arv->dir, total);
            return 1;
        }
    }
}


/*int Verifica(TREEh arv, int total) {
//Infixa
    if (arv == NULL) {
        return 0;
    }
    if(arv->somaEsq + arv->somaDir == total && abs(arv->somaEsq - arv->somaDir) <= 5){
        printf("%i | %i\t", arv->somaEsq, arv->somaDir);
        printf("//\tdiferenca: %d  \t",arv->somaEsq-arv->somaDir);
        printf("// soma: %d\t//\t total: %d\n", arv->somaEsq + arv->somaDir, total);
    }
    if(arv->esq != NULL){
        Verifica(arv->esq, total);
    }
    if(arv->dir != NULL){
        Verifica(arv->dir, total);
    }
}*/

void PesqIn(TREEh arv) {
//Infixa
    if (arv != NULL) {
        printf("%i | %i\n", arv->somaEsq, arv->somaDir);
        PesqIn(arv->esq);
        PesqIn(arv->dir);
    }
}

void PesqLeaf(TREEh arv) {
//Infixa
    if (arv == NULL) {
        return;
    }
    if(arv->esq == NULL && arv->dir == NULL){
        printf("%i | %i \n", arv->somaEsq, arv->somaDir);
    }
    if(arv->esq != NULL){
        PesqLeaf(arv->esq);
    }
    if(arv->dir != NULL){
        PesqLeaf(arv->dir);
    }
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
        insArvoreDir(&((*arv)->dir), vr, 0, 0 );
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
