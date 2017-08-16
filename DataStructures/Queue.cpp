#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
}*front,*rear;
bool isEmpty(){
	return (front==0 && rear==0);
}
void enqueue(int n){
	Node* temp=new Node;
	temp->data=n;temp->next=0;
	if(isEmpty()){
		front=temp;rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
void dequeue(){
	if(isEmpty()){
		cout<<"Underflow!!\n";
		return;
	}
	front=front->next;
	if(!front)
		rear=0;
}
void display() {
	Node* temp=front;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
int main(int argc, char const *argv[]){
	enqueue(2);enqueue(3); dequeue();display();
	dequeue();dequeue();display();
	enqueue(2);enqueue(3); dequeue();display();
	enqueue(2);enqueue(3);display();
	enqueue(2);enqueue(3);display();
	enqueue(2);enqueue(3);display();
	
	return 0;
}