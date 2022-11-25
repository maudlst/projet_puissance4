#include "node.hpp"

using namespace std;


Node::Node()
{

}


Node::Node(string pwPositionName)
{
    mwPositionName = pwPositionName;
    for (int i = 0; i < 5; i++)
    {
        mvWeights[i] = -1;
        mvChildren[i] = "";
    } 
}

// CALCULS

string Node::reversePosition()
{
    string lwReturnString = mwPositionName;
    int liLeftCursor, liRightCursor;
    for (int liIndexRow = 0 ; liIndexRow < SIZE_SIDE ; liIndexRow ++)
    {
        liLeftCursor = liIndexRow * SQUARE_REPR_SIZE_IN_STRING * SIZE_SIDE;
        liRightCursor = (liIndexRow + 1) * SQUARE_REPR_SIZE_IN_STRING * SIZE_SIDE - 1;
        lwReturnString[liLeftCursor] = mwPositionName[liRightCursor];
        lwReturnString[liRightCursor] = mwPositionName[liLeftCursor];
        

        liLeftCursor += SQUARE_REPR_SIZE_IN_STRING;
        liRightCursor -= SQUARE_REPR_SIZE_IN_STRING;
        lwReturnString[liLeftCursor] = mwPositionName[liRightCursor];
        lwReturnString[liRightCursor] = mwPositionName[liLeftCursor];
    }
    return lwReturnString;
}

string Node::calculateNewPositionValue(int pnColumnChosen, int pnCompteur) // player  
{
    string lwReturnString = mwPositionName;
    int lnPlayer = (pnCompteur % 2) + 1;
    int lnIndexLineCurrent = 0, lnIndexCharCurrent;
    do
    {
        lnIndexCharCurrent = lnIndexLineCurrent * SIZE_SIDE + pnColumnChosen;
        lnIndexLineCurrent++;
        cout << lwReturnString[lnIndexCharCurrent] ;
        cout << (lwReturnString[lnIndexCharCurrent] != 48) << endl;
    }
    while (lnIndexLineCurrent < 5 && lwReturnString[lnIndexCharCurrent] != 48);
    
    cout << lnIndexCharCurrent << endl;
    lwReturnString[lnIndexCharCurrent] = to_string(lnPlayer)[0];
    return lwReturnString;
}

// AFFICHAGES

string Node::printPositionName(std::string pwPositionName)
{
    string lwReturnString = "", lwBufferLineString = "";
    const int lnCharInLine = SIZE_SIDE * SQUARE_REPR_SIZE_IN_STRING;
    int lnFirstStringOfRow;
    for (int liIndexRow = 4 ; liIndexRow >= 0 ; liIndexRow --)
    {
        lnFirstStringOfRow = liIndexRow * SIZE_SIDE * SQUARE_REPR_SIZE_IN_STRING;
        lwBufferLineString = pwPositionName.substr(lnFirstStringOfRow, lnCharInLine); 
        lwReturnString.append(std::move(lwBufferLineString));
        lwReturnString.append(CHAR_SEPARATOR_LINE);
    }
    return lwReturnString;
}

string Node::getPositionName()
{
    return mwPositionName;
}
int * Node::getWeights()
{
    return mvWeights;
}
string * Node::getChildren()
{
    return mvChildren;
}

