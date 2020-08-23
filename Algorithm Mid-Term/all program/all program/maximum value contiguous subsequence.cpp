#include<iostream>
using namespace std;
int main()
{
    int arr[9]={1,2,3,4,5,8,11,12,13},n=9;
    int first_start=0,first_end=0,sum1=0,sum2=0,second_start,second_end;

    for(int i=0; i<n; i++)
    {
        for(int j=i; arr[j]+1 == arr[j+1] && j<n; j++)
        {
            first_start = i;
            first_end = j;
            sum1 += arr[j];
        }
        if(sum1>sum2)
        {
            sum2 = sum1;
            second_start = first_start;
            second_end = first_end+1;
            i=first_end;
        }
    }
    for(int i=second_start; i<=second_end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
