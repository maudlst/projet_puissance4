#include "plateau.hpp"
#include <stdio.h>
#include <iostream>

#define JOUEUR1 1
#define JOUEUR2 2

using namespace std;

int main(){

    int plateau[5][5];
    int ligne, colonne, joueurCourant, colonneChoisie;
    bool estFiniJeu;

    for (ligne =0; ligne <5; ligne++)
    {
        for( colonne =0; colonne <5; colonne++)
        {
            plateau[ligne][colonne] = 0 ;
        }
    }

    afficheJeu(plateau);
    estFiniJeu =false;
    joueurCourant = JOUEUR1;

    while(!estFiniJeu){
        cout << "C est le tour du joueur " << joueurCourant << endl;
        cout << "Sur quelle colonne voulez vous jouez (0 à 4)"<< endl;
        cin >> colonneChoisie;
        colonneChoisie = colonneChoisie % 5;

        jouer(plateau,colonneChoisie,joueurCourant);
        afficheJeu(plateau);
        estFiniJeu = jeuFini(plateau,joueurCourant);

        if(joueurCourant == JOUEUR1)
        {
            joueurCourant = JOUEUR2;
        }
        else 
        {
            joueurCourant = JOUEUR1;
        }
    }

    if(joueurCourant == JOUEUR1)
    {
        cout << "Le gagnant est le joueur "<< JOUEUR2 << endl;
    }
    else 
    {
        cout << "Le gagnant est le joueur " << JOUEUR1 << endl;
    }
    /*
    jouer(plateau,1,JOUEUR2);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR1);
    
    jouer(plateau,2,JOUEUR1);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);
    
    jouer(plateau,4,JOUEUR2);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);
    
    jouer(plateau,3,JOUEUR1);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);
    
    jouer(plateau,0,JOUEUR1);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);
    
    jouer(plateau,2,JOUEUR2);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);
    
    jouer(plateau,2,JOUEUR2);
    afficheJeu(plateau);
    jeuFini(plateau,JOUEUR2);

*/




    return 0;
}