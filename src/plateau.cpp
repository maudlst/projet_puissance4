#include "plateau.hpp"
using namespace std;

void afficheJeu( int plateau[5][5])
{
    int colonne, ligne ;

    for (ligne = 4; ligne >=0 ; ligne --)
    {
        cout << "\t| ";
        for(colonne = 0; colonne <5 ; colonne ++)
        {
            cout << plateau[ligne][colonne] << " | ";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}


bool jouer(int plateau[5][5], int colonneOuJouer, int joueur )
{
    bool aJoue, boucleFinie;
    int casePlateau, indiceLigne ;

    aJoue = false;
    boucleFinie = false;
    indiceLigne = 0;
      
    while(!boucleFinie  && indiceLigne < 5)
    {
        casePlateau = plateau[indiceLigne][colonneOuJouer];  
        if(casePlateau == 0)
        {
            plateau[indiceLigne][colonneOuJouer] = joueur;
            aJoue = true;
            boucleFinie = true;
        }
        indiceLigne++;
    }

    return aJoue;
}


bool jeuFini(int plateau[5][5], int joueur)
{
    bool estFini;

    if (verificationHorizontale(plateau,joueur))
    {
        estFini = true;
        cout << "partie gagnée" << endl;
    }
    else if(verificationVerticale(plateau,joueur))
    {
        estFini = true;
        cout << "partie gagnée" << endl;
    }
    else if (verficationDiagonaleBdHg(plateau,joueur))
    {
        estFini = true;
        cout << "partie gagnée" << endl;
    }
    else if (verficationDiagonaleBgHd(plateau,joueur))
    {
        estFini = true;
        cout << "partie gagnée" << endl;
    }
    else 
    {
        estFini = false;
    }
    return estFini;
}


bool verificationVerticale(int plateau[5][5], int joueur)
{
    bool alignementVertical;
    int indiceColonne;

    alignementVertical = false;

    for (indiceColonne =0 ; indiceColonne < 5; indiceColonne++)
    {
        if(plateau[1][indiceColonne]== joueur)
        {
            if(plateau[2][indiceColonne]== joueur && plateau[3][indiceColonne]== joueur) // 3 pions alignés
            {
                if(plateau[0][indiceColonne]== joueur || plateau[4][indiceColonne]== joueur) // 4 pions alignés
                {
                    alignementVertical = true;
                }
            }
        }
    }
    return alignementVertical;
}

bool verificationHorizontale(int plateau[5][5], int joueur)
{
    bool alignementHorizontale;
    int indiceLigne;

    alignementHorizontale = false;

    for (indiceLigne =0 ; indiceLigne < 5; indiceLigne++)
    {
        if(plateau[indiceLigne][1]== joueur)
        {
            if(plateau[indiceLigne][2]== joueur && plateau[indiceLigne][3]== joueur) // 3 pions alignés
            {
                if(plateau[indiceLigne][0]== joueur || plateau[indiceLigne][4]== joueur) // 4 pions alignés
                {
                    alignementHorizontale = true;
                }
            }
        }
    }
    return alignementHorizontale;
}

bool verficationDiagonaleBgHd(int plateau[5][5], int joueur)//Diagonale le Bas à Gauche et le Haut à Droite
{
    bool alignementDiagonale;

    alignementDiagonale = false;

    if (plateau[2][2]== joueur)
    {
        if(plateau[1][1]== joueur && plateau[3][3]== joueur) // 3 pions alignés
        {
            if(plateau[0][0]== joueur || plateau[4][4]== joueur) // 4 pions alignés
            {
                alignementDiagonale = true;
            }
        }
    }
    else if (plateau[1][0]== joueur && plateau[2][1]== joueur && plateau[3][2]== joueur && plateau[4][3]== joueur )
    {
        alignementDiagonale = true;
    }
    else if (plateau[0][1]== joueur && plateau[1][2]== joueur && plateau[2][3]== joueur && plateau[3][4]== joueur )
    {
        alignementDiagonale = true;
    }
    return alignementDiagonale;
}

bool verficationDiagonaleBdHg(int plateau[5][5], int joueur)//Diagonale le Bas à Droite et le Haut à Gauche
{
    bool alignementDiagonale;

    alignementDiagonale = false;

    if (plateau[2][2]== joueur)
    {
        if(plateau[3][1]== joueur && plateau[1][3]== joueur) // 3 pions alignés
        {
            if(plateau[0][4]== joueur || plateau[4][0]== joueur) // 4 pions alignés
            {
                alignementDiagonale = true;
            }
        }
    }
    else if (plateau[3][0]== joueur && plateau[2][1]== joueur && plateau[1][2]== joueur && plateau[0][3]== joueur )
    {
        alignementDiagonale = true;
    }
    else if (plateau[4][1]== joueur && plateau[3][2]== joueur && plateau[2][3]== joueur && plateau[1][4]== joueur )
    {
        alignementDiagonale = true;
    }
    return alignementDiagonale;
}