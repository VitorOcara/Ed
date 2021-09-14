#ifndef LIST_H
#define LIST_H

struct node;


class List
{
private:
    node* head;
    int tamanho = 0;
public:
    
    // Construtor da classe. Deve iniciar todos os atributos da classe com valores validos.
    List();   //O(1)      ok

    //Destrutor da classe. Libera mem´oria previamente alocada.
    ~List();   //O(n)    ok

    //Insere um inteiro key ao final da lista.
    void push_back(int key);  //O(1) ok

    //Remove elemento do final da lista e retorna seu valor.
    int pop_back(); //O(1) ok

    //Insere um novo n´o com valor key apos o k-esimo n´o da lista.
    bool insertAfter(int key, int k);   //O(n)  ok

    //Remove da lista a primeira ocorrˆencia do inteiro key
    void remove(int key);   //O(n)     ok
    
    // Remove da lista todas as ocorrˆencias do inteiro key.
    void removeAll(int key);     //O(n)    ok

    // Imprime os elementos da lista.
    void print();     //O(n)  ok
    
    // Imprime os elementos da lista em ordem reversa.
    void printReverse();    //O(n) ok
    
    // Retorna true se a lista estiver vazia e false caso contr´ario.
    bool empty();      //O(1)  ok
    
    // Retorna o n´umero de n´os da lista.
    int size();      //O(1)    ok
    
    //Remove todos os elementos da lista e deixa apenas o n´o cabe¸ca.
    void clear();       //O(n)    ok
    
    /* Concatena a lista atual com a lista lst passada por
    parˆametro. Ap´os essa opera¸c˜ao ser executada, lst ser´a uma lista vazia, ou seja, o
    ´unico n´o de lst ser´a o n´o cabe¸ca. */
    void concat(List *lst); 
    
    //Retorna um ponteiro para uma copia desta lista.
    List *copy(); 
    
    // Copia os elementos do array arr para a
    //lista. O array arr tem n elementos. Todos os elementos anteriores da lista s˜ao
    //mantidos e os elementos do array arr devem ser adicionados ap´os os elementos
    //originais.
    void copyArray(int n, int arr[]); 
    
    /*  Determina se a lista passada por parˆametro ´e igual `a
    lista em quest˜ao. Duas listas s˜ao iguais se elas possuem o mesmo tamanho e o valor
    do k-´esimo elemento da primeira lista ´e igual ao k-´esimo elemento da segunda lista. */
    bool equal(List *lst);

};

#endif