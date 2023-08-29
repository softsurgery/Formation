epaisseur = 0.1
hauteur_burj = 828
pliages = 0

while epaisseur < hauteur_burj * 1000:
    epaisseur *= 2
    pliages += 1

print(f"Épaisseur initiale du papier : {epaisseur:.2f} mm")
print(f"Hauteur du Burj Khalifa : {hauteur_burj} m")
print(f"Nombre minimal de pliages nécessaires : {pliages}")
