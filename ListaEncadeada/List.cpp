
#include <iostream>
#include <climits>
#include "List.h"

struct Node {
    int value; 
    Node *next; 
    ~Node() { std::cout << "Node " << this->value << " removido" << std::endl; }
};

List::List() {
    head = new Node;
    head->value = -77777777;
    head->next = nullptr;
}

List::~List() {
    clear();
    delete head;
    std::cout << "lista liberada" << std::endl;
}


bool List::empty(){
    return head->next == nullptr;
}

void List::add(int x){
    Node* novo =new Node;
    novo->value = x;
    if(this->empty()){
        head->next = novo;
    }else{
        Node* aux = head;
        while( aux->next != nullptr){
            aux = aux->next;
        }
        aux->next=novo;
    }

}
void List::remove(int x){
    if(this->empty()){
        Node * aux = head;
        while(aux->next != nullptr){
            if(aux->next->value == x){
                Node* t = aux->next->next;
                delete aux->next;
                aux->next = t;
                break;
            }
            aux = aux->next;
        }
    }
}

void List::print(){
    std::cout<< "[";
    if(!this->empty()){
        Node* aux = head->next;
        while(aux!=nullptr){

            std::cout<< aux->next << ", ";
            aux = aux->next;

        }
    }
    std::cout<<"]\n";
}

int List::clear(){
    Node* aux = head->next;
    Node* t = aux;
    while(aux!= nullptr){
        aux = aux->next;
        delete t;
        t = aux;
    }
    head->next = nullptr;
}

int List::size(){
    int size = 0;
    if(!empty()){
        Node* aux = head->next;
        while(aux!= nullptr){
            size++;
            aux =aux->next;
        }
    }
    return size;
}

void List::reverse(){
    if(!empty()){
        auxReverse(head->next, nullptr);
    }
}

void auxReverse(Node* no,Node* ant){
   if(no == nullptr){
       head->next = ant;
       return ant;
   }else{
       no = auxReverse(no->next, no);
       no->next = ant;
       return ant;
   }
}

void List::removeAll(int x){
    if(this->empty()){
        Node * aux = head;
        while(aux->next != nullptr){
            if(aux->next->value == x){
                Node* t = aux->next->next;
                delete aux->next;
                aux->next = t;
            }
            aux = aux->next;
        }
    }
}

int List::removeNodeAt(){
    if(!empty()){
        if(0 <= i)
    }
}


