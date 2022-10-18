#include <stdio.h>
#include <iostream>

void afficheJeu(int plateau[5][5]);
bool jouer(int plateau[5][5], int colonneOuJouer, int joueur);
bool jeuFini(int plateau[5][5], int joueur);
bool verificationVerticale(int plateau[5][5], int joueur);
bool verificationHorizontale(int plateau[5][5], int joueur);
bool verficationDiagonaleBgHd(int plateau[5][5], int joueur);
bool verficationDiagonaleBdHg(int plateau[5][5], int joueur);

