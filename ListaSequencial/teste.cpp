#include <iostream>

using namespace std;



int main(int argc, char const *argv[]){
    int n = 6;

    int vet[n];

    vet[0]=1;
    vet[1]=2;
    vet[2]=3;
    vet[3]=4;
    vet[4]=5;

    for(int i = 0; i< 6; i++){
        cout << vet[i] << " ";
    }
    cout<< "\n";

    for(int i = 6; i > 2; i--){
        vet[i] = vet[i -1];
    }
    for(int i = 0; i< 6; i++){
        cout << vet[i] << " ";
    }
    cout<< "\n";
    return 0;
}
