#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next, *prev;
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
	head->prev=0;
	return head;
}
Node* addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = 0;newNode->prev = 0;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			newNode->prev=cur;
			return head;
		}
		cur = cur->next;
	}
	return head;
}
Node* insertBegin(Node* head, int x){
	Node* temp=new Node;
	temp->data=x;temp->next=head;temp->prev=0;
	head->prev=temp;
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
		else{
			head->prev=0;
			head->next=0;
			head=0;
		}
	}
	else{
		int i=1;
		Node* before=new Node;
		Node* cur=new Node;Node* after=new Node;
		before=head;
		cur=head->next;
		after=cur->next;
		while(i<pos){
			before=cur;
			cur=after;
			after=after->next;
			++i;
		}
		before->next=after;
		if(after)
			after->prev=before;
		delete cur;
	}
	return head;
}
int main(int argc, char const *argv[])
{
	Node* head=NULL;
	head=initNode(head,2);display(head);
	head=addNode(head,12);
	display(head);
	head=insertBegin(head,32);
	display(head);
	int i=0;
	while(i++<3){
		head=deleteNode(head,0);
		display(head);
	}
	return 0;
}