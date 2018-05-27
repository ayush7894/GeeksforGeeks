#include<iostream>
#include<stack>
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
void Inorder(node *root){ //O(n)
	stack <node *> s;
	node *current=root;
	bool done =0;
	while(!done){
	if(current!=NULL){
		s.push(current);
		current=current->left;
	}
	else {
		if(current==NULL&&!s.empty()){
		current=s.top();
		s.pop();
		cout<<current->data<<" ";
		current=current->right;
	}
	else done=1;
	}
	}

}

int main(){
node *root=new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5); 
Inorder(root);
}