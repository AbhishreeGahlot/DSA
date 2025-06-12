// TIME LIMIT EXCEEDS : 
// USE DYNAMIC PROGRAMMING FOR OPTIMIZED SOLUTION  + TRIES 
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
        Node* temp = root; 
        for(int i  =0 ; i<key.size() ; i++)
        {
            if(temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }

            temp = temp->children[key[i]]; // updation
        }
        temp->endofWord=true;
    }   

    // 2. search 
    bool search(string key)
    {
        Node* temp = root;
        for(int i = 0 ; i<key.size();i++)
        {
            if(temp->children.count(key[i])==1)
            {
                temp = temp->children[key[i]];
            }
            else{
                return false;
            }
        }

        return temp->endofWord; // return true only if end of word is true / else false 
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// HELPER FUNCTION
    bool helper(Trie &trie , string key)
    {
        if(key.size() == 0) //base case for recursion to stop
        {
            return true;
        }
        for(int i = 0 ; i<key.size() ;i++)
        {
            string first = key.substr(0 , i+1);  //str.substr(pos, len);
            string second =key.substr(i+1); //i+1 to end
        
        if(trie.search(first) && helper(trie,second))
        {
            return true;
        }
        }
        
        return false;

    }
   
    // WORD BREAK FUNCTION
    bool wordBreak(vector<string> words , string key)
    {
        Trie trie;
        for(int i = 0 ;i<words.size() ;i++)
        {
            trie.insert(words[i]);
        }

        return helper(trie,key); //returns true only if helper returns true
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    vector<string> words ={"the" , "a" , "there" , "their" , "any" , "thee"};
    Trie trie;
    for(int i = 0 ; i<words.size() ;i++)
    {
        trie.insert(words[i]);
    }
    cout<<"word break :  ";
    cout<<wordBreak(words,"apple")<<endl;
   
    return 0;
}