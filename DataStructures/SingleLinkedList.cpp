#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void display(struct Node *head) {
	cout <<"<<----------------->>"<<endl;
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout <<"\n<<----------------->>"<<endl;
}
void printRec(Node* head){
	cout<<head->data<<" ";
	if(head->next){
		printRec(head->next);
	}
}
void printReverse(Node* head){
	if(head->next){
		printReverse(head->next);
	}
	cout<<head->data<<" ";
}
Node* initNode(struct Node *head, int n){
	head=new Node;
	head->data=n;
	head->next=0;
	return head;
}
Node* addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return head;
		}
		cur = cur->next;
	}
	return head;
}
Node* insertBegin(Node* head, int x){
	Node* temp=new Node;
	temp->data=x;temp->next=head;
	head=temp;
	return head;
}
Node* insertMiddle(Node* head, int pos, int x){
	int i=1;
	Node* temp=new Node;
	Node* temp1=new Node;
	temp=head;	temp1=head->next;
	while(i<pos){
		temp=temp->next;
		temp1=temp->next;
		++i;
	}
	Node* nd=new Node;
	nd->next=temp1;nd->data=x;
	temp->next=nd;
	return head;
}
Node* deleteNode(Node* head, int pos){
	if(pos==0){
		if(head->next){
			Node* temp=head;
			head=head->next;
			delete temp;
		}
		else
			head=NULL;
	}
	else{
		int i=1;
		Node* prev=new Node;
		Node* cur=new Node;Node* after=new Node;
		prev=head;
		cur=head->next;
		after=cur->next;
		while(i<pos){
			prev=cur;
			cur=after;
			after=after->next;
			++i;
		}
		prev->next=after;
		delete cur;
	}
	return head;
}
Node* reverseSLL(Node* head){
	Node* temp=head;
	if(!head->next)//single element
		return head;
	Node *before=head,*cur=head->next,*after=head->next->next;
	before->next=NULL;
	while(after){
		cur->next=before;
		before=cur;
		cur=after;
		after=after->next;
	}
	cur->next=before;
	head=cur;
	return cur;
}
Node* reverseSLLRec(Node* head){
	if(head->next==NULL){
		return head;
	}
	Node* temp=reverseSLLRec(head->next);
	head->next->next=head;
	head->next=NULL;
	return temp;
	
}
int main(int argc, char const *argv[]){
	struct Node *head;// = new Node;
	head=initNode(head,10);
	head=addNode(head,12);
	display(head);
	head=insertBegin(head,8);
	display(head);
	head=insertMiddle(head, 2, 20);
	display(head);
	printRec(head);
	cout<<"\n";
	printReverse(head);
	cout<<"\n";
	display(head);
	head=reverseSLL(head);
	printRec(head);
	cout<<"\n";
	head=reverseSLLRec(head);
	display(head);
	return 0;
}