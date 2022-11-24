#include "node.hpp"
#include <stdio.h>
#include <iostream>


using namespace std;

int main(){

    Node node("1002100011000000000000000");
    cout << node.getWeights()[4] << endl;

    cout << "STR :: \n" << node.printPositionName(node.getPositionName()) << endl;


    cout << "REVERSE_STR :: \n" << node.printPositionName(node.reversePosition()) << endl;




    return 0;
}