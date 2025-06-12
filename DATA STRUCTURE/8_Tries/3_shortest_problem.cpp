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
    int freq ; 

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
        root->freq = -1;
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
                temp->children[key[i]] -> freq = 1;
            }
            else
            {
                temp->children[key[i]]->freq++;
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

    // helper function for shortest prefix problem 
    string getPrefix(string key)//O(L)
    {
        Node* temp = root;
        string prefix="";

        for(int i=0 ;i<key.size();i++)
        {
            prefix+=key[i];
            if(temp->children[key[i]] -> freq ==1)
            {
                break;
            }

            temp = temp->children[key[i]];
        }

        return prefix;
    }
};


// shortest prefix problem 
void prefixProblem(vector<string> dict)
{
    Trie trie;
    for(int i = 0 ; i<dict.size() ;i++)
    {
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size();i++)
    {
        cout<<trie.getPrefix(dict[i]) <<endl;
    }
}

int main()
{
    vector<string> words ={"the" , "a" , "there" , "their" , "any" , "thee"};
    Trie trie;
    for(int i = 0 ; i<words.size() ;i++)
    {
        trie.insert(words[i]);
    }
    cout<<"Shortest Prefix are :  " <<endl;
    prefixProblem(words);
    return 0;
}