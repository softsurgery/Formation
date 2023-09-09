#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024


typedef struct{
    char* nom;
    char* prenom;
    int rdv;
} Patient;

typedef struct cellule{
    Patient p;
    struct cellule* suivant;
} Cellule;

typedef Cellule* LC;

char buffer[MAX_SIZE];

void saisirPatient(Patient *p);
void afficherPatient(Patient p);
void enregistrerPatient(Patient p, char *chemin);
void lireDernierPatient(Patient *p,char *chemin);

LC AjoutPatient ( LC tete, Patient p );
void RendezVous ( LC tete, int *rdv, int *sansRdv );
LC SupprimePatient ( LC tete );

int main(){
    return 0;
}

void saisirPatient(Patient *p){
    do{
        printf("Nom = ");
        gets(buffer);
    }while(strlen(buffer)<3);
    p->nom = (char*) malloc(strlen(buffer)+1);
    strcpy(p->nom, buffer);

    do{
        printf("Prenom = ");
        gets(buffer);
    }while(strlen(buffer)<3);
    p->prenom = (char*) malloc(strlen(buffer)+1);
    strcpy(p->prenom, buffer);

    do{
        printf("Avez-vous un rendez-vous ?\n");
        scanf("%d",&p->rdv);
    } while(p->rdv!=0 && p->rdv!=1);
}

void afficherPatient(Patient p){
    printf("Nom : %s",p.nom);
    printf("Prenom : %s",p.prenom);
    (p.rdv==1) 
    ? printf("Ce Patient a un rendez-vous\n") 
    : printf("Ce Patient n'a pas un rendez-vous\n");
}

void enregistrerPatient(Patient p,const char *chemin){
    FILE* fp = fopen(chemin,"a");
    if (fp==NULL) fp = fopen(chemin,"w");
    if (fp==NULL) printf("Impossible d'ouvrir %s",chemin);
    else {
        fprintf(f,"%s\n%s\n%d\n",p.nom,p.prenom,p.rdv);
        fclose(fp);
    }
}

LC AjoutPatient ( LC tete, Patient p ){
    Cellule* nouveau = (Cellule*) malloc(sizeof(Cellule));
    nouveau->p = p;
    nouveau->suivant = tete;
    return nouveau;
}

void RendezVous ( LC tete, int *rdv, int *sansRdv ){
    *rdv = 0;
    *sansRdv = 0;
    while(tete!=NULL){
        (tete->p.rdv) ? (*rdv)++ : (*sansRdv)++;
        tete = tete->suivant;
    }
}

LC SupprimePatient ( LC tete ){
    int rdv, sansRdv;
    RendezVous (tete,&rdv,&sansRdv);
    if (rdv == 0 || tete->p.rdv) return tete->suivant;
    else {
        Cellule* parc = tete,*current = tete->suivant;
        while(current->p.rdv==0) {
            parc = parc->suivant;
            current = current->suivant;
        }
        parc = current->suivant;
        free(current);
        return tete;
    }
}