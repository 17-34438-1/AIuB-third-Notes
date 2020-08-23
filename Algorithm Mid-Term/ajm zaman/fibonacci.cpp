#include<iostream>
#include<cstdio>
using namespace std;

///------------------------- NAIVE -----------------------------
int naive_fibonacci(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else
        return naive_fibonacci(n-1)+naive_fibonacci(n-2);
}
///----------------------- TOP DOWN WITH MEMOIZATION -------------------
int arr[100];
void initialize(int n)
{
    for(int i=0; i<=n; i++)
        arr[i] = -1;
}
int top_down_with_memoization(int n)
{
    if(n==1) return 1;
    else if(n==0) return 0;
    else if(arr[n] != -1) return arr[n];
    else
    {
        return arr[n] = top_down_with_memoization(n-1) + top_down_with_memoization(n-2);
    }
}
///---------------------- BOTTOM UP ----------------------------
int bottom_up_fibonacci(int n)
{
    int fibo_1 = 0,fibo_2 = 1,temp;
    for(int i=2; i<=n; i++)
    {
        temp = fibo_1 + fibo_2;
        fibo_1 = fibo_2;
        fibo_2 = temp;
    }
    return temp;
}
int main()
{
    cout<<naive_fibonacci(10)<<endl<<endl;
    initialize(10);
    cout<<top_down_with_memoization(10)<<endl<<endl;
    cout<<bottom_up_fibonacci(10)<<endl<<endl;


    return 0;
}
