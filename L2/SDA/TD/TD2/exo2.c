#include <stdio.h>
#include <stdlib.h>


int maj_tab(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        int compteur = 0;
        for (int j = 0; j < n; j++) {
            if (tab[j] == tab[i])
                compteur++;
        }
        if (compteur > n / 2){
            return i;
        }
    }
    return -1; 

}




int maj_tab_bis(int *tab, int n) {
    // Cas de base : tableau vide ou de taille 1
    if (n == 0) return -1;
    if (n == 1) return 0; 

    // Partitionnement du tableau
    int milieu = n / 2;
    int gauche = maj_tab_bis(tab, milieu); // Appel récursif sur la première moitié
    int droite = maj_tab_bis(tab + milieu, n - milieu); // Appel récursif sur la seconde moitié

    // Vérification du candidat de la première moitié
    if (gauche != -1) {
        int val_gauche = tab[gauche];
        if (compter_occurrences(tab, 0, n - 1, val_gauche) > n / 2) {
            return gauche;
        }
    }

    // Vérification du candidat de la seconde moitié
    if (droite != -1) {
        int val_droite = tab[milieu + droite];
        if (compter_occurrences(tab, 0, n - 1, val_droite) > n / 2) {
            return milieu + droite;
        }
    }

    return -1;
}

int main() {
    int tab[] = {2, 4, 4, 3, 4};
    int n = 5;
    int resultat = maj_tab_bis(tab, n);
    printf("Indice de l'élément majoritaire : %d\n", resultat);
    return 0;
}