#include "boardGame.hpp"


using namespace std;

void gameDisplay( int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD])
{
    int liColomn, liRow ;

    for (liRow = cnSIZE_OF_BOARD - 1; liRow >=0 ; liRow --)
    {
        cout << "\t| ";
        for(liColomn = 0; liColomn <cnSIZE_OF_BOARD ; liColomn ++)
        {
            cout << pvBoardGame[liRow][liColomn] << " | ";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}


tuple <bool, int> play(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnColomnToPlay, int pnPlayer)
{
    bool lbPlayed, lbIsLoopFinished;
    int lnBoxBoard, liIndexRow ;

    lbPlayed = false;
    lbIsLoopFinished = false;
    liIndexRow = 0;
      
    while(!lbIsLoopFinished  && liIndexRow < cnSIZE_OF_BOARD)
    {
        lnBoxBoard = pvBoardGame[liIndexRow][pnColomnToPlay];  
        if(lnBoxBoard == 0)
        {
            pvBoardGame[liIndexRow][pnColomnToPlay] = pnPlayer;
            lbPlayed = true;
            lbIsLoopFinished = true;
        }
        else 
        {
            liIndexRow++;
        }
    }

    return make_tuple(lbPlayed, liIndexRow);
}


bool isGameFinished(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer)
{
    bool lbIsFinished;

    if (isHorizontalAlignment(pvBoardGame,pnPlayer))
    {
        lbIsFinished = true;
        cout << "partie gagnée" << endl;
    }
    else if(isVerticalAlignment(pvBoardGame,pnPlayer))
    {
        lbIsFinished = true;
        cout << "partie gagnée" << endl;
    }
    else if (isDiagonalAlignmentTLBR(pvBoardGame,pnPlayer))
    {
        lbIsFinished = true;
        cout << "partie gagnée" << endl;
    }
    else if (isDiagonalAlignmentTRBL(pvBoardGame,pnPlayer))
    {
        lbIsFinished = true;
        cout << "partie gagnée" << endl;
    }
    else 
    {
        lbIsFinished = false;
    }
    return lbIsFinished;
}


bool isVerticalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer)
{
    bool lbIsAlignment;
    int liIndexColomn;

    lbIsAlignment = false;

    for (liIndexColomn =0 ; liIndexColomn < cnSIZE_OF_BOARD; liIndexColomn++)
    {
        if(pvBoardGame[1][liIndexColomn]== pnPlayer)
        {
            if(pvBoardGame[2][liIndexColomn]== pnPlayer && pvBoardGame[3][liIndexColomn]== pnPlayer) // 3 pions alignés
            {
                if(pvBoardGame[0][liIndexColomn]== pnPlayer || pvBoardGame[4][liIndexColomn]== pnPlayer) // 4 pions alignés
                {
                    lbIsAlignment = true;
                }
            }
        }
    }
    return lbIsAlignment;
}

bool isHorizontalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer)
{
    bool lbIsAlignment;
    int liIndexRow;

    lbIsAlignment = false;

    for (liIndexRow =0 ; liIndexRow < cnSIZE_OF_BOARD; liIndexRow++)
    {
        if(pvBoardGame[liIndexRow][1]== pnPlayer)
        {
            if(pvBoardGame[liIndexRow][2]== pnPlayer && pvBoardGame[liIndexRow][3]== pnPlayer) // 3 pions alignés
            {
                if(pvBoardGame[liIndexRow][0]== pnPlayer || pvBoardGame[liIndexRow][4]== pnPlayer) // 4 pions alignés
                {
                    lbIsAlignment = true;
                }
            }
        }
    }
    return lbIsAlignment;
}

