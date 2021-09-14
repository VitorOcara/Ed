#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

#include "Mat.h"

using namespace std;


struct node {
    node * direita ;
    node * abaixo ;
    int linha ;
    int coluna ;
    double valor ;
};


Mat::Mat(){
    head = new node;

    head->linha = -1;
    head->coluna = -1;
    head->direita = head;
    head ->abaixo = head;
    head->valor = -999;
}
Mat::~Mat(){

    //caso a matriz tenha elementos
    if(!empty()){
        //um nó auxiliar que começa na posição head
        node * aux = head;
        //um segundo nó auxiliar que fica à direita do auxiliar
        node *t; 
        //um nó que fica uma posição a frente do segundo auxiliar
        node *x;
        // enquanto tiver linhas o auxiliar irá andar uma casa para baixo
        while(aux->abaixo != head){
            t = aux->direita;
            x = t->direita;
            //fazemos o segundo auxiliar (t) ir pra direita enquanto for diferente do aux
            while(t!= aux){
                //o nó que percorre as colunas (t) sera apagado 
                delete t;
                //em seguida ele recebe a posição do auxiliar que está a direita dele
                t = x;
                //e o auxiliar vai mais uma vez pra frente do segundo aux (t)
                x = t->direita;
                    
            }
            aux = aux->abaixo;
        }
        cout<< "Matriz Destruida\n";
    }
    //por fim apaga a cabeça
    delete head;

}


//função que cria a quantidade de cabeças definidas
//por parâmetro abaixo e à direita, respectivamente, sendo o total de cabeças 
//criadas igual as linhas e colunas da matriz
void Mat::criarHead(int l ,int c){

    node* aux = head;
    for(int i = 0; i< l; i++){
        //alocamos um novo nó new_head (nhead)
        node* nhead = new node;

        //as linhas das cabeças recebem indice -1 por regra
        nhead->linha = -1;
        //fazemos as novas cabeças apontar pra elas mesmas(circularidade)
        nhead->direita = nhead;
        //o nó auxiliar que esta na posição anterior agora aponta pro nhead
        //em vez de apontar pro head
        aux->abaixo = nhead;
        //e o aux agora fica na ultima posição
        aux = nhead;
       
    }
    //atribuimos a quantidade de linhas criadas para a matriz
    this->linha = l;
    //e fazemos o aux apontar pra cabeça pra fechar a circularidade
    aux->abaixo = head;


    //agora resetamos o aux afim de criar as colunas 
    aux = head;
    for(int i = 0; i < c; i++){
        //alocação do novo nó cabeça
        node * nhead = new node;
        //a coluna do nó cabeça recebe -1
        nhead->coluna = -1;
        //fazemos a circularidade pra ele mesmo, sendo agora para baixo
        nhead->abaixo = nhead;
        //fazemos o nó aux apontar pra nova cabeça criada
        aux->direita = nhead; 
        //atualizamos a posiçao aux
        aux = nhead;
    }
    //atribuimos o total de colunas
    this->coluna = c;
    //fechamos a circularidade horizontal
    aux->direita = head;

}


void Mat::lerMatriz(string tex){
    //trasnformando a variavel em um leitor de arquivo
    ifstream entrada;
    //verificando se o arquivo foi aberto 
    entrada.open(tex);
    if(entrada.is_open()){
        string texto;

        getline(entrada, texto);
        int l, c;

        // cria as dimenções da matriz 
        //divide a primeira linha da entrada em partes
        istringstream organizer {texto};
        string token;
        vector<string> tamanho;
        //divide as parte pela ","
        while (getline(organizer, token, ',')){
            //coloca dentro do vetor
            tamanho.push_back(token);
        }
        //converte as strings quebradas em inteiros pra serem usados como parametros
        l = stoi(tamanho[0]);
        c = stoi(tamanho[1]);
        //utiliza das variaveis convertidas para dar os tamanhos da matriz e criar as cabeças
        this->criarHead(l, c);

        // criamos um vetor de strings que irá guardar o restantes das informações do txt
        vector<string> insercao;
        while(!entrada.eof()){
            //string linha que sera adicionada no vetor  insercao
            string linha = "";
            //fazemos o linha receber a string do txt e quebrando ela apos a virgula
            getline(entrada, linha, ',');  
            //inserimos a linha na ultima posiçao do vetor
            insercao.push_back(linha);
        } 
        //agora iremos fazer as inserções na matriz usando as posições do vetor
        for(int i = 0; i < insercao.size(); i+=3){
            //como respectivamente sao 3 informações pegaremos 3 posiçoes por vez 

            //a posição 'i' é a linha
            int x= stoi(insercao[i]);
            //a posição 'i+1'  é a coluna
            int j = stoi(insercao[i+1]);
            //a posição 'i+2' é o valor do nó
            double value = stod(insercao[i+2]);
            // com essas informações agora podemos inserir o novo nó na matriz;
            this->insere(x,j,value);
        }
        entrada.close();
    }

}


