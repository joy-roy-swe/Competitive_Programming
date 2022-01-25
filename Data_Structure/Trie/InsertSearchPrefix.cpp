#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 26

struct trieNode{
    int pc;  //pc:prefix_count
    int wc;  //wc:word_count
    trieNode *child[SIZE];

    trieNode(){
        for(int i=0; i<SIZE; i++){
            child[i] = NULL;
            wc=0;
            pc=0;
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
            current->child[idx] = new trieNode();
        current->child[idx]->pc+=1;
        //cout << current->child[idx]->pc <<endl;
        current = current->child[idx];
    }
    current->wc+=1;
}

bool search(string word){
    trieNode *current = root;
    int idx;
    for(int i=0; i<word.length(); i++){
        idx = word[i] - 'a';
        if(current->child[idx] == NULL)
            return false;
        current = current->child[idx];
    }
    if(current->wc == 0){
        return false;
    }
    return true;
}

int countPrefix(string word){
    trieNode *current = root;
    int idx;
    for(int i=0; i<word.length(); ++i){
        idx = word[i]-'a';
        if(current->child[idx]==NULL || current->child[idx]->pc == 0)
            return 0;   //No string with given prefix is present
        current = current->child[idx];
    }
    return current->pc;
}

int main(){
    root = new trieNode();
    insert("ab");
    insert("aba");
    insert("abc");
    insert("bab");
    insert("b");

    if(search("ab")){
        cout <<"word found" <<endl;
    }
    else cout <<"word not found" <<endl;

    if(search("a")){
        cout <<"word found" <<endl;
    }
    else cout <<"word not found" <<endl;
    

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("b"));
    printf("No of strings with given prefix = %d\n",countPrefix("ba"));
}