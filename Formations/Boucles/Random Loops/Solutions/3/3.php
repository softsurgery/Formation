<?php
$score = 0;

for ($i = 0; $i < 10; $i++) {
    $a = rand(1, 10);
    $b = rand(1, 10);
    $rep = $a * $b;

    echo "$a x $b = ";
    $sugg = intval(readline());

    if ($rep === $sugg) {
        $score++;
    } else {
        $score--;
    }
}

echo "Your Score = $score\n";
?>
