#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y,z;
        cin>>x>>y>>z;
        ll n = 2*z/(x+y);
        cout<<n<<endl;
        ll d = (y-x)/(n-5);
        ll a = (x-2*d);
        int i;
        for(i=1;i<=n;i++)
        cout<<(a+(i-1)*d)<<" ";
        cout<<endl;
    }
    return 0;
}
