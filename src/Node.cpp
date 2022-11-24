#include "node.hpp"

using namespace std;


Node::Node()
{

}


Node::Node(string pwPositionName)
{
    mwPositionName = pwPositionName;
}

string Node::reversePosition()
{
    string lwReturnString = mwPositionName;
    int liLeftCursor, liRightCursor;
    for (int liIndexRow = 0 ; liIndexRow < SIZE_SIDE ; liIndexRow ++)
    {
        liLeftCursor = liIndexRow * SQUARE_REPR_SIZE_IN_STRING * SIZE_SIDE + 2;
        liRightCursor = (liIndexRow + 1)* SQUARE_REPR_SIZE_IN_STRING * SIZE_SIDE - 1;
        lwReturnString[liLeftCursor] = mwPositionName[liRightCursor];
        lwReturnString[liRightCursor] = mwPositionName[liLeftCursor];
        

        liLeftCursor += SQUARE_REPR_SIZE_IN_STRING;
        liRightCursor -= SQUARE_REPR_SIZE_IN_STRING;
        lwReturnString[liLeftCursor] = mwPositionName[liRightCursor];
        lwReturnString[liRightCursor] = mwPositionName[liLeftCursor];
    }
    return lwReturnString;
}


string Node::printPositionName(std::string pwPositionName)
{
    string lwReturnString = "", lwBufferLineString = "";
    const int lnCharInLine = SIZE_SIDE * SQUARE_REPR_SIZE_IN_STRING;
    int lnFirstStringOfRow;
    for (int liIndexRow = 4 ; liIndexRow >= 0 ; liIndexRow --)
    {
        lnFirstStringOfRow = liIndexRow * SIZE_SIDE * SQUARE_REPR_SIZE_IN_STRING;
        // cout << "de " << lnFirstStringOfRow << " à " << lnFirstStringOfRow + lnCharInLine - 1 << endl;
        lwBufferLineString = pwPositionName.substr(lnFirstStringOfRow, lnCharInLine); 
        for (int liIndexColumn = 3; liIndexColumn < lnCharInLine + (1 * SIZE_SIDE) ; liIndexColumn += SQUARE_REPR_SIZE_IN_STRING + 1)
        {
            lwBufferLineString.insert(liIndexColumn, CHAR_SEPARATOR_COL);
        }
        // cout << "HEY ::\n " << pwPositionName.substr(lnFirstStringOfRow, lnCharInLine - 1) << endl;
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

