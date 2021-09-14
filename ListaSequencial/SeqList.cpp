#include "SeqList.h"

SeqList::SeqList(int n){
    capacity_vec = n;
    size_vec = 0;
    vec = new int[capacity_vec];
}
int SeqList::at(int k){
    if (k>= 0 && k < capacity_vec){
        return vec[k];
    }
    else
        return -1;
    
}

SeqList::~SeqList(){
    delete vec;
} 


int SeqList::size(){
    return size_vec;
} 

bool SeqList::isFull(){
    return size_vec == capacity_vec;
} 


bool SeqList::add(int x){
    if(!isFull()){
        vec[size_vec] = x;
        size_vec ++;
        return true;
    }
    return false;
}


void SeqList::clear(){
    size_vec = 0;   
} 

int SeqList::search(int x){
    for(int i = 0; i< size_vec; i++){
        if(vec[i] == x){
            return i;
        }
    }
    return -1;
}


bool SeqList::remove(int x){
    int y = search(x);
    if(y == -1){
        return false;
    }else{
        for(int i = x -1; i < size_vec-1; i++){
            vec[i] = vec[i+1];
        }
        size_vec --;
        return true;
    }
} 
std::string SeqList::toString(){
    std::string s = "[";
    for(int i = 0; i < size(); i++){
        s += std::to_string(vec[i]);
        if(i < size()-1){
            s += ",";
        }
    }
    return s + "]";
}

bool SeqList::replaceAt(int x, int k){
    if(k >= 0 && k < size_vec -1){
        vec[k] = x;
        return true;
    }
    return false;
} 
bool SeqList::removeAt(int k){
    if( k >= 0 && k < size_vec -1){
        for(int i = k; i < size_vec-1; i++){
            vec[i] = vec[i+1];
        }
        size_vec--;
        return true;
    }
    return false;
}
bool SeqList::insertAt(int x, int k){
    if( k >= 0 && k < size_vec -1 && size_vec < capacity_vec){  
        size_vec ++;  
        for(int i = size_vec; i > k; i--){
            vec[i] = vec[i -1];
        }
        vec[k]=x;
        return true;
    }
    return false;
}

void SeqList::removeAll(int x){
    for(int i = 0; i < size_vec; i ++){
        if(vec[i] == x){
            vec[i] = vec[size_vec];
            size_vec --;
            i--;
        }
    }
}

