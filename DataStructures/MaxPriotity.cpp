#include <iostream>
#include <cmath>
using namespace std;
int N;
void swap(int a[],int i, int j){
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void max_heapify(int Arr[ ], int i){
        int left = 2*i;                 //left child
        int right = 2*i+1;   
        int largest;        //right child
        if(left<= N and Arr[left] > Arr[i] )
              largest = left;
        else
             largest = i;
        if(right <= N and Arr[right] > Arr[largest] )
            largest = right;
        if(largest != i )
        {
            swap(Arr,i,largest);
            max_heapify (Arr, largest);
        } 
}
void build_maxheap(int Arr[ ]){
// elements from Arr[N/2+1] to Arr[N] are leaf nodes,
    for(int i = N/2 ; i >= 1 ; i-- ){
            max_heapify (Arr, i) ;
        }
}
int extract_peek(int Arr[]){
	int val=Arr[1];
	Arr[1]=Arr[N];
	--N;
	max_heapify(Arr,1);
	return Arr[1];
}
void increase_value (int Arr[ ], int i, int val){
    //While increasing a particular elements value..it's parent can be effect ..swap up until it gets correct place..
        if(val < Arr[ i ])
        {
            cout<<”New value is less than current value, can’t be inserted” <<endl;
            return;
        }
        Arr[ i ] = val;
        while( i > 1 and Arr[ i/2 ] < Arr[ i ])
        {
            swap(Arr[ i/2 ], Arr[ i ]);
            i = i/2;
        }
}
void insert_value (int Arr[ ], int val){
        length = length + 1;
        Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
        increase_val (Arr, length, val);//this will take care of max_heapify by swap up..to the correct place
}