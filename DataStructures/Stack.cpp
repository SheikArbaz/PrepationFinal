#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* push(Node* head,int n){
	if(head==0){
		head=new Node;
		head->data=n;head->next=0;
		return head;
	}
	Node* temp=new Node;
	temp->data=n;temp->next=head;
	return temp;
}
Node* pop(Node* head){
	Node* temp=head->next;
	delete head;
	return temp;
}
bool isEmpty(Node* head){
	if(!head)
		return true;
	return false;
}
void display(struct Node *head) {
	cout <<"<<----------------->>"<<endl;
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout <<"\n<<----------------->>"<<endl;
}
int main(int argc, char const *argv[]){
	Node* top;
	top=push(top, 2);
	top=push(top, 3);top=push(top, 2);
	top=push(top, 3);
	top=pop(top);top=pop(top);
	cout<<isEmpty(top)<<"\n";
	display(top);
	top=pop(top);top=pop(top);
	cout<<isEmpty(top)<<"\n";
	return 0;
}