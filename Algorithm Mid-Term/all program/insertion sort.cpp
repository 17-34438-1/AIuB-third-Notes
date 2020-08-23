#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<windows.h>

#define INPUT freopen("in.txt","r",stdin)
#define OUTPUT freopen("out.txt","w",stdout)
using namespace std;

int main()
{
    clock_t tstart = clock();
    int *arr,n,j,x;
    cin>>n;
    arr = new int [n];
    //srand(time(NULL));

    for(int i=0; i<n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";

    }
    for(int i=1; i<n; i++)
    {
        x = arr[i];
        j=i;
        while(j>0 && arr[j-1]>x)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = x;
    }
    cout<<"\n\n\n";
    for(int i=0; i<n; i++) {

        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Time : "<<(double) (clock() - tstart)/CLOCKS_PER_SEC <<endl;

    return 0;
}

