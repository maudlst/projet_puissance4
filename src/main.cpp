#include "boardGame.hpp"
#include <stdio.h>
#include <iostream>


using namespace std;

int main(){

    int gvBoardGame[5][5];
    int giRow, giColomn, gnCurrentPlayer, gnSelectedColomn;
    bool gbIsGameFinished;
    

    for (giRow =0; giRow <5; giRow++)
    {
        for( giColomn =0; giColomn <5; giColomn++)
        {
            gvBoardGame[giRow][giColomn] = 0 ;
        }
    }

    gameDisplay(gvBoardGame);
    gbIsGameFinished =false;
    gnCurrentPlayer = cnIA;

    while(!gbIsGameFinished)
    {
        cout << "C est le tour du joueur " << gnCurrentPlayer << endl;
        cout << "Sur quelle colonne voulez vous jouez (0 à 4)"<< endl;
        cin >> gnSelectedColomn;
        gnSelectedColomn = gnSelectedColomn % 5;

        play(gvBoardGame,gnSelectedColomn,gnCurrentPlayer);
        gameDisplay(gvBoardGame);
        gbIsGameFinished = isGameFinished(gvBoardGame,gnCurrentPlayer);

        if(gnCurrentPlayer == cnIA)
        {
            gnCurrentPlayer = cnPLAYER;
        }
        else 
        {
            gnCurrentPlayer = cnIA;
        }
    }

    if(gnCurrentPlayer == cnIA)
    {
        cout << "Le gagnant est le joueur "<< cnPLAYER << endl;
    }
    else 
    {
        cout << "Le gagnant est le joueur " << cnIA << endl;
    }

    return 0;
}