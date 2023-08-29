public class Main {
    public static void main(String[] args) {
        double epaisseur = 0.1;
        int hauteurBurj = 828;
        int pliages = 0;

        while (epaisseur < hauteurBurj * 1000) {
            epaisseur *= 2;
            pliages++;
        }

        System.out.printf("Épaisseur initiale du papier : %.2f mm%n", epaisseur);
        System.out.println("Hauteur du Burj Khalifa : " + hauteurBurj + " m");
        System.out.println("Nombre minimal de pliages nécessaires : " + pliages);
    }
}
