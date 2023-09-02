#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 20

int somme(int x,int y){ return x+y;}

int factorielle(int n){
    int f = 1;
    for(int i=2;i<=n;i++) f*=i;
    return f;
}

int produit_f(int x,int y){return factorielle(x)*factorielle(y);}

int pf_reste(int x,int y){return produit_f(x,y) % somme(x,y);}

bool pfr_verif(int x,int y) {
    int reste = pf_reste(x,y);
    return reste == x || reste == y;
}

void remplir_relations(int M[][MAX_SIZE],int n){
    for(int i=0;i<n;i++){
        printf("Couple N°%d\n",i);
        printf("A = ");
        scanf("%d",&M[i][0]);
        printf("B = ");
        scanf("%d",&M[i][1]);
        M[i][2] = somme(M[i][0],M[i][1]);
        M[i][3] = factorielle(M[i][0]);
        M[i][4] = factorielle(M[i][1]);
        M[i][5] = produit_f(M[i][0],M[i][1]);
        M[i][6] = pf_reste(M[i][0],M[i][1]);
    }
}

void afficher_relation(int M[][MAX_SIZE],int n){
    printf("A - B - A+B - A! - B! - A!*B! - A!*B! Mod (A + B) - Resultat\n");
    for(int i=0;i<n;i++){
        for(int j=0 ;j<7;j++){
            printf("%d -",M[i][j]);
        }
        if (pfr_verif(M[i][0],M[i][1])) printf("Premier\n");
        else printf("Pas Premier\n");
    }
}

int main(){
    int n = 5;
    int M[MAX_SIZE][MAX_SIZE];
    remplir_relations(M,n);
    afficher_relation(M,n);
    return 0;
}