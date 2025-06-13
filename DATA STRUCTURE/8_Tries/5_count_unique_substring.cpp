#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node
{
    public:
    unordered_map<char , Node*> children ; //char , next node address
    bool endofWord;

    Node()
    {
        endofWord = false;
    }
};

class Trie
{
    public:
        Node *root;
    public:
        Trie()
        {
            root = new Node() ; // creates a node 
        }

    // Insert
    void insert(string key)
    {
        Node* temp = root;
        for(int i  =0 ; i<key.size() ; i++)
        {
            if(temp->children.count(key[i]) == 0) // if it doesnt exist then insert 
            {
                temp->children[key[i]] = new Node(); // if not then make it  a new node 
            }

            temp = temp->children[key[i]]; // updation , now the next node will be children node as temp
        }
        temp->endofWord=true;
    }

    // search
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

    // helper function
    int countHelper(Node* root){
      int ans = 0 ;

      for(pair<char, Node*> child : root->children)
      {
            ans += countHelper(child.second);
      }

      return ans+1;
    }

    // count nodes 
    int countNodes()
    {
        return countHelper(root);
    }
};


// int count substring  wrapper function
int countUniqueSubstring(string str)
{
    Trie trie;

    // find suffic
    for(int i =0 ; i<str.size() ;i++)
    {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main()
{
 string str = "ababa" ;   
    
    cout<<countUniqueSubstring(str)<<endl;

    return 0;
};