#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
    int a;
    int player1 = 0;
    int player2 = 0;
    
    cin >> a;

    float produtos[a];
    float chutesP[a];
    char escolhaS[a];


    for(int i = 0; i < a; i++){
        cin >> produtos[i];
        cin.ignore();
    }
    for(int i = 0; i < a; i++){
        cin >> chutesP[i];
        cin.ignore();
    }
    
    for(int i = 0; i < a; i++){
        cin >> escolhaS[i];
        cin.ignore();

    }

    for(int i = 0; i < a; i++){
        
        if( (produtos[i] == chutesP[i])||
            (produtos[i] > chutesP[i] && escolhaS[i] == 'm')||
            (produtos[i] < chutesP[i] && escolhaS[i] == 'M')
            ){
                player1++;
        }else
        {
            player2++;
        }
            
    }
    if (player1 == player2)
    {
        cout << "empate"<< endl;
    }else if (player1 > player2)
    {
        cout << "primeiro"<< endl;
    }else{
        cout << "segundo"<< endl;
    }
    
    


    return 0;
}
