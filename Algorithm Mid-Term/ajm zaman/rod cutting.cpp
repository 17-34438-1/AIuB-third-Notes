#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b)
{
    return (a>b)? a:b;
}
int rodCuttingNaive(int *p,int n)
{
    if(n==0)
        return 0;
    int max_value = INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_value = max(max_value,p[i] + rodCuttingNaive(p,n-i-1));
    }
    return max_value;
}
int bottom_up_rodCutting(int *p,int n)
{
    int r[n],s[n];
    r[0] = 0;
    for(int j=0; j<n; j++)
    {
        int q = INT_MIN;
        for(int i=0; i<j; i++)
        {

        }
    }
}
int main()
{
    int p[] = {1,5,8,9,10,17,17,20};
    int n;
    cin>>n;
    while(n!=0)
    {
        cout<<rodCuttingNaive(p,n)<<endl<<endl;
        cin>>n;
    }

    return 0;
}
