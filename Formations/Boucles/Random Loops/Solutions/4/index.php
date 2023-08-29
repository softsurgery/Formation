<?php
$cible = rand(0, 100);
$proposition = -1;
$essais = 0;

while ($proposition !== $cible) {
    $proposition = readline("Proposez une valeur : ");
    $essais++;

    if ($proposition < $cible) {
        echo "Trop petit.\n";
    } elseif ($proposition > $cible) {
        echo "Trop grand.\n";
    } else {
        echo "Bravo, vous avez trouvé le nombre en $essais coup(s).\n";
    }
}

echo "En $essais coups, vous êtes sûr(e) de trouver.\n";
?>