//função que retorna um valor na posição linha i e coluna j
double Mat::returnValue(int i, int j){

    //criamos um nó que irá percorrer as linhas da matriz
    node *lin = head->abaixo;
    //se a matriz não é vazia
    if(!empty()){
        //fazemos o lin "descer" até a linha desejada
        int cont = 1;
        while(cont < i){
            cont++;
            lin = lin->abaixo;
        }

        //agora que temos a linha na posição correta
        //criamos um nó aux que irá percorrer as colunas dessa linha
        node *aux = lin->direita;
        while (aux != lin){
            //se a coluna do aux for igual a da posição que queremos
            //retornamos o valor dessa coordenada
            if(aux->coluna == j){
                return aux->valor;
            }
            //se nao for igual o aux caminha para a proxima posição a direita
            aux = aux->direita;
        }
    }
    //se a busca não encontrou nada então aquela posição não esta sendo utilizada
    return 0;
}


//Função remasterizada por conta da função return value 
//mesmo sendo uma operação um pouco mais demorada torna-se de melhor compreensão
void Mat::imprime(){
    if(empty()){
        cout << "[]\n";
        return ;
    }
    //percorrer o vetor pelas linhas e colunas, printando os 
    //valores retornados pela função returnValue()
    for(int i = 1; i <= this->linha; i++){
        cout<< "[";
        for(int j = 1; j <= this->coluna; j++){
            if(j== this->coluna){
                cout<< this->returnValue(i,j);
            }else
                cout<< this->returnValue(i,j)<< " ";
        }
        cout<<"]"<<"\n";
    }
}



//Houve uma mudança no parâmetro original da função pois agora é nescessario inserir a matriz
//a qual irá receber os valores 
Mat *Mat::soma(Mat *A, Mat *B, Mat *C){
    //caso as dimensões das duas matrizes passadas sejam iguais
    //a soma sera efetuada
    if(A->coluna == B->coluna && A->linha == B->linha){
        //cria as cabeças da nova matriz
        C->criarHead(A->linha, A->coluna);
        //como todas as matrizes tem as mesmas dimensões,
        //pode percorrer usando qualquer uma como parametro
        for(int i = 1; i <= C->linha; i++){
            for(int j = 1; j<= C->coluna; j++){
                if(A->returnValue(i,j) != 0 || B->returnValue(i,j) != 0){
                    int som = A->returnValue(i, j) + B->returnValue(i, j);
                    C->insere(i,j ,som);
                }
            }
        }
        return C;
    }else{
        //caso as matrizes sejam de proporções diferentes 
        //nao será possivel a soma
        cout << "impossivel somar!\n";
        return nullptr;
    }
}

//função que verifica se a lista está completamente vazia
bool Mat::empty(){
    node *colun = head->direita;
    node *lin = head->abaixo;
    if(colun != head && lin != head)
        return false;
    return true;
}


/* seguindo a mesma idéia do  Mat::soma somente houve a mudança dos parâmetros 
passados para a função ao ser chamada na main */
Mat *Mat::multiplica(Mat *A, Mat *B, Mat *C){
    
    //caso o numero de colunas da Matriz A seja igual ao numero de linhas da Matriz B
    //uma nova Matriz (C) sera criada com as proporções: A ->linha e B->coluna
    //e consequentemente a multiplicação será efetuada
    if(A->coluna == B->linha){
        //cria as cabeças da nova matriz
        C->criarHead(A->linha, B->coluna);
        
        for(int i=1; i <= C->linha; i++){   
            for(int j= 1; j <= C->coluna; j++){
                double mult = 0;
                for(int s=1; s <= B->linha; s++){
                    mult += A->returnValue(i, s)* B->returnValue(s, j);
                }
                C->insere(i, j, mult);
            }
        }
        return C;  
    }else{
        cout << "impossivel multiplicar!\n";
        return nullptr;
    }
}


void Mat::insere(int i, int j, double value){
    //Cria o novo nó que será adicionado
    node * novo = new node;
    novo->linha = i;
    novo->coluna = j;
    novo->valor = value;
    cout<<"add i:" << novo->linha <<" j:" << novo->coluna<<" v:" << novo->valor<<"\n";


    //nó auxiliar para percorrer as linhas
    node * lin = head->abaixo;
    int cont = 1;
    //move o nó auxiliar até a linha correta
    while (lin!=head){
        if(cont == novo->linha){
            break;
        }
        cont++;
        lin = lin->abaixo;
    }
    //nó auxiliar para percorrer as colunas
    node *col = head->direita;
    //move o nó auxiliar até a coluna correta
    cont = 1;
    while(col!=head){
        if(cont == novo->coluna){
            break;
        }
        cont++;
        col = col->direita;
    }
    
    //Caso base na linha, onde será o primeiro inserido 
    //em determinada linha
    node *aux = lin;
    if(aux->direita->coluna == novo->coluna && aux->direita != lin){
        aux->direita->valor = novo->valor;
        delete novo;
        //cout<<"Valor existente!\n";
        return;
    }
    else if(lin->direita == lin){
        lin->direita = novo;
        novo->direita= lin; 
        //cout<< "inserido com sucesso na linha\n";
    }else{
        //move ate o local
        while(aux->direita != lin){
            if(aux->direita->coluna < novo->coluna){
                aux = aux->direita;
            }
        }   
        //verifica se já existe um nó naquela posição em determinada linha
            //...[]  ---> [n] --->  []..
        if(aux->direita->coluna > novo->coluna ){
            //criar um no auxiliar 2 (t) e fazer aux -> novo -> t
            node* t = aux->direita;
            aux->direita = novo;
            novo->direita = t;
            //cout<< "inserido com sucesso na linha\n";
        }
        //aux é o ultimo elemento
            //lin -> [][][][][a]  ---> lin
            //lin -> [][][][][a]-> [n]  ---> lin


        else if(aux->direita == lin){
            aux->direita = novo;
            novo->direita = lin;
            //cout<< "inserido com sucesso na linha\n";
            // novo->direita = aux->direita->direita;
            // aux->direita = novo;
            //cout<< "inserido com sucesso\n";
        }
    
    }

    //caso base na coluna
    aux = col;
    if(aux->abaixo->linha == novo->linha && aux->abaixo != col){
        delete novo;
        //cout<< "inserido com sucesso na coluna\n";
    }else if(col->abaixo == col){
        col->abaixo = novo;
        novo->abaixo = col;
        //cout<< "inserido com sucesso na coluna\n";
    }else{

        //move ate o local
        while(aux->abaixo !=col){
            if(aux->abaixo->linha < novo->linha){
                aux = aux->abaixo;
            }
        }   
        //ajuste para inserção
        //verificar se ja existe

            //verificação para inserção entre nós
            //[][][][][a]  --->  [t] []
            
            //...[]  ---> [n] --->  []..
        if(aux->abaixo->linha > novo->linha){
            //criar um no auxiliar 2 (t) e fazer aux -> novo -> t
            node* t = aux->abaixo;
            aux->abaixo = novo;
            novo->abaixo = t;
            //cout<< "inserido com sucesso na coluna\n";


        }
        //aux é o ultimo elemento
            //lin -> [][][][][a]  ---> lin
            //lin -> [][][][][a]-> [n]  ---> lin


        else if(aux->abaixo == col){
            aux->abaixo = novo;
            novo->abaixo = col;
            // novo->direita = aux->direita->direita;
            // aux->direita = novo;
            //cout<< "inserido com sucesso na coluna\n";

        }
    }
}

