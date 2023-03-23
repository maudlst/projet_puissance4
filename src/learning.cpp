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

void doGame(GraphAI *graph, string mode)
{
    vector<Node*> gvEncounteredNodes;
    Node *actual = graph->getRoot();
    
    int lvBoardGame[5][5] = {{0}};
    int lnCurrentPlayer, lnSelectedColomn, lnRowPlayed, lnMoveCounter;
    gameStatus lnPositionStatus;
    bool lbIsPlayed;


    //gameDisplay(lvBoardGame);
    lnPositionStatus = gnGameNotFinished;
    lnCurrentPlayer = cnIA;
    lnMoveCounter = 0;
    
    gameDisplay(lvBoardGame);
    //cout << calculateBestMove(lvBoardGame) << endl;
    while(lnPositionStatus == gnGameNotFinished)
    {
        lbIsPlayed = false;
        while (!lbIsPlayed)
        {
            if(mode.compare("rand")) 
            {
                // 
            }
            else if (mode.compare("algo"))
            { 
                lnSelectedColomn = calculateBestMove(lvBoardGame);
            }
            lnSelectedColomn = calculateBestMove(lvBoardGame);
            tie(lbIsPlayed,lnRowPlayed) = play(lvBoardGame,lnSelectedColomn, lnCurrentPlayer); 
        }
        string lwTempString = actual->calculateNewPositionValue(lnSelectedColomn, lnMoveCounter);
        actual = graph->appendChildToParent(actual, lnSelectedColomn, move(lwTempString));
        gvEncounteredNodes.push_back(actual);
        gameDisplay(lvBoardGame);
        lnPositionStatus = whatGameStatus(lvBoardGame,lnCurrentPlayer);

        lnCurrentPlayer = (lnCurrentPlayer) % 2 + 1;
        
        lnMoveCounter++;
    }

    if (lnPositionStatus != gnStaleMate)
    {
        calculateWeights(gvEncounteredNodes, false);

        if(lnCurrentPlayer == cnIA)
        {
            cout << "Vous avez gagné  " << endl;
        }
        else
        {
            cout << "Le gagnant est l'IA  " << endl;
        }
    }
    else 
    {
        cout << "Le Match est ex aequo  " << endl;
    }

}

int main(int argc, char **argv) // nb_parties, mode
{
    if (argc != 3)
    {
        printf("Erreur nombre d'arguments invalide.\nUtilisation : ./<executable> <nb_parties> <mode>\n");
    }
    else 
    {
        int lnNbReps = atoi(argv[1]);
        string mode(argv[1]);
        GraphAI graph;
        for (int i = 0 ; i < lnNbReps; i++)
        {
            doGame(&graph, mode);
        }

        cout << endl << "Graph1 export" << endl;
        graph.exportToFile();

        return 0;
    }
}
