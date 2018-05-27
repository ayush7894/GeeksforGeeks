#include<iostream>
#include<queue>
#include<cmath>
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
void levelordertraversal(node *root){ //Better Complexity O(n)
	if(root==NULL) return;
	queue<node *> q;
    q.push(root);

	while(1){
	int nodecnt=q.size();
	if(nodecnt==0) break;
    while(nodecnt>0){
     node * d=q.front();
     cout<<d->data<<" ";
     q.pop();
     if(d->left!=NULL) q.push(d->left);
     if(d->right!=NULL) q.push(d->right);
     nodecnt--;
    }
    cout<<endl;
}
}
int height(node *root){
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL) return 1;
	int lh=height(root->left);
	int rh=height(root->right);
    return max(lh,rh)+1;
	}
void LevelTraversal(node *root,int h){
	if(root==NULL) return;
	if(h==1) cout<<root->data<<" ";
	else if(h>1){
		LevelTraversal(root->left,h-1);
		LevelTraversal(root->right,h-1);
	}
}
void levelTraversalLineByLine(node *root){ //O(n^n)
	int h=height(root);
	for(int i=1;i<=h;i++){
	LevelTraversal(root,i);
	cout<<endl;
}

}
int main(){
node *root=new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5); 
//cout<<height(root)<<endl;
levelTraversalLineByLine(root);
levelordertraversal(root);
}