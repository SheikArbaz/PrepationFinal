#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
struct node
{
	int data;
	node *next;
};

int main(int argc, char const *argv[]){
	node *head=0;
	node *temp=new node();//(node*)malloc(sizeof(node));
	temp->data=2;temp->next=0;
	head=temp;
	cout<<head->data<<"\n";
	return 0;
}
http://www.bogotobogo.com/cplusplus/linkedlist.php