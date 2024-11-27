#include<iostream>
#include<queue>
using namespace std;


//1. creation of node   
class node
{
    public:
    
    int data;
    node* left;
    node* right;

    //constructor

    node(int data)
    {
        this->data=data;
        //initially 
        node* left=NULL;
        node* right=NULL;

    }
    
};

//2. Building a tree

node* buildTree(node* root)
{
cout<<"Enter the data"<<endl;
int data;
cin>>data;
root=new node(data);

if(data==-1)
{
    return NULL;
}

cout<<"enter data for left side of "<<data<<endl;
 root->left=buildTree(root->left); //recursive call

cout<<"enter data for right side of "<<data<<endl;
root->right=buildTree(root->right);

return root;



}



//3. level order traversal
void levelOrderTraversal(node* root)
{
 queue<node*> q;
 q.push(root);
 q.push(NULL);
 while(!q.empty())
 {
    node* temp=q.front();
    q.pop();
    if(temp==NULL)
    {
    cout<<endl;
    if(!q.empty())
    {
        q.push(NULL);
    }
    }

    else
    {
        cout<<temp->data<<" ";
    
    if(temp->left)
    {
        q.push(temp->left);
    }

     if(temp->right)
    {
        q.push(temp->right);
    }
 }
}
}

//4 . PREORDER TRAVERsal
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);

}

//5. inorder traversal
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
   
    inorder(root->left);
     cout<<root->data<<endl;
    inorder(root->right);

}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
   
    postorder(root->left);
     postorder(root->right);
     cout<<root->data<<endl;
   

}


/*1 
2 3 
4 5 6 7 */

int main()
{
    node* root=NULL;

    root=buildTree(root);
    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);
    cout<<"preorder traversal"<<endl;
    preorder(root);
     cout<<"inorder traversal"<<endl;
    inorder(root);
      cout<<"postorder traversal"<<endl;
    postorder(root);
    return 0;
}

output:
Enter the data
1
enter data for left side of 1
Enter the data
2
enter data for left side of 2
Enter the data
4
enter data for left side of 4
Enter the data
-1
enter data for right side of 4
Enter the data
-1
enter data for right side of 2
Enter the data
5
enter data for left side of 5
Enter the data
-1
enter data for right side of 5
Enter the data
-1
enter data for right side of 1
Enter the data
3
enter data for left side of 3
Enter the data
6
enter data for left side of 6
Enter the data
-1
enter data for right side of 6
Enter the data
-1
enter data for right side of 3
Enter the data
7
enter data for left side of 7
Enter the data
-1
enter data for right side of 7
Enter the data
-1
level order traversal
1 
2 3 
4 5 6 7 
preorder traversal
1
2
4
5
3
6
7
inorder traversal
4
2
5
1
6
3
7
postorder traversal
4
5
2
6
7
3
1
