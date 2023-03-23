#include <string>
#include <iostream>
/**
 * @brief  Le nombre de caractere qui represente une case dans une chaine de carractere
 * 
 */
#define SQUARE_REPR_SIZE_IN_STRING 1
/**
 * @brief Le nombre de case sur une ligne dans le plateau
 * 
 */
#define SIZE_SIDE 5

//#define CHAR_SEPARATOR_COL " "
//#define CHAR_SEPARATOR_LINE "\n"

/**
 * @brief Classe reprensentant un noeud du graphe
 * 
 */
class Node 
{
    private:
    /**
     * @brief Tableau contenant les fils du noeud
     * 
     */
    std::string mvChildren[5];
    /**
     * @brief Tableau contenant le poids des fils du noeud 
     * (le poids est un calcul de reussite en suivant le chemin de ce fils)
     * 
     */
    int mvWeights[5];
    
    /**
     * @brief Chaine de caractere representant le plateau de jeu et des pions joués
     * Il represente une "position" de jeu dans une partie
     * 
     */
    std::string mwPositionName;

    public:
    Node();
    Node(std::string pwPositionName);
    void addChild(int pnColumn, std::string mvChildrenName); // ajoute le fils à la position place dans mvChildren 
    int ** stringToArray(); // attention au malloc

    static std::string arrayToString();
    
    std::string reversePosition();
    std::string calculateNewPositionValue(int pnColumnChosen, int pnCompteurDeCoup);

    static std::string printPositionName(std::string pwPositionName);

    
    std::string getPositionName();
    // void setPositionName(std::string pwNewPositionName);
    int *getWeights();
    std::string *getChildren();
};
