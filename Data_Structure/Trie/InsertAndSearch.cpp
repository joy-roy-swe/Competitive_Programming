#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 26

struct trieNode{
    char data;
    int wc;  //wc:word_count
    trieNode *child[SIZE];

    void node(){
        for(int i=0; i<SIZE; i++){
            child[i] = NULL;
        }
    }
};

trieNode *root;    //Root of Trie

void insert(string word){
    trieNode *current = root;
    int idx;
    for(int i=0; i<word.length(); i++){
        idx = word[i] - 'a';
        if(current->child[idx] == NULL)
            current->child[idx] = new node();
        current->child[idx]->wc +=1;
        current = current->child[idx];
    }
}

bool search(string word){
    trieNode *current = root;
    int idx;
    for(int i=0; i<word.length(); i++){
        idx = word[i] - 'a';
        if(current->child[idx] == NULL || current->child[idx]->wc == 0)
            return false;
        current = current->child[idx];
    }
    return true;
}

int main(){

    insert("ab");
    insert("aba");
    insert("abc");
    insert("bab");
    insert("b");

    cout <<search("ab") <<endl;
    cout <<search("a") <<endl;

}