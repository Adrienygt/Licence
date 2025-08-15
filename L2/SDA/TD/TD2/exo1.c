#include <stdio.h>
#include <stdlib.h>

typedef int item;

struct maillon{
    item valeur;
    struct maillon *suivant;
};

struct liste {
    struct maillon *premier;
    int longueur;
};


int maj_tab (int *tab, int n) {
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

int maj_tab2(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        int compteur = 1; 
        for (int j = i + 1; j < n; j++) { 
            if (tab[j] == tab[i]) {
                compteur++;
            }
        }
        if (compteur > n / 2) {
            return i;
        }
    }
    return -1; 
}

struct maillon* maj_list(struct liste* l) {
   struct maillon *current = l->premier;

   while(current!=NULL){
        struct maillon *temp = l->premier;
        int compteur;
        while(temp!=NULL){
            if(current->valeur== temp->valeur){
                compteur++;
            } 
            temp = temp->suivant;
        }
        if(compteur>l-> longueur /2){ 
            return current;
        }
        current=current->suivant;
   }
    
   return NULL;
}


int main(){

    int tab[5]={2,4,4,3,4};
    printf("%d",maj_tab(tab,5));
    printf("\n");
    printf("%d",maj_tab2(tab,5));

}