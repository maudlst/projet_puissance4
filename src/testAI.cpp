#include "node.hpp"
#include <stdio.h>
#include <iostream>


using namespace std;

int main(){

    Node node("001010020032041100110120131141200210220230240300310320330340400410420430440");

    cout << "STR :: \n" << node.printPositionName(node.getPositionName()) << endl;


    cout << "REVERSE_STR :: \n" << node.printPositionName(node.reversePosition()) << endl;




    return 0;
}