//fonction d'ackerman

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct etudiant_ {
    char* nom;
    char* promotion;
    int notes[10];
} etudiant;

int calculerMoyenne(etudiant monEtudiant) {
    int i;
    float moyenne = 0.0;

    for(i=0; i<10; i++) {
        moyenne += monEtudiant.notes[i];
    }
    moyenne = moyenne/i;
    return moyenne;
}

etudiant initialiserNotesEtudiant(etudiant unEtudiant) {
    for(int i=0; i<10; i++) {
        unEtudiant.notes[i] = rand() % 20;
    }
    return unEtudiant;
}

int main(int argc, char* argv[]){
    float moyenneClasse;
    srand(time(NULL));
    etudiant unEtudiant[30];
    //Initialisation des notes pour chaque etudiants
    for(int i=0; i<30; i++) {
        unEtudiant[i] = initialiserNotesEtudiant(unEtudiant[i]);
    }
    //Calcul de la moyenne de classe
    for(int i=0; i<30; i++) {
        moyenneClasse += calculerMoyenne(unEtudiant[i]);
    }
    moyenneClasse = moyenneClasse/30;
    printf("La moyenne de la classe est : %f\n", moyenneClasse);
    return 0;
}
