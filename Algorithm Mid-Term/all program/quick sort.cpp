#include <iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int partition(int *arr, int p, int r);
void quicksort(int *arr, int p, int r)
{
	int q;
	if(p<r)
	{
		q = partition(arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}

int partition(int *arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for(int j=p; j<r; j++){
		if(arr[j]<x){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}

int main ()
{
	int *arr,n;
    cin>>n;
    arr = new int [n];

    for(int i=0; i<n; i++) {
        arr[i] = rand() % 1000;
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
