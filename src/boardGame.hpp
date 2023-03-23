#include <stdio.h>
#include <iostream> 
#include <tuple>
#include <limits>

/**
 * @brief La taille d une ligne du plateau
 * 
 */
#define cnSIZE_OF_BOARD 5
/**
 * @brief Le numero representant le joueur "humain" dans le jeu
 * 
 */
#define cnPLAYER 1
/**
 * @brief Le numero represantant le joueur "ordinateur" dans le jeu
 * 
 */
#define cnIA 2
/**
 * @brief Decalage d'un indice de 1
 * 
 */
#define cnOffsetIndex1 1
/**
 * @brief Valeur pour un alignement de 1 jeton 
 * 
 */
#define cnValueOf1Piece 1
/**
 * @brief Valeur pour un alignement de 2 jetons 
 * 
 */
#define cnValueOf2Piece 4
/**
 * @brief Valeur pour un alignement de 3 jetons
 * 
 */
#define cnValueOf3Piece 9

void gameDisplay(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
std::tuple<bool, int> play(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnColomnToPlay, int pnPlayer);

enum gameStatus {gnGameNotFinished = 0, gnGameWon = 1, gnStaleMate = 2};
gameStatus isGameFinished(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);

bool isVerticalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isHorizontalAlignment(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isDiagonalAlignmentTRBL(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isDiagonalAlignmentTLBR(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayer);
bool isBoardGameFull(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
int calculateBestMove(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD]);
int calculatePositionValue(int pvBoardGame[cnSIZE_OF_BOARD][cnSIZE_OF_BOARD], int pnPlayeur, int pnRowOfMove, int pnColumnOfMove);
int calculateValueDirection(int pnValueEmpty1, int pnValueEmpty2, int pnValuePT1, int pnValuePT2);