bool isDiagonalAlignmentTRBL(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer)//Diagonale le Bas à Gauche et le Haut à Droite
{
    bool lbIsAlignment;

    lbIsAlignment = false;

    if (pvBoardGame[2][2]== pnPlayer)
    {
        if(pvBoardGame[1][1]== pnPlayer && pvBoardGame[3][3]== pnPlayer) // 3 pions alignés
        {
            if(pvBoardGame[0][0]== pnPlayer || pvBoardGame[4][4]== pnPlayer) // 4 pions alignés
            {
                lbIsAlignment = true;
            }
        }
    }
    else if (pvBoardGame[1][0]== pnPlayer && pvBoardGame[2][1]== pnPlayer && pvBoardGame[3][2]== pnPlayer && pvBoardGame[4][3]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    else if (pvBoardGame[0][1]== pnPlayer && pvBoardGame[1][2]== pnPlayer && pvBoardGame[2][3]== pnPlayer && pvBoardGame[3][4]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    return lbIsAlignment;
}

bool isDiagonalAlignmentTLBR(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer)//Diagonale le Bas à Droite et le Haut à Gauche
{
    bool lbIsAlignment;

    lbIsAlignment = false;

    if (pvBoardGame[2][2]== pnPlayer)
    {
        if(pvBoardGame[3][1]== pnPlayer && pvBoardGame[1][3]== pnPlayer) // 3 pions alignés
        {
            if(pvBoardGame[0][4]== pnPlayer || pvBoardGame[4][0]== pnPlayer) // 4 pions alignés
            {
                lbIsAlignment = true;
            }
        }
    }
    else if (pvBoardGame[3][0]== pnPlayer && pvBoardGame[2][1]== pnPlayer && pvBoardGame[1][2]== pnPlayer && pvBoardGame[0][3]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    else if (pvBoardGame[4][1]== pnPlayer && pvBoardGame[3][2]== pnPlayer && pvBoardGame[2][3]== pnPlayer && pvBoardGame[1][4]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    return lbIsAlignment;
}

int calculateBestMove(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD])
{
    int lnColumnOfBestMoveFor1 = -1;
    int lnBestMoveValueFor1 = 0;
    int lnColumnOfBestMoveFor2 = -1;
    int lnBestMoveValueFor2 = 0;
    

    int lnRowOfPiece;
    bool lbIsPiecePlayed;
    int lnValuePosition;
    for(int liIndexColumn = 0; liIndexColumn < 4; liIndexColumn++)
    {
        std::tie(lbIsPiecePlayed, lnRowOfPiece) = play(pvBoardGame, liIndexColumn, cnIA); // joue temporairement le coup à tester
        lnValuePosition = calculatePositionValue(pvBoardGame, cnIA);
        if (lnBestMoveValueFor1 < lnValuePosition) // test la valeur de la position 
        {
            lnBestMoveValueFor1 = lnValuePosition; // la nouvelle meilleure valeur
            lnColumnOfBestMoveFor1 = liIndexColumn; // l'indice pour avoir la nouvelle meilleure valeur
        }
        else 
        {
            // la meilleure valeur ne change pas
        }
        pvBoardGame[lnRowOfPiece][liIndexColumn] = 0; // reset le coup ayant été testé
    }


    for(int liIndexColumn = 0; liIndexColumn < 4; liIndexColumn++)
    {
        std::tie(lbIsPiecePlayed, lnRowOfPiece) = play(pvBoardGame, liIndexColumn, cnPLAYER); // joue temporairement le coup à tester
        lnValuePosition = calculatePositionValue(pvBoardGame, cnPLAYER);
        if (lnBestMoveValueFor2 < lnValuePosition) // test la valeur de la position 
        {
            lnBestMoveValueFor2 = lnValuePosition; // la nouvelle meilleure valeur
            lnColumnOfBestMoveFor2 = liIndexColumn; // l'indice pour avoir la nouvelle meilleure valeur
        }
        else 
        {
            // la meilleure valeur ne change pas
        }
        pvBoardGame[lnRowOfPiece][liIndexColumn] = 0; // reset le coup ayant été testé
    }

    if (lnBestMoveValueFor1 >= lnBestMoveValueFor2)
    {
        return lnColumnOfBestMoveFor1;
    }
    else 
    {
        return lnColumnOfBestMoveFor2;
    }

    return 0;
}

int calculatePositionValue(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayeur)
{


    return 0;
}