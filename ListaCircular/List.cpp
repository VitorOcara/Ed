#include <iostream>
#include <string>
#include <climits>
#include "List.h"

struct Node {
    int value;
    Node *next;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};
List::~List(){
    if(!this->empty()){
        Node* aux = head->next;
        Node* t = aux;
        while (aux!=head){
            aux=aux->next;
            delete t;
            t = aux;
        }
        delete head;
        std::cout<< "Lista liberada\n";
    }
} 

List::List() {
    head = new Node;
    head->next = head;
    head->value = 77777777;
}

bool List::contains(int x){
   if(this->empty()){
       return false;
   }
   else{
       Node* aux = head->next;
       while (aux!= head){
           if(aux->value == x){
               return true;
           }
           aux = aux->next;
       }
   }
   return false;
} 

bool List::empty(){
    return head->next == nullptr;
} 

int List::size(){
    int size =0;
    if(!empty()){
        Node* aux = head->next;
        while(aux!= nullptr){
            size++;
            aux =aux->next;
        }
    }
    return size;
} 

void List::clear(){
    Node* aux = head->next;
    Node* t = aux;
    while(aux!= nullptr){
        aux = aux->next;
        delete t;
        t = aux;
    }
    head->next = nullptr;
} 

void List::add_back(int x){
    Node* novo = new Node;
    novo ->value = x;
    novo->next = head;
    if(this->empty()){
        head->next = novo;
    }else{
        Node*aux = head;
        while(aux->next!=head){
            aux = aux->next;
        }
        aux->next = novo;
    }

} 

void List::add_front(int x){
    Node* aux= head->next;
    Node* novo = new Node;
    novo->value = x;
    head->next = novo;
    novo ->next = aux;
}

int List::remove_front(){
    if(this->empty()){
        return INT_MIN;
    }else{    
        Node*aux = head->next ->next;
        int x = head->next->value;
        delete head->next;
        head->next = aux;
        return x;
    }
}

int List::remove_back(){
    if(!this->empty()){
        Node* aux = head->next;
        Node* x = aux;
        while(aux->next != head){
            x = aux;
            aux = aux->next;
        }
        int a = aux->value;
        delete aux;
        x->next = head;
        return a;
    }
}

void List::remove(int x){
    if(!this->empty()){
        Node * aux = head;
        while(aux->next!=head){
            if(aux->next->value == x){
                Node* t = aux->next->next;
                int x = aux->next->value;
                delete aux->next;
                aux->next = t;
                break;
            }
            aux = aux->next;
        }
    }
}

void List::removeAll(int x){
    if(!this->empty()){
        Node * aux = head;
        while(aux->next!=head){
            if(aux->next->value == x){
                Node* t = aux->next->next;
                delete aux->next;
                aux->next = t;
            }
            aux = aux->next;
        }
    }
} 

std::string List::toString(){
    if (empty()){
        return "[]";
    }else{
        std::string s = "[";
        Node *aux;
        aux = head->next;
        while (aux != head){
            if (aux->next != head){
                s += std::to_string(aux->value) += ",";
            }
            else if (aux->next == head){
                s += std::to_string(aux->value);
            }
            aux = aux->next;
        }
        return s += "]";
    }

}
