#include "boardGame.hpp"
#include "graphAI.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void calculateWeights(vector <Node*> pvEncounteredNodes, bool pbStaleFinish)
{
  weight_t lsWeights;
  int lnTailleEncounteredNode = pvEncounteredNodes.size(), lnIterator = 0;

  for(Node* lsCurentNode : pvEncounteredNodes)
  {
    lsWeights = lsCurentNode->getWeight();
    lsWeights.mnGamePlayed += 1;
    if(!pbStaleFinish && (lnTailleEncounteredNode - lnIterator) % 2 == 1)
    {
      lsWeights.mnGameWon += 1;
    }
    lsWeights.mnVictoryRate = (lsWeights.mnGameWon / lsWeights.mnGamePlayed) * 100;
    lsCurentNode->setWeight(lsWeights.mnGamePlayed, lsWeights.mnGameWon, lsWeights.mnVictoryRate);
    lnIterator++;
  }
}

int main() {

    GraphAI graph;
    vector<Node*> gvEncounteredNodes;

    Node *actual = graph.getRoot();
    
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
            string lwTempString = actual->calculateNewPositionValue(gnSelectedColomn, gnMoveCounter);
            actual = graph.appendChildToParent(actual, gnSelectedColomn, move(lwTempString));
            gvEncounteredNodes.push_back(actual);
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
            string lwTempString = actual->calculateNewPositionValue(gnSelectedColomn, gnMoveCounter);
            actual = graph.appendChildToParent(actual, gnSelectedColomn, move(lwTempString)); 
            gvEncounteredNodes.push_back(actual);
            gameDisplay(gvBoardGame);
            gbIsGameFinished = isGameFinished(gvBoardGame,gnCurrentPlayer);

            gnCurrentPlayer = cnIA; 
        }
        gnMoveCounter++;
    }

    calculateWeights(gvEncounteredNodes, false);
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
    
    //graph.getGraphMap()["0000000000000000000000000"] = *(graph.getRoot());
    graph.exportToFile();


    return 0;
}
