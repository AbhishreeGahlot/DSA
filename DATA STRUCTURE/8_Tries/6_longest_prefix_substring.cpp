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

    
    // main logic : helper function
    void longestHelper(Node* root , string &ans , string temp)
    {
        for(pair<char,Node*> child : root->children)
        {
            if(child.second -> endofWord) //if true 
            {
                temp+= child.first;

                if((temp.size() == ans.size() && temp<ans) || (temp.size() > ans.size()) )
                {
                    ans = temp;
                }

                longestHelper(child.second , ans , temp);
                temp = temp.substr(0  , temp.size() -1);
            }
        }
    }

    // helper func
    string longestStringWithEOW()
    {
        string ans="";
        longestHelper(root, ans , "");
        return ans;
    }
     
};

// wrapper function
string longestString(vector<string>dict)
{
    Trie trie;

    for(int i = 0 ; i<dict.size() ; i++)
    {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}


int main()
{
    vector<string> dict = { "a" , "banana" , "app" , "apple" , "ap" , "appl" , "apply"};
    cout<<longestString(dict)<<endl;

    return 0;
};