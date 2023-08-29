#include <stdio.h>

int main() {
    double epaisseur = 0.1;
    int hauteur_burj = 828;
    int pliages = 0;

    while (epaisseur < hauteur_burj * 1000) {
        epaisseur *= 2;
        pliages++;
    }

    printf("Épaisseur initiale du papier : %.2f mm\n", epaisseur);
    printf("Hauteur du Burj Khalifa : %d m\n", hauteur_burj);
    printf("Nombre minimal de pliages nécessaires : %d\n", pliages);

    return 0;
}
