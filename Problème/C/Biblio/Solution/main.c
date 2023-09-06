#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char* titre;
    float prix;
} Livre;

//variable globale
char buffer[256];

void remplirLivre(Livre* l){
    //id
    do{
        puts("ID =");
        scanf("%d",&l->id);
    }while(l->id<=0);

    //titre
    puts("Titre =");
    gets(buffer);
    l->titre= (char*)malloc(strlen(buffer) + 1);
    strcpy(l->titre,buffer);

    //prix
    do{
        puts("Prix =");
        scanf("%d",&l->prix);
    }while(l->prix<=0);
}

int duplicateLivre(Livre Bib[],int n,Livre l){
    int i=0;
    while(i<n && Bib[i].id!=l->id) i++;
    return i<n;
}

void remplirBib(Livre Bib[], int n){
    puts("Le 1er Livre :");
    remplirLivre(Bib[0]);
    for(int i = 1; i < n;i++){
        do{
             printf("Le %deme Livre :",i+1);
             remplirLivre(Bib[i]);
        } while(duplicateLivre(Bib,i,Bib[i])==true);
    }
}

void afficheLivre(Livre l){
    printf("ID = %d",l.id);
    printf("Titre = %s",l.titre);
    printf("Prix = %.2f",l.prix);
}

void afficheBib(Livre Bib[],int n){
    for(int i=0;i<n;i++){
        printf("Livre N°%d",i+1);
        afficheLivre(Bib[i]);
    }
}

int existeLivre(Livre Bib[],int n,const char* titre){
    int i=0;
    while(i<n && Bib[i].id!=l->id) i++;
    return (i<n) ? i : -1;
}

int nbLivresChers(Livre Bib[],int n){
    int s = 0;
    for(int i=0;i<n;i++) if (Bib[i].prix>100) s++;
    return s;
}

int nbLivresChersRv(Livre Bib[],int n){
    if (n==0) return 0;
    else {
        if (Bib[n-1].prix>100) return 1 + nbLivresChersRv(Bib,n-1);
        else return nbLivresChersRv(Bib,n-1);
    }
}

int main(){

    return 0;
}