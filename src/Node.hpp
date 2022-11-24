#include <string>

#define SQUARE_REPR_SIZE_IN_STRING 3
#define SIZE_SIDE 5

class Node {
    private:
    std::string mvChildren[5];
    int mvWeights[5];
    std::string mwPositionName;

    public:
    Node();
    void addChild(int place, std::string child); // ajoute le fils à la position place dans mvChildren 
    int ** stringToArray(); // attention au malloc

    static std::string arrayToString();
    
    std::string reversePosition();

    std::string getPositionName();
    int *getWeights();
    

};
