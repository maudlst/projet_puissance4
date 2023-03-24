#include "boardGame.hpp"
#include "graphAI.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void doGame(GraphAI *graph, string mode)
{
    vector<string> lvEncounteredPositions;
    lvEncounteredPositions.reserve(cnSIZE_OF_BOARD * cnSIZE_OF_BOARD);
    vector<string>::iterator lnEncounteredIterator;
    lnEncounteredIterator = lvEncounteredPositions.begin();

    Node *lsActual = graph->getRoot(), *lsActualCpy;
    
    int lvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD] = {{0}};
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
                lnSelectedColomn = moveAtRandom(lvBoardGame);
            }
            else if (mode.compare("algo"))
            { 
                lnSelectedColomn = calculateBestMove(lvBoardGame);
            }
            lnSelectedColomn = calculateBestMove(lvBoardGame);
            tie(lbIsPlayed,lnRowPlayed) = play(lvBoardGame,lnSelectedColomn, lnCurrentPlayer); 
        }
        string lwTempString = lsActual->calculateNewPositionValue(lnSelectedColomn, lnMoveCounter);
        lsActual = graph->appendChildToParent(lsActual, lnSelectedColomn, move(lwTempString));
        lsActualCpy = lsActual;

        lnEncounteredIterator = lvEncounteredPositions.insert(lnEncounteredIterator , lsActual->getPositionName());
        
        gameDisplay(lvBoardGame);
        lnPositionStatus = whatGameStatus(lvBoardGame,lnCurrentPlayer);

        lnCurrentPlayer = (lnCurrentPlayer) % 2 + 1;
        
        lnMoveCounter++;

        cout << lvEncounteredPositions.size() << endl;
    }
    for (int i = 0; i < lvEncounteredPositions.size(); i++)
        cout << (new Node)->printPositionName(lvEncounteredPositions[i]) << endl;

    if (lnPositionStatus != gnStaleMate)
    {
        graph->calculateWeights(lvEncounteredPositions, false);

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
        exit(1);
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
        graph.deleteNodes();
        return 0;
    }
}
