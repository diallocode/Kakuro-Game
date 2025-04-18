#include "FilteredSolver.h"
#include "Cell_vide.h"
#include "Cell_sum.h"
#include <set>
#include <iostream>
#include <algorithm>

bool FilteredSolver::solution(Grille& g) {
    // Réinitialiser toutes les cellules vides avant de commencer
    for (int i = 0; i < g.getRows(); ++i) {
        for (int j = 0; j < g.getCols(); ++j) {
            if (Cell_vide* cv = dynamic_cast<Cell_vide*>(g.getCell(i, j))) {
                cv->setValue(0);
            }
        }
    }
    return solveKakuro(g, 0, 0);
}

bool FilteredSolver::solveKakuro(Grille& g, int row, int col) {
    // Si on a parcouru toute la grille
    if (row >= g.getRows()) return true;
    
    // Si on dépasse les colonnes, passer à la ligne suivante
    if (col >= g.getCols()) return solveKakuro(g, row + 1, 0);

    Cell_vide* cell = dynamic_cast<Cell_vide*>(g.getCell(row, col));
    if (!cell) return solveKakuro(g, row, col + 1); // Case non éditable

    // Essayer les nombres de 1 à 9
    for (int num = 1; num <= 9; ++num) {
        if (isValid(g, row, col, num)) {
            cell->setValue(num);
            
            // Trouver la prochaine case vide
            int nextRow = row;
            int nextCol = col + 1;
            bool found = false;
            while (nextRow < g.getRows() && !found) {
                while (nextCol < g.getCols()) {
                    if (dynamic_cast<Cell_vide*>(g.getCell(nextRow, nextCol))) {
                        found = true;
                        break;
                    }
                    nextCol++;
                }
                if (!found) {
                    nextRow++;
                    nextCol = 0;
                }
            }

            if (solveKakuro(g, nextRow, nextCol)) {
                return true;
            }
            
            // Backtrack
            cell->setValue(0);
        }
    }
    
    return false;
}

bool FilteredSolver::isValid(Grille& g, int row, int col, int num) {
    // Vérification des doublons et sommes horizontales
    if (!checkHorizontal(g, row, col, num)) return false;
    
    // Vérification des doublons et sommes verticales
    if (!checkVertical(g, row, col, num)) return false;
    
    return true;
}

bool FilteredSolver::checkHorizontal(Grille& g, int row, int col, int num) {
    int startCol = col;
    int endCol = col;
    
    // Trouver le début de la séquence
    while (startCol > 0) {
        if (!dynamic_cast<Cell_vide*>(g.getCell(row, startCol - 1))) break;
        startCol--;
    }
    
    // Trouver la fin de la séquence
    while (endCol < g.getCols() - 1) {
        if (!dynamic_cast<Cell_vide*>(g.getCell(row, endCol + 1))) break;
        endCol++;
    }
    
    // Vérifier les doublons et calculer la somme
    std::set<int> used;
    int sum = 0;
    bool hasEmpty = false;
    
    for (int j = startCol; j <= endCol; ++j) {
        Cell_vide* cv = dynamic_cast<Cell_vide*>(g.getCell(row, j));
        if (!cv) continue;
        
        int val = (j == col) ? num : cv->getValue();
        if (val == 0) {
            hasEmpty = true;
        } else {
            if (used.count(val)) return false;
            used.insert(val);
            sum += val;
        }
    }
    
    // Trouver la somme cible
    int target = -1;
    for (int j = startCol - 1; j >= 0; --j) {
        Cell_sum* cs = dynamic_cast<Cell_sum*>(g.getCell(row, j));
        if (cs && cs->getsumHorizontale() >= 0) {
            target = cs->getsumHorizontale();
            break;
        }
    }
    
    if (target != -1) {
        if (sum > target) return false;
        if (!hasEmpty && sum != target) return false;
    }
    
    return true;
}

bool FilteredSolver::checkVertical(Grille& g, int row, int col, int num) {
    int startRow = row;
    int endRow = row;
    
    // Trouver le début de la séquence
    while (startRow > 0) {
        if (!dynamic_cast<Cell_vide*>(g.getCell(startRow - 1, col))) break;
        startRow--;
    }
    
    // Trouver la fin de la séquence
    while (endRow < g.getRows() - 1) {
        if (!dynamic_cast<Cell_vide*>(g.getCell(endRow + 1, col))) break;
        endRow++;
    }
    
    // Vérifier les doublons et calculer la somme
    std::set<int> used;
    int sum = 0;
    bool hasEmpty = false;
    
    for (int i = startRow; i <= endRow; ++i) {
        Cell_vide* cv = dynamic_cast<Cell_vide*>(g.getCell(i, col));
        if (!cv) continue;
        
        int val = (i == row) ? num : cv->getValue();
        if (val == 0) {
            hasEmpty = true;
        } else {
            if (used.count(val)) return false;
            used.insert(val);
            sum += val;
        }
    }
    
    // Trouver la somme cible
    int target = -1;
    for (int i = startRow - 1; i >= 0; --i) {
        Cell_sum* cs = dynamic_cast<Cell_sum*>(g.getCell(i, col));
        if (cs && cs->getSumVerticale() >= 0) {
            target = cs->getSumVerticale();
            break;
        }
    }
    
    if (target != -1) {
        if (sum > target) return false;
        if (!hasEmpty && sum != target) return false;
    }
    
    return true;
}