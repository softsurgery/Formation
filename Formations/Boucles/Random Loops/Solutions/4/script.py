import random

nombre_cible = random.randint(0, 100)
proposition_utilisateur = -1
essais = 0

while proposition_utilisateur != nombre_cible:
    proposition_utilisateur = int(input("Proposez une valeur : "))
    essais += 1

    if proposition_utilisateur < nombre_cible:
        print("Trop petit.")
    elif proposition_utilisateur > nombre_cible:
        print("Trop grand.")
    else:
        print("Bravo, vous avez trouvé le nombre en", essais, "coup(s).")

print("En", essais, "coups, vous êtes sûr(e) de trouver.")
