#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *rlink, *llink;
};
Node* insert(Node* root,int x){
	if(!root){//null root
		root=new Node;
		root->data=x;root->rlink=0;root->llink=0;
	}
	else{
		if(x<root->data)//lesser value so go left and make the created node currents llink
			root->llink=insert(root->llink, x);
		else//higher/equal value so go right and make the created node currents rlink
			root->rlink=insert(root->rlink, x);
	}
	return root;
}
void preorder(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->llink);
	preorder(root->rlink);
}
void postorder(Node* root){
	if(!root)
		return;
	preorder(root->llink);
	preorder(root->rlink);
	cout<<root->data<<" ";
}
void inorder(Node* root){
	if(!root)
		return;
	preorder(root->llink);
	cout<<root->data<<" ";
	preorder(root->rlink);
}
Node* search(Node* root, int data){//returns NULL or node found
    if (root == NULL || root->data == data)
       return root;
    if (root->data < data)
       return search(root->rlink, data);
    return search(root->llink, data);
}
Node * minValueNode(Node* node){
    Node* current = node;
    while (current->llink != NULL)
        current = current->llink;
    return current;
}
Node* deleteNode(Node* root, int key){
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)//this root becomes parent
        root->llink = deleteNode(root->llink, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)//this root becomes parent
        root->rlink = deleteNode(root->rlink, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->llink == NULL)
        {
            Node*temp = root->rlink;
            free(root);
            return temp;
        }
        else if (root->rlink == NULL)
        {
            Node*temp = root->llink;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(root->rlink);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->rlink = deleteNode(root->rlink, temp->data);
    }
    return root;
}
int maxx(int a, int b){
	return a>b?a:b;
}
int height(Node* root){
	if(!root)
		return 0;
	int l=0,r=0;
	l=height(root->llink);
	r=height(root->rlink);
	return 1+maxx(l,r);
}
int main(int argc, char const *argv[]){
	Node *root;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,35);
	root=insert(root,60);

	// root=insert(root,30);
	// root=insert(root,40);
	// root=insert(root,20);
	// root=insert(root,19);
	// root=insert(root,25);
	// root=insert(root,16);
	// root=insert(root,19);
	// root=insert(root,25);
	// root=insert(root,24);
	// root=insert(root,28);
	preorder(root);
	cout<<"\n";
	// root=deleteNode(root, 20);
	preorder(root);
	cout<<"\n";
	cout<<height(root)<<"\n";
	return 0;
}