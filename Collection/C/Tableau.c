#include <stdio.h>
#define MAX_SIZE 100
#include <unistd.h>
#include <termios.h>

char getch(void)
{
    printf("Press Any To Continue...");
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    
    return buf;
 }

void saisir_tab(int T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("T[%d]=", i);
        scanf("%d", T + i);
    }
}

void afficher_tab(int T[], int n)
{
    for (int i = 0; i < n; i++)
        printf("T[%d]=%d\t", i, T[i]);
    printf("\n");
}

int recherche_tab(int T[], int n, int val)
{
    int i = 0;
    while (i < n && T[i] != val)
        i++;
    return i < n ? i : -1;
}

void ajout_fin(int T[], int *pn, int val)
{
    T[*pn] = val;
    (*pn)++;
}

void ajout_debut(int T[], int *pn, int val)
{
    for (int i = *pn; i > 0; i--)
        T[i] = T[i - 1];
    T[0] = val;
    (*pn)++;
}

void ajout_pos(int T[], int *pn, int val, int pos)
{
    for (int i = *pn; i > pos; i--)
        T[i] = T[i - 1];
    T[pos] = val;
    (*pn)++;
}

void supprimer_fin(int T[], int *pn)
{
    T[*pn] = 0;
    (*pn)--;
}

void supprimer_debut(int T[], int *pn)
{
    for (int i = 0; i < *pn - 1; i++)
        T[i] = T[i + 1];
    (*pn)--;
}

void supprimer_pos(int T[], int *pn, int pos)
{
    for (int i = pos; i < *pn - 1; i++)
        T[i] = T[i + 1];
    (*pn)--;
}

void inverser(int T[], int n)
{
    int aux;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        aux = T[i];
        T[i] = T[j];
        T[j] = aux;
    }
}

void permutation(int *pa, int *pb)
{
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}

void menu()
{
    printf("01. Saisir Tableau\n");
    printf("02. Afficher Tableau\n");
    printf("03. Rechercher dans le tableau\n");
    printf("04. Ajouter Debut\n");
    printf("05. Ajouter à une position donnée\n");
    printf("06. Ajouter Fin\n");
    printf("07. Supprimer Debut\n");
    printf("08. Supprimer à une position donnée\n");
    printf("09. Supprimer Fin\n");
    printf("10. Inverser Tableu\n");
    printf("11. Quitter\n");
}

int main()
{
    int T[MAX_SIZE];
    int n=0;
    int choix,val,pos,res;
    do
    {
        system("clear");
        menu();
        printf("Quelle est votre choix ?\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            do {
                printf("N = ");
                scanf("%d",&n);
            }while(!(n>=1 && n <= MAX_SIZE));
            saisir_tab(T,n);
            break;
        case 2:
            if(n==0) printf("Tableau Vide\n");
            else{
                afficher_tab(T,n);
                getch();
            }
            break;
        case 3:
            printf("Val = ? ");
            scanf("%d",&val);
            res = recherche_tab(T,n,val);
            if (res!=-1) printf("%d se trouve a la position %d\n",val,res);
            else printf("%d ne se trouve pas dans le tableau\n",val);
            getch();
            break;
        case 4:
            printf("Val = ? ");
            scanf("%d",&val);
            ajout_debut(T,&n,val);
            break;
        case 5:
            printf("Val = ? ");
            scanf("%d",&val);
            do{
                printf("Pos = ? ");
                scanf("%d",&pos);
            }while(!(pos>=0 && pos<=n));
            ajout_pos(T,&n,val,pos);
            break;
        case 6:
            printf("Val = ? ");
            scanf("%d",&val);
            ajout_fin(T,&n,val);
            break;
        case 7:
            if(n==0) printf("Tableau est deja vide\n");
            else supprimer_debut(T,&n);
            break;
        case 8:
            if(n==0) printf("Tableau est deja vide\n");
            else{
                do{
                    printf("Pos = ? ");
                    scanf("%d",&pos);
                }while(!(pos>=0 && pos<=n));
                supprimer_pos(T,&n,pos);
            } 
            break;
        case 9:
            if(n==0) printf("Tableau est deja vide\n");
            else supprimer_fin(T,&n);
            break;
        case 10:
            if(n!=0) inverser(T,n);
            else printf("Tableau est vide\n");
            break;
        case 11:
            break;
        
        default:
            printf("choix invalide");
            break;
        }
    } while (choix!=11); 
    return 0;
}