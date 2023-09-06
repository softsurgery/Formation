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

void ajouterGateau (Gateau tabG [],Gateau g,int* tg){
    tabG[*tg] = g;
    (*tg)++;
}

void afficher(Gateau tabG[],int tg){
    for(int i=0;i<tg;i++){
        if (tabG[i].type==0) printf("Gateau N°%d est Chocolat\n",i);
        else if (tabG[i].type==1) printf("Gateau N°%d est Nougatine\n",i);
        else printf("Gateau N°%d est Pistache\n",i);
        printf("Ce Gateau Contient %d Ingrediant(s) :\n",tabG[i].nbi);
        for(int j=0;j<tabG[i].nbi;j++){
            printf("Ingrdiant N°%d : \n",j);
            printf("\tDesignation : %s\n",tabG[i].T[j].des);
            printf("\tPrix Unitaire : %.2f\n",tabG[i].T[j].prix);
            printf("\tQuantite : %d\n",tabG[i].T[j].qte);
        }
    }
}

void trouver(Gateau tabG[],int tg, int type, int *pos){
    int i = 0;
    while(i<tg && tabG[i].type!=type) i++;
    *pos = (i<tg) ? i : -1;
}

float calculerPrix(Gateau g){
    int cout = 0;
    for(int i=0;i<g.nbi;i++) cout += g.T[i].prix * g.T[i].qte;
    return (g.type==0) ? 1.10 * cout : (g.type==1) ? 1.15 * cout : 1.20 *cout;
}

void initialiser(int matV [][7], float tabP[]){
    for(int i=0;i<7;i++){
        tabP[i] = 0;
        for(int j=0;j<3;j++) matV[i][j] = 0;
    }
}

void vendre(int matV[][7], Gateau tabG[], int type, int jour, int* tg, float tabP[]){
    int pos;
    trouver(tabG,*tg,type,&pos);
    if (pos!=-1){
        tabP[jour]+= calculerPrix(tabG[pos]);
        matV[type][jour]++;
        for (int i=pos;i<*tg;i++) tabG[i] = tabG[i+1];
        (*tg)--;
    } else {
        printf("Gateau de type specifie est introuvable\n");
    }
}

void afficherRecette(int matV[][7], int jour, float tabP[]){
    char* jours[] = {"Lundi", "Mardi", "Mercredi", "Jeudi" ,"Vendredi","Samedi","Dimanche"};
    printf("C'est %s on a comme un chiffre d'affaire %.2f",jours[jour],tabP[jour]);
    char* types[] = {"Chocolat","Nougatine","Pistache"}
    for(int i=0;i<3;i++){
        printf("On a effectuer %d achat pour le gateau de type %s\n",matV[i][jour],types[i]);
    }
}

int main(){
    
    return 0;
}