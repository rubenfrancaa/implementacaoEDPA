#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct noh {
	int info;
	struct noh *esq, *dir;
};
typedef struct noh *TREE;

void PesqIn (TREE arv);
void insArvoreIN (TREE *arv, int vr);
int somaNoh (TREE arv);

int main () {
	TREE arvore=NULL,x;
	int testes, tam, i, valor;
    int balanco;

    printf("Insira a quantidade de testes: ");
    scanf("%d", &testes);

    /*
	insArvoreIN (&arvore->esq,6);
	insArvoreIN (&arvore->dir,6);
	insArvoreIN (&arvore->esq,6);
    */

    while(testes > 0){

        arvore = NULL;
        insArvoreIN(&arvore, 0);

        printf("Insira o tamanho do vetor: ");
        scanf("%d", &tam);

        for(i=0;i<tam;i++){
            printf("Digite o %d valor do vetor: ",i+1);
            scanf("%d", &valor);

            balanco = 0;

            if(valor + balanco < 5 && valor + balanco > -5){
                insArvoreIN(&arvore->esq, valor);
            }
            else{
                insArvoreIN(&arvore->dir, valor);
            }
            balanco = somaNoh(arvore->esq) - somaNoh(arvore->dir);


            if(balanco < -5 || balanco > 5){
                printf("SeaFoodDishes\n");
                break;
            }

            printf ("A soma da arvore esquerda e: %d\n",somaNoh(arvore->esq));
            printf ("A soma da arvore direita e: %d\n",somaNoh(arvore->dir));
            printf ("A diferenca entre a arvore esquerda e direita e: %d\n", balanco);

            printf("Balanca mas nao cai!\n\n");

            printf ("Infixa: ");
            PesqIn (arvore);
            printf ("\n");

        }


        printf("--- --- --- --- --- --- --- --- --- --- --- --- \n");

        testes-=1;

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
