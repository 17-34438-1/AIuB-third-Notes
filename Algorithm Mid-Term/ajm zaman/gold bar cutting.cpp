#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b)
{
    return (a>b)? a:b;
}
int GoldBarCutting(int *p,int n)
{
    if(n==0)
        return 0;
    int max_value = INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_value = max(max_value,p[i] + GoldBarCutting(p,n-i-1));
    }
    return max_value;
}

int main()
{
    int p[] = {0,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int n;
    cin>>n;
    while(n!=0)
    {
        cout<<GoldBarCutting(p,n)<<endl<<endl;
        cin>>n;
    }
    return 0;
}

