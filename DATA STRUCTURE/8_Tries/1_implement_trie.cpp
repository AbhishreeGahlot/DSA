#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node
{
    public:
    unordered_map<char , Node* > children ;
    bool endofWord;

    Node()
    {
        endofWord=false;
    }
};

class Trie
{
    Node* root ; 
    public:
    Trie()
    {
        root = new Node();
    }

    // 1. insert function
    void insert(string key)
    {
        Node* temp = root;  // root node has knowledge of children nodes
        for(int i  =0 ; i<key.size() ; i++)
        {
            if(temp->children.count(key[i]) == 0) // if it doesnt exist then insert 
            {
                temp->children[key[i]] = new Node(); // if not then make it  a new node 
            }

            temp = temp->children[key[i]]; // updation , now the next node will be children node as temp
        }
        temp->endofWord=true; // after looop ends , means iterating the whole word , end of word should be marked true
    }   

    // 2. search 
    bool search(string key)
    {
        Node* temp = root;
        for(int i = 0 ; i<key.size();i++)
        {
            if(temp->children.count(key[i])==1) // if exist , go till the end of the word
            {
                temp = temp->children[key[i]];
            }
            else{
                return false;
            }
        }

        return temp->endofWord; // return true only if end of word is true / else false 
    }

    //3. is prefix()
    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children.count(prefix[i]) == 0) { // if not exist return false 
                return false;
            }
            temp = temp->children[prefix[i]];
        }
        return true;
    }
};

int main()
{
    vector<string> words ={"the" , "a" , "there" , "their" , "any" , "thee"};
    Trie trie;
    for(int i = 0 ; i<words.size() ;i++)
    {
        trie.insert(words[i]);
    }
    cout<<"Searching for apple : "<<trie.search("apple")<<endl;
    cout<<"Searching for there : "<<trie.search("there")<<endl;
    return 0;
}