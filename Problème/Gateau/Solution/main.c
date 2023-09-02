#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* des;
    int qte;
    float prix;
} Ingrediant;

typedef struct{
    int type;
    int nbi;
    Ingrediant* T;
} Gateau;

void saisir (Gateau* g){
    char buffer[100];
    do{
        printf("Type = ");
        scanf("%d",&g->type);
    }while(!(g->type>=0 && g->type<=2));
     do{
        printf("Nombre d'ingrediants = ");
        scanf("%d",&g->nbi);
    }while(g->nbi<=0);
    g->T = (Ingrediant*) malloc(sizeof(Ingrediant)*g->nbi);
    for(int i=0;i<g->nbi;i++){
        printf("Designation de l'ingrediant n°%d\n",i);
        gets(buffer);
        g->T[i].des = (char*) malloc(strlen(buffer) + 1);
        strcpy(g->T[i].des,buffer);
        do{
            printf("Quantite de l'ingrediant n°%d\n");
            scanf("%d",&g->T[i].qte);
        }while(g->T[i].qte <= 0);
         do{
            printf("Prix Unitaire de l'ingrediant n°%d\n");
            scanf("%f",&g->T[i].prix);
        }while(g->T[i].prix <= 0);
    }
}