#include "../include/bruteForceSolver.h"


bool isValid(Grille& g, int row, int col) {
    // ----- Vérification HORIZONTALE -----
    int i = row, j = col;
    int currentSum = 0;
    int targetSum = -1;
    int emptyCount = 0;
    std::set<int> used;

    // Trouver la cellule de somme vers la droite
    while (j >= 0) {
        Cells* c = g.getCell(i, j);
        Cell_sum* sumCell = dynamic_cast<Cell_sum*>(c);
        if (sumCell && sumCell->getsumHorizontale() >= 0) {
            targetSum = sumCell->getsumHorizontale();
            break;
        }
        --j;
    }

    j++;
    while (j < g.getCols()) {
        Cells* c = g.getCell(i, j);
        Cell_vide* cell = dynamic_cast<Cell_vide*>(c);
        if (!cell) break;

        int val = cell->getValue();
        if (val != 0) {
            if (used.count(val)) return false; // doublon
            used.insert(val);
            currentSum += val;
        } else {
            emptyCount++;
        }
        ++j;
    }

    if (targetSum != -1) {
        if (emptyCount == 0 && currentSum != targetSum)
            return false; // bloc complet mais mauvaise somme
        if (emptyCount > 0 && currentSum >= targetSum)
            return false; // partiel mais déjà trop grand
    }

    // ----- Vérification VERTICALE -----
    i = row;
    j = col;
    currentSum = 0;
    targetSum = -1;
    emptyCount = 0;
    used.clear();

    // Trouver la cellule de somme vers le bas
    while (i >= 0) {
        Cells* c = g.getCell(i, j);
        Cell_sum* sumCell = dynamic_cast<Cell_sum*>(c);
        if (sumCell && sumCell->getSumVerticale() >= 0) {
            targetSum = sumCell->getSumVerticale();
            break;
        }
        --i;
    }

    i++;
    while (i < g.getRows()) {
        Cells* c = g.getCell(i, j);
        Cell_vide* cell = dynamic_cast<Cell_vide*>(c);
        if (!cell) break;

        int val = cell->getValue();
        if (val != 0) {
            if (used.count(val)) return false;
            used.insert(val);
            currentSum += val;
        } else {
            emptyCount++;
        }
        ++i;
    }

    if (targetSum != -1) {
        if (emptyCount == 0 && currentSum != targetSum)
            return false;
        if (emptyCount > 0 && currentSum >= targetSum)
            return false;
    }

    return true;
}

bool bruteForceSolver::solution(Grille& g) {
    for (int i = 0; i < g.getRows(); ++i) {
        for (int j = 0; j < g.getCols(); ++j) {
            Cells* cell = g.getCell(i, j);
            Cell_vide* empty = dynamic_cast<Cell_vide*>(cell);

            if (empty && empty->getValue() == 0) {
                for (int val = 1; val <= 9; ++val) {
                    empty->setValue(val);

                    if (isValid(g, i, j)) { // tu peux activer ça après
                        if (solution(g)) {
                            return true;
                        }
                    }

                    empty->setValue(0); // backtrack
                }
                return false;
            }
        }
    }

    return true; // tout est rempli
}
