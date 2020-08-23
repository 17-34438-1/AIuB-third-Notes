#include<iostream>
#include<string>

using namespace std;

int main()
{
    int operation = 0, i;
    string a,b;
    cin>>a>>b;
    for(i=0; i<a.length(); i++)
    {
        b[i] = a[i];
    }
    b[i] = '\0';
    cout<<b<<endl;
    return 0;
}
