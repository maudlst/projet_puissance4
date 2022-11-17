#include "boardGame.hpp"


using namespace std;

void gameDisplay(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD])
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
    else if (isBoardGameFull(pvBoardGame))
    {
        lbIsFinished = true;
        cout << "match nul" << endl;
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
    if (pvBoardGame[1][0]== pnPlayer && pvBoardGame[2][1]== pnPlayer && pvBoardGame[3][2]== pnPlayer && pvBoardGame[4][3]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    if (pvBoardGame[0][1]== pnPlayer && pvBoardGame[1][2]== pnPlayer && pvBoardGame[2][3]== pnPlayer && pvBoardGame[3][4]== pnPlayer )
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
    if (pvBoardGame[3][0]== pnPlayer && pvBoardGame[2][1]== pnPlayer && pvBoardGame[1][2]== pnPlayer && pvBoardGame[0][3]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    if (pvBoardGame[4][1]== pnPlayer && pvBoardGame[3][2]== pnPlayer && pvBoardGame[2][3]== pnPlayer && pvBoardGame[1][4]== pnPlayer )
    {
        lbIsAlignment = true;
    }
    return lbIsAlignment;
}

bool isBoardGameFull(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD])
{
    bool lbIsBoardGameFull;
    int liColomnIndex;

    lbIsBoardGameFull = true;
    for (liColomnIndex = 0 ; liColomnIndex < cnSIZE_OF_BOARD ; liColomnIndex++)
    {
        if(pvBoardGame[cnSIZE_OF_BOARD-1][liColomnIndex] == 0)
        {
            lbIsBoardGameFull = false; // si on a un zero dans la derniere ligne le plateau n est pas plein
        }
        else {}// on ne s occupe pas des autres valeur
    }

    return lbIsBoardGameFull;
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
    for(int liIndexColumn = 0; liIndexColumn < 5; liIndexColumn++)
    {
        std::tie(lbIsPiecePlayed, lnRowOfPiece) = play(pvBoardGame, liIndexColumn, cnIA); // joue temporairement le coup à tester
        if (lbIsPiecePlayed)
        {
            lnValuePosition = calculatePositionValue(pvBoardGame, cnIA, lnRowOfPiece, liIndexColumn);
            //cout << liIndexColumn << " : " << lnValuePosition << endl;
            if (lnBestMoveValueFor1 < lnValuePosition) // test la valeur de la position 
            {
                lnBestMoveValueFor1 = lnValuePosition; // la nouvelle meilleure valeur
                lnColumnOfBestMoveFor1 = liIndexColumn; // l'indice pour avoir la nouvelle meilleure valeur
            }
            else 
            {
                // la meilleure valeur ne change pas
            }
        }
        else 
        {

        }
        pvBoardGame[lnRowOfPiece][liIndexColumn] = 0; // reset le coup ayant été testé
    }
    //cout << cnIA << " : " << lnColumnOfBestMoveFor1 << " : " << lnBestMoveValueFor1 << endl;

    for(int liIndexColumn = 0; liIndexColumn < 5; liIndexColumn++)
    {
        std::tie(lbIsPiecePlayed, lnRowOfPiece) = play(pvBoardGame, liIndexColumn, cnPLAYER); // joue temporairement le coup à tester
        if (lbIsPiecePlayed)
        {
            lnValuePosition = calculatePositionValue(pvBoardGame, cnPLAYER, lnRowOfPiece, liIndexColumn);
        // cout << liIndexColumn << " : " << lnValuePosition << endl;
            if (lnBestMoveValueFor2 < lnValuePosition) // test la valeur de la position 
            {
                lnBestMoveValueFor2 = lnValuePosition; // la nouvelle meilleure valeur
                lnColumnOfBestMoveFor2 = liIndexColumn; // l'indice pour avoir la nouvelle meilleure valeur
            }
            else 
            {
                // la meilleure valeur ne change pas
            }
            
        }
        else 
        {
            
        }
        pvBoardGame[lnRowOfPiece][liIndexColumn] = 0; // reset le coup ayant été testé
    }
   // cout << cnPLAYER << " : " << lnColumnOfBestMoveFor2 << " : " << lnBestMoveValueFor2 << endl;

    if (lnBestMoveValueFor1 >= lnBestMoveValueFor2)
    {
        return lnColumnOfBestMoveFor1;
    }
    else 
    {
        return lnColumnOfBestMoveFor2;
    }
}

int calculatePositionValue(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayeur, int pnRowOfMove, int pnColumnOfMove)
{
    int lnPositionValue = 0;
    int lnDirectionValue;

    int lnOpposingPlayer;
    int lnActualRow;
    int lnActualColumn;
    int lvMemoEmpty[3][3] = {{0}}; 
    int lvMemoPlayerTerritory[3][3] = {{0}};
    int lnRangeFromPiece;
    lvMemoEmpty[1][1] = -1; 
    lvMemoPlayerTerritory[1][1] = -1; 
   // gameDisplay(pvBoardGame);

    if (pnPlayeur == cnIA)
    {
        lnOpposingPlayer = cnPLAYER;
    }
    else 
    {
        lnOpposingPlayer = cnIA;
    }
    // cout << lnOpposingPlayer << endl;

    // int lnValueOfPosition = 0;
    for (int liDeltaRow = -1; liDeltaRow <= 1; liDeltaRow++)
    {
        for (int liDeltaColumn = -1; liDeltaColumn <= 1; liDeltaColumn++)
        {
            if (liDeltaRow == 0 && liDeltaColumn == 0)
            {
                // ne rien faire
            }
            else 
            {
                lnActualRow = pnRowOfMove + liDeltaRow;
                lnActualColumn = pnColumnOfMove + liDeltaColumn;
                lnRangeFromPiece = 1;
                // cout << "HEYE" << lnActualRow << lnActualColumn << pvBoardGame[lnActualRow][lnActualColumn] << endl;
                while ((lnActualRow < cnSIZE_OF_BOARD && lnActualRow >= 0) && (lnActualColumn < cnSIZE_OF_BOARD && lnActualColumn >= 0) && (pvBoardGame[lnActualRow][lnActualColumn] != lnOpposingPlayer) && lnRangeFromPiece < 4)
                {
                    //cout << lnActualRow << lnActualColumn << endl;
                    if (pvBoardGame[lnActualRow][lnActualColumn] == 0)
                    {
                        lvMemoEmpty[liDeltaRow + cnOffsetIndex1][liDeltaColumn + cnOffsetIndex1] += 1;
                    }
                    else 
                    {
                        if (lvMemoEmpty[liDeltaRow + cnOffsetIndex1][liDeltaColumn + cnOffsetIndex1] != 0)
                        {
                            lvMemoEmpty[liDeltaRow + cnOffsetIndex1][liDeltaColumn + cnOffsetIndex1] += 1;
                        }
                        else 
                        {
                            lvMemoPlayerTerritory[liDeltaRow + cnOffsetIndex1][liDeltaColumn + cnOffsetIndex1] += 1;
                        }
                    }
                    lnActualRow += liDeltaRow;
                    lnActualColumn += liDeltaColumn;
                    lnRangeFromPiece++;
                }
            }
        }
    }

    lnDirectionValue = calculateValueDirection(lvMemoEmpty[0][0], lvMemoEmpty[2][2], lvMemoPlayerTerritory[0][0], lvMemoPlayerTerritory[2][2]);
    if (lnDirectionValue >= 0)
    {
        lnPositionValue += lnDirectionValue;
    }
    else 
    {
        return numeric_limits<int>::max();
    }
    lnDirectionValue = calculateValueDirection(lvMemoEmpty[1][0], lvMemoEmpty[1][2], lvMemoPlayerTerritory[1][0], lvMemoPlayerTerritory[1][2]);
    if (lnDirectionValue >= 0)
    {
        lnPositionValue += lnDirectionValue;
    }
    else 
    {
        return numeric_limits<int>::max();
    }
    lnDirectionValue = calculateValueDirection(lvMemoEmpty[2][0], lvMemoEmpty[0][2], lvMemoPlayerTerritory[2][0], lvMemoPlayerTerritory[0][2]);
    if (lnDirectionValue >= 0)
    {
        lnPositionValue += lnDirectionValue;
    }
    else 
    {
        return numeric_limits<int>::max();
    }
    lnDirectionValue = calculateValueDirection(lvMemoEmpty[0][1], lvMemoEmpty[2][1], lvMemoPlayerTerritory[0][1], lvMemoPlayerTerritory[2][1]);
    if (lnDirectionValue >= 0)
    {
        lnPositionValue += lnDirectionValue;
    }
    else 
    {
        return numeric_limits<int>::max();
    }
    
    return lnPositionValue;
}

int calculateValueDirection(int pnValueEmpty1, int pnValueEmpty2, int pnValuePT1, int pnValuePT2)
{
    int lnDirectionValue;
    if ((pnValueEmpty1 + pnValueEmpty2 + pnValuePT1 + pnValuePT2) >= 3)
    {
        lnDirectionValue = 1 + pnValuePT1 + pnValuePT2;
        if (lnDirectionValue >= 4)
            return -1;
        else if (lnDirectionValue == 3)
            return cnValueOf3Piece;
        else if (lnDirectionValue == 2)
            return cnValueOf2Piece;
        else
            return cnValueOf1Piece;
    }
    else 
    {
        return 500; // erreur si l'algo exécute ce else
    }
}