#include <map>
#include <string>
#include "node.hpp"

class graphAI{
    private:
    std::map<std::string, Node *> msGraphMap;
    Node msRoot;
    // Node msActual;

    public:
    graphAI();
    void exportToFile();
    void importFromFile();
    Node appendChildToParent(Node& parent, std::string pwPositionValue); // Si le fils existe déja l'ajouter au parent Sinon on le créer et on le rajoute au parent

    int evaluateKnownPosition();


};