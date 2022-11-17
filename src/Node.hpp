#include <string>

class Node {
    private:
    std::string mvChildren[5];
    int mvWeights[5];
    std::string positionValue;

    public:
    Node();
    void addChild(int place, std::string child); // ajoute le fils à la position place dans mvChildren 
    int ** stringToArray(); // attention au malloc

    static std::string arrayToString();
    
    // reversePosition() //



};
