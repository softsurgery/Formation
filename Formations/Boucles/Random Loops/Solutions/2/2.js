let epaisseur = 0.1;
let hauteurBurj = 828;
let pliages = 0;

while (epaisseur < hauteurBurj * 1000) {
    epaisseur *= 2;
    pliages++;
}

console.log(`Épaisseur initiale du papier : ${epaisseur.toFixed(2)} mm`);
console.log(`Hauteur du Burj Khalifa : ${hauteurBurj} m`);
console.log(`Nombre minimal de pliages nécessaires : ${pliages}`);
