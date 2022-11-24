#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "node.hpp"

#define FILE_NAME "file/graphAI.txt"

class GraphAI{
    private:
    std::map<std::string, Node> msGraphMap;
    Node msRoot;
    // Node msActual;

    public:
    GraphAI();
    void exportToFile();
    void importFromFile();
    std::vector<std::string> GraphAI::cutString(std::string pwLine, char pwDelimiter);
    Node appendChildToParent(Node& parent, std::string pwPositionValue); // Si le fils existe déja l'ajouter au parent Sinon on le créer et on le rajoute au parent

    int evaluateKnownPosition();

    std::map<std::string, Node>& getGraphMap();
    Node& getRoot();
};