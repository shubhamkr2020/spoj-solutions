#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i,sum=0;
        rep(i,0,n)
        {
            ll a;
            cin>>a;
            sum = (sum+a)%n;
        }
        if(sum == 0)
        cout<<"YES";
        else
        cout<<"NO";
        cout<<endl;
    }
 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
