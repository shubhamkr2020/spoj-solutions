#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i,ans=0;
    for(i=1; i*i<=n; i++)
    ans = ans+((n-(i*i-i))/i);
    
    cout<<ans;
    
    return 0;
}
