#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

ll solve(int n)
{
    if(n>-1 && n<12)
    return n;
    
    ll a,b,c;
    a= solve(n/2);
    b= solve(n/3);
    c= solve(n/4);
    if(a+b+c > n)
    return a+b+c;
    else
    return n;
}


int main() {
    
    int n;
    while(cin>>n)
    {
        ll ans = solve(n);
        cout<<ans<<endl;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
