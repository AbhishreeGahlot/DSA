#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node
{
    public:
    string key;
    int val;
    Node* next;

    Node(string key , int val)
    {
        this->key=key;
        this->val=val;
        next=NULL;
    }

    ~Node() //destructor
    {
        if(next != NULL)
        {
            delete next; //khud ko delete krne se pehele next ko delete krdo
        }
    }
};

class HashTable
{
    int totSize; //total size
    int currSize ; 
    Node** table;

    int hashFunction(string key) // for inserting
    {
        int idx=0; 

        for(int i=0;i<key.size();i++)
        {
            idx = idx + (key[i]*key[i])%totSize;
        }
        return idx%totSize;
    }

    void rehash() //for rehashing O(n) 
    {
        //make new table , store old table 
        Node** oldTable = table ; // stores old table 
        int oldSize = totSize ; // stores old table size

        totSize = 2*totSize ; //increase the totSize 
        currSize=0;;
        table = new Node*[totSize]; // making new table 

        for(int i = 0 ; i<totSize ; i++)
        {
            table[i] = NULL; // making new table initially with NULL VALUES
        }

        //copying old table values to new table
        for(int i = 0; i<oldSize ; i++)
        {
            Node* temp = oldTable[i];
            while(temp != NULL)
            {
                insert(temp->key , temp->val);
                Node* toDelete = temp;
                temp = temp->next;
                toDelete->next = NULL; // ✅ Prevent recursive delete
                delete toDelete;     
            }
        }
        //deleting the whole old table: from memory
        delete[] oldTable ; // delete old table array

    }
    public:
        HashTable(int size=5)
        {
            totSize = size;
            currSize = 0;

            table = new Node*[totSize];

            for(int i = 0 ; i<totSize ; i++)
            {
                table[i]=NULL;
            }
        }

        //void insert function
        void insert(string key , int val) //O(1) , worst case : rehash -: O(n)
        {
            //1. index for inserting in table
            int idx = hashFunction(key);
            //2. create new node 
            Node* newNode = new Node(key , val);
            //3. new node -> next is head
            newNode->next = table[idx];
            //4. newNode is head now
            table[idx] = newNode;
            //5 increase the curr size
            currSize++;

            //LOGIC FOR Rehashing 
            double lamba = currSize/(double)totSize;
            if(lamba>1)
            {
                rehash(); //call rehash function
            }
        }

        //bool exists
        bool exists(string key){
            int idx = hashFunction(key);
            Node* temp = table[idx];
            while(temp !=NULL)
            {
                if(temp->key == key)
                {
                    return true;
                }
            temp=temp->next;
            }
            return false;
            
        }
        // void search function
        int search(string key)
        {
            int idx = hashFunction(key);
            Node* temp = table[idx];
             while(temp !=NULL){
                if(temp->key == key)
            {
                return temp->val;
            }
            temp=temp->next;
             }
        return -1;
        }

        void print()
        {
            for(int i = 0;i<totSize;i++)
            {
                cout<<"idx"<<i<<"->";
                Node* temp = table[i];
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->val<<") ->";
                    temp = temp -> next;
                }
                cout<<endl;
            }
        }
        // void remove/erase function
        void remove(string key) //O(lambda)
        {
            int idx = hashFunction(key);

            Node* temp = table[idx];
            Node* prev = temp;

            while(temp!=NULL)
            {
                if(temp->key==key)
                {
                    if(prev==temp) //case 1
                    {
                        table[idx] = temp->next; 
                    }
                    else // case 2
                    {
                        prev->next = temp->next;
                    }
                    break;
                }
                 prev=temp;
                 temp=temp->next;
            }

        }

};

int main()
{
    HashTable ht;
    ht.insert("India",150);
    ht.insert("China",200);
    ht.insert("Russia",250);
    ht.insert("US",100);
    ht.insert("Nepal",50);
    ht.insert("Bangladesh",1000);

    if(ht.exists("Bangladesh")){
        cout << "Population for the given country is " << ht.search("Bangladesh") << endl;
    }


    ht.print();
    cout<<"___________________________________________________";
    ht.remove("India");
    ht.print();
    return 0;
}
