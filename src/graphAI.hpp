#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "node.hpp"

#define FILE_NAME "./src/files/graphAI.txt"
/**
 * @brief classe representant le graphe de l'IA
 * 
 */
class GraphAI{
    private:
    /**
     * @brief Map contenant le graphe de l'IA
     * 
     */
    std::map<std::string, Node> msGraphMap;
    
    /**
     * @brief Le noeud racine du graphe
     * 
     */
    Node msRoot = *(new Node("0000000000000000000000000"));
    // Node msActual;

    public:
    GraphAI();
    void exportToFile();
    void importFromFile();
    std::vector<std::string> cutString(std::string pwLine, char pwDelimiter);
    Node& appendChildToParent(Node& psParent, int pnColunm, std::string pwPositionValue); // Si le fils existe déja l'ajouter au parent Sinon on le créer et on le rajoute au parent

    int evaluateKnownPosition();

    std::map<std::string, Node>& getGraphMap();
    Node& getRoot();
    void setRoot(Node& psNode);
    void addNodetoMap(Node& psNode );
};