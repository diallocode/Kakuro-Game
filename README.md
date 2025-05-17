# Kakuro Solver - Projet C++

---

## Compilation
Pour compiler le projet, utilisez la commande suivante dans le terminal à la racine du projet :

```bash
make

---

## Exécution
Pour exécuter le programme, entrer la commande suivante :

```bash
./bin/kakuro

---

## Utilisation

1. Au lancement :
   - Choisissez le format (1 : texte / 2 : json).
   - Le programme charge automatiquement `Grille.txt` ou `Grille.json`.

2. Choix de difficulté :
   - Facile : temps illimité.
   - Moyen : 3 minutes.
   - Difficile : 2 minutes + 10 tentatives maximum.

3. Mode joueur :
   - Entrez les coordonnées (ligne, colonne) et la valeur (1-9, 0 pour effacer).
   - Quittez en entrant -1 à la ligne.

4. Résolution automatique :
   - Une fois le mode joueur terminé (ou si la grille est incorrecte), le programme propose une solution correcte calculée automatiquement.
   - Cela permet de comparer avec votre propre solution.




