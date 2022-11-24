#include <string>
#include <iostream>

#define SQUARE_REPR_SIZE_IN_STRING 3
#define SIZE_SIDE 5
#define CHAR_SEPARATOR_COL " "
#define CHAR_SEPARATOR_LINE "\n"

class Node 
{
    private:
    std::string mvChildren[5];
    int mvWeights[5] = {-1};
    std::string mwPositionName;

    public:
    Node();
    Node(std::string pwPositionName);
    void addChild(int place, std::string child); // ajoute le fils à la position place dans mvChildren 
    int ** stringToArray(); // attention au malloc

    static std::string arrayToString();
    
    std::string reversePosition();

    static std::string printPositionName(std::string pwPositionName);

    std::string getPositionName();
    // void setPositionName(std::string pwNewPositionName);
    int *getWeights();


};
