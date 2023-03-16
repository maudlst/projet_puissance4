#include "node.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    Node node("1202120011000000000000000");
    cout << node.getWeights()[3] << endl;

    cout << "STR :: \n" << node.printPositionName(node.getPositionName()) << endl;


    cout << "REVERSE_STR :: \n" << node.printPositionName(node.reversePosition()) << endl;

    cout << "STRNEW :: \n" << Node::printPositionName(node.calculateNewPositionValue(3, 7)) << endl;

    return 0;
}