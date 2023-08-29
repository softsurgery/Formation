<?php
$epaisseur = 0.1;
$hauteurBurj = 828;
$pliages = 0;

while ($epaisseur < $hauteurBurj * 1000) {
    $epaisseur *= 2;
    $pliages++;
}

echo "Épaisseur initiale du papier : " . number_format($epaisseur, 2) . " mm\n";
echo "Hauteur du Burj Khalifa : $hauteurBurj m\n";
echo "Nombre minimal de pliages nécessaires : $pliages\n";
?>
