# Kakuro Solver - Projet C++


## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal à la racine du projet :


`make`


---

## Exécution
Pour exécuter le programme, entrer la commande suivante :

`./bin/kakuro`

---


## Utilisation

1. **Choix du format de la grille** :
   - 1 → Fichier texte (`Grille.txt`)
   - 2 → Fichier JSON (`Grille.json`)
   - Le programme charge automatiquement le bon fichier selon l’extension.

2. **Sélection de la difficulté** :
   - Facile : temps illimité.
   - Moyen : 3 minutes.
   - Difficile : 2 minutes + 10 tentatives maximum.

3. **Mode joueur** :
   - Entrez les coordonnées (ligne, colonne) et la valeur (1-9, ou 0 pour effacer).
   - Entrez `-1` pour quitter le mode joueur.

4. **Résolution automatique** :
   - À la fin du jeu, ou si la grille est incorrecte, une solution est automatiquement proposée par le solver.

---



