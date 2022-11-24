#include "node.hpp"

using namespace std;


Node::Node()
{

}


string Node::reversePosition()
{
    string lwReturnString = mwPositionName;
    int liLeftCursor, liRightCursor
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

string Node::getPositionName()
{
    return mwPositionName;
}
int * Node::getWeights()
{
    return mvWeights;
}

