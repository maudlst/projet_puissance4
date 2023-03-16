#include "boardGame.hpp"
#include "graphAI.hpp"
#include <stdio.h>
#include <iostream>


using namespace std;

int main() {

    GraphAI graph;

    // cout << Node::printPositionName(graph.getRoot().getPositionName()) << endl;
    Node &actual = graph.getRoot();
    graph.getGraphMap()["0000000000000000000000000"] = graph.getRoot();
    
    for(auto it = graph.getGraphMap().cbegin(); it != graph.getGraphMap().cend(); ++it)
    {
        std::cout << "COUCOU" << it->first << "\n";
    }
    

    int gvBoardGame[5][5] = {{0}};
    int gnCurrentPlayer, gnSelectedColomn, lnRowPlayed, gnMoveCounter;
    bool gbIsGameFinished, lbIsPlayed;

    //gameDisplay(gvBoardGame);
    gbIsGameFinished = false;
    gnCurrentPlayer = cnIA;
    lbIsPlayed = false;
    gnMoveCounter = 0;

    //gvBoardGame[0][1] = 1;
    //gvBoardGame[0][3] = 2;
    //gvBoardGame[1][1] = 1;
    //gvBoardGame[0][2] = 2;

    gameDisplay(gvBoardGame);
    //cout << calculateBestMove(gvBoardGame) << endl;
    while(!gbIsGameFinished)
    {
        if(gnCurrentPlayer == cnIA)
        {
            cout << "C'est le tour de l'IA " << endl;
            while (!lbIsPlayed)
            {
                gnSelectedColomn = calculateBestMove(gvBoardGame);
                tie(lbIsPlayed,lnRowPlayed) = play(gvBoardGame,gnSelectedColomn, gnCurrentPlayer); 
            }
            lbIsPlayed = false;
            string s = actual.calculateNewPositionValue(gnSelectedColomn, gnMoveCounter);
            actual = graph.appendChildToParent(actual, gnSelectedColomn, s);
            gameDisplay(gvBoardGame);
            gbIsGameFinished = isGameFinished(gvBoardGame,gnCurrentPlayer);

            gnCurrentPlayer = cnPLAYER;
        }
        else 
        {
            cout << "C est votre tour "  << endl;
            
            while (!lbIsPlayed)
            {
                cout << "Sur quelle colonne voulez vous jouez (0 à 4)"<< endl;
                cin >> gnSelectedColomn;
                gnSelectedColomn = gnSelectedColomn % 5;
                tie(lbIsPlayed,lnRowPlayed) = play(gvBoardGame,gnSelectedColomn,gnCurrentPlayer);
                if (!lbIsPlayed)
                    cout << "Colonne Pleine !" << endl;
            }
            lbIsPlayed = false;
            actual = graph.appendChildToParent(actual, gnSelectedColomn, actual.calculateNewPositionValue(gnSelectedColomn, gnMoveCounter));
            gameDisplay(gvBoardGame);
            gbIsGameFinished = isGameFinished(gvBoardGame,gnCurrentPlayer);

            gnCurrentPlayer = cnIA; 
        }
        gnMoveCounter++;
    }

    if(gnCurrentPlayer == cnIA)
    {
        cout << "Vous avez gagné " << endl;
    }
    else
    {
        cout << "Le gagnant est l'IA  " << endl;
    }
    cout << "APRES LEARNING" << endl;
    for(auto it = graph.getGraphMap().cbegin(); it != graph.getGraphMap().cend(); ++it)
    {
        std::cout << it->first << "\n";
    }
    

    return 0;
}