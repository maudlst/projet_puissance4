#include <stdio.h>
#include <iostream> 
#include <tuple>
#include <limits>

// Fichier a rangé en deux parties

#define cnSIZE_OF_BOARD 5 
#define cnPLAYER 1
#define cnIA 2
#define cnOffsetIndex1 1
#define cnValueOf1Piece 1
#define cnValueOf2Piece 4
#define cnValueOf3Piece 9

void gameDisplay( int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
std::tuple<bool, int> play(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnColomnToPlay, int pnPlayer);
bool isGameFinished(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isVerticalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isHorizontalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isDiagonalAlignmentTRBL(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isDiagonalAlignmentTLBR(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isBoardGameFull(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
int calculateBestMove(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
int calculatePositionValue(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayeur, int pnRowOfMove, int pnColumnOfMove);
int calculateValueDirection(int pnValueEmpty1, int pnValueEmpty2, int pnValuePT1, int pnValuePT2);
