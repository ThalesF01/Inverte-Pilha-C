#include <stdio.h>
#include <stdlib.h>
#include "TADs_lineares_aloc_enc.h"

void inverte(TipoPilha *p){

    TipoFila *f = (TipoFila *)malloc(sizeof(TipoFila));
    CriaFilaVazia(f);
    TipoItem item;

    while (!TestaPilhaVazia(p))
    {
        RemovePilha(p, &item);
        InsereFila (f,item);
    }

    while (!TestaFilaVazia(f))
    {
        RemoveFila(f, &item);
        InserePilha (p,item);
    }
}


int main(void)
{
    printf("-----------------------\n");
    printf("    Lista e Pilha\n");
    printf("-----------------------\n");

    TipoPilha *pilha = (TipoPilha *)malloc(sizeof(TipoPilha));

    CriaPilhaVazia(pilha);

    int qtd;

    printf("\nInforme a quantidade de valores que devem ser inseridos: ");
    scanf("%i",&qtd);

    TipoItem e[qtd];

    printf("\n");
     for(int i=0; i<qtd; i++)
    {
        printf("Informe o valor de posicao %i: ", i+1);
        scanf ("%i", &e[i].chave);
        InserePilha(pilha,e[i]);
     }


    printf("\nValores informados: ");
     for(int i=0; i<qtd; i++)
        printf("%i ", e[i].chave);

     printf("\n\nPilha: ");
     ImprimePilha(pilha);

     inverte(pilha);

     printf("\n\nPilha invertida: ");
     ImprimePilha(pilha);
     printf("\n");

    return 0;
}
