#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node *left;
node *right;
node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}
};
void inordertraversal(node *root){
if(root==NULL) return;
inordertraversal(root->left);
cout<<root->data<<" ";
inordertraversal(root->right);

}
void postordertaversal(node *root){
if(root==NULL) return;
postordertaversal(root->left);
postordertaversal(root->right);
cout<<root->data<<" ";
}
void preordertraversal(node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preordertraversal(root->left);
	preordertraversal(root->right);
}
void levelordertraversal(node *root){ //Better Complexity
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
     node * d=q.front();
     cout<<d->data<<" ";
     q.pop();
     if(d->left!=NULL) q.push(d->left);
     if(d->right!=NULL) q.push(d->right);
    }
}
int main(){
node *root=new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5); 
inordertraversal(root);
cout<<endl;
postordertaversal(root);
cout<<endl;
preordertraversal(root);
cout<<endl;
levelordertraversal(root);
cout<<endl;

}