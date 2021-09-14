
#include <iostream>
#include <fstream>
#include "Mat.h"


using namespace std;


int main(int argc, char const *argv[]){

    Mat *A = new Mat();
    Mat *B = new Mat();
    Mat *C = new Mat();

    A->lerMatriz ("A.txt");
    A->imprime();
    B->lerMatriz("B.txt"); 
    B->imprime() ;
    C->soma(A,B,C); 
    C->imprime();
    B->lerMatriz ("A.txt");
    B->imprime();
    B->insere(1,1,4);
    B->imprime();

    return 0;
}
