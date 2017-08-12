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
Node* initNode(struct Node *head, int n){
	head=new Node;
	head->data=n;
	head->next=0;
	return head;
}
void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
Node* insertBegin(Node* head, int x){
	Node* temp=new Node;
	temp->data=x;temp->next=head;
	head=temp;
	return head;
}
Node* insertMiddle(Node* head, int pos, int x){
	int i=0;
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
int main(int argc, char const *argv[]){
	struct Node *head;// = new Node;
	head=initNode(head,10);
	addNode(head,12);addNode(head,14);addNode(head,13);
	display(head);
	head=insertBegin(head,8);
	display(head);
	head=insertMiddle(head, 2, 20);
	display(head);
	head=deleteNode(head,0);head=deleteNode(head,0);
	display(head);
	head=deleteNode(head,3);display(head);
	head=deleteNode(head,0);display(head);
	return 0;
}