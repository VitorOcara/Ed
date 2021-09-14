#include <iostream>
#include "List.h"
#include <climits>

using namespace std;

struct node{
    int value;
    node* next;
    node* back;
};

List::List(){
    head = new node;
    head ->next = head;
    head->back = head;
    head->value = -7777777;
    tamanho = 0;
}


List::~List(){
    if(!empty()){
        node* aux = head->next;
        node* t = aux->next;
        while (aux->next!= head){
            delete aux;
            aux = t;
            t = aux->next;
        }
    } else{
        delete head;
    }
    cout << "Lista Liberada.\n";   
}
void List::clear(){
    //deleta os nós até que a lista fique vazia.
    if(!empty()){
        node* aux = head->next;
        node* t = aux->next;
        while (aux->next!= head){
            delete aux;
            aux = t;
            t = aux->next;
        }
        //faz com que a cabeça aponte para si tanto para frente
        //como para trás.
        head->back = head;
        head->next = head;
        cout<< "Lista Limpa\n";
        this->tamanho = 0;
    }
}


bool List::empty(){
    if(head->next == head)
        return true;
    else
        return false;
}


void List::push_back(int x){
    node* novo = new node;
    novo->value = x;
    //nos dois casos irá precisar do nó novo.
    //faz a definição do ultimo nó, para que depois seja
    //adicionado o novo nó na frente.
    node* aux = head->back;
    if(empty()){
        head->next = novo;
        head->back = novo;
        novo->back= head;
        novo->next = head;
    }else{ 
        aux->next = novo;
        novo->next = head;
        novo->back = aux;
        head->back = novo;
    }
    tamanho++;
}

int List::pop_back(){
    if(empty()){

        //retorna o min se a lista esta vazia.
        return INT_MIN;
    }else{

        //cria um auxiliar que aponta o penultimo.
        node* aux = head->back->back;
        //e um aux que aponta o ultimo.
        node* t= head->back;

        //guarda o valor do ultimo.
        int i = t->value;

        //apaga o ultimo.
        delete t;
        //head aponta pro penultimo que passa a ser o ultimo.
        head->back = aux;
        aux->next = head;

        //reduz o tamanho da lista e retorna o valor do nó removido.
        this->tamanho--;
        return i;
    }
} 


void List::print(){
    if(this->empty()){
        cout << "[]\n";
    }else{
        cout<< "[";
        node* aux = head->next;
        while(aux != head){
            if(aux->next == head){
                cout << aux->value;
            }else{
                cout << aux->value << ", ";
            }
            aux = aux->next;
        }
        cout<< "]\n";
    }
}

void List::printReverse(){
    if(this->empty()){
        cout<< "[]\n";
    }else{
        cout<< "[";
        node* aux = head->back;
        //faz em sentindo contrário o que o print normal faz.
        while (aux!=head){
            if(aux->back == head){
                cout<< aux->value;
            }else{
                cout << aux->value << ", ";
            }
            aux = aux->back;
        }
        cout<< "]\n";
    }
}


bool List::insertAfter(int key, int k){
    
    if(k <= tamanho && k> 0){
        int count = 1;
        node* novo = new node;
        novo->value = key;
        node* aux = head->next;
        node* t = aux->next;
        //percorre a lista até que ache a posição
        //quando acha, remove o nó e faz as ligações.
        while(aux!= head){
            if(count == k){
                aux->next = novo;
                novo->next = t;
                novo->back = aux;
                t->back = novo;
                tamanho ++;

                return true;
            }
            aux= aux->next;
            t= aux->next;
            count++;
        }
    } 
    return false;
}

int List::size(){
    //retorna a variavel que representa o size
    //que é incrementada ou decrementada, dependendo da operação.
    return this->tamanho;
}

void List::remove(int key){
    //O(n)

    if(!this->empty()){ 
        //define quem é o nó atual, o da frente e o anterior.
        node* aux = head->next;
        node* aux2 = aux->next;
        node* aux3 = aux->back;
        while(aux!=head){
            //apaga o primeiro nó com o valor, faz as ligações
            //e quebra o laço, para que não apague outros nós
            //com o mesmo valor.
            if(aux->value == key){
                aux3->next = aux2;
                aux2->back = aux3;
                delete aux;
                break;
            }

            aux= aux->next;
            aux2 = aux->next;
            aux3 = aux->back;
        }
    }
}
void List::removeAll(int key){
    //O(n)

    if(!this->empty()){ 
        //define quem é o nó atual, o da frente e o anterior.
        node* aux = head->next;
        node* aux2 = aux->next;
        node* aux3 = aux->back;
        while(aux!=head){
            //apaga o primeiro nó com o valor até o ultimo
            //logo depois as ligações.
            if(aux->value == key){
                aux3->next = aux2;
                aux2->back = aux3;
                delete aux;
            }

            aux= aux->next;
            aux2 = aux->next;
            aux3 = aux->back;
        }
    }
}
List *List::copy(){
    //cria uma nova lista para ser utilizada para
    //ser feita a inserção dos nós.
    List* l = new List;
    //percorre o lista atual, adicionando os nós á lista criada.
    node* aux = head->next;
    while(aux != head){
        l->push_back(aux->value);
        aux = aux->next;
    }
    return l;
}

void List::copyArray(int n, int v[]){
    if(n > 0){
        //adiciona cada valor do array para a lista.
        for(int i = 0; i < n; i++){
            this->push_back(v[i]);
        }
    }else{
        cout << "tamanho invalido";
    }
}

bool List::equal(List *lst){
    if(this->size() == lst->size()){
        //definindo os primeiros de cada lista.
        node* auxT = this->head->next;
        node* auxL = lst->head->next;
        //faz a comparação dos valores.
        while(auxT != head){
            if(auxT->value != auxL->value){
                return false;
            }  
            auxT = auxT->next;
            auxL = auxL->next; 
        }
        return true;
    }
    return false;
}

void List::concat(List *lst){
    
    if(lst->tamanho <1){
        cout << "invalido" << endl;
    }else{
        node* aux = head->back;

        node* aux2 = lst->head->next;

        node* aux3 = lst->head->back;
        
        //concatena o primeiro da lista do parametro
        //com o ultimo da lista principal.

        aux->next = aux2;
        aux2->back = aux;

        //concatena o ultimo do parametro com a cabeça da principal.

        this->head->back = aux3;
        aux3->next = this->head;

        //esvaziando a lista LST.
        lst->head->back= lst->head;
        lst->head->next = lst->head;
        lst->tamanho = 0;
    }
}