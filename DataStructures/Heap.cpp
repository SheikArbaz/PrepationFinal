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
void heap_sort(int Arr[ ])
{
        int heap_size = N;
        build_maxheap(Arr);
        for(int i = N; i>=2 ; i-- )
        {
            swap(Arr[ 1 ], Arr[ i ]);
            heap_size = heap_size-1;
            max_heapify(Arr, 1);
        }
}
int main(int argc, char const *argv[])
{
	N=5;
	int Arr[]={-1,1,2,3,4,5};
	build_maxheap(Arr);
	for(int i=1;i<=N;++i){
		cout<<Arr[i]<<" ";
	}cout<<"\n";
	cout<<extract_peek(Arr)<<"\n";
	for(int i=1;i<=N;++i){
		cout<<Arr[i]<<" ";
	}cout<<"\n";
	return 0;
}