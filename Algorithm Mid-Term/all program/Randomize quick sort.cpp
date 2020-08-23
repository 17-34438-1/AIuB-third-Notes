#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int partition(int *arr, int p, int r);
int Randomize_partition(int *arr, int p, int r);

void Randomize_QuickSort(int *arr,int p,int r)
{
    int q;
    if(p<r)
    {
        q = Randomize_partition(arr,p,r);
        Randomize_QuickSort(arr,p,q-1);
        Randomize_QuickSort(arr,q+1,r);
    }

}
int Randomize_partition(int *arr,int p, int r)
{
    int i = p + (rand()%(r-p+1));
    swap(arr[r],arr[i]);
    return partition(arr,p,r);
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
    Randomize_QuickSort(arr,0,n-1);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
