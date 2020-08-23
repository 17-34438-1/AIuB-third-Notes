#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

long long int fibonacci(int n)
{
    if(n==1)
        return n;
    else if(n==0)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int x;
    cout<<"Enter the position of fibonacci number you want to see.\nEnter 0 for exit.\n";
    while(scanf("%d",&x)==1 && x != 0)
    {
        time_t start = clock();
        cout<<fibonacci(x)<<endl;
        cout<<"Required time is : "<<(clock()-start)<<" ms.( 1000 ms = 1 sec )\n"<<endl;
        cout<<"Enter the position of fibonacci number you want to see.\nEnter 0 for exit.\n";
    }
    return 0;
}
