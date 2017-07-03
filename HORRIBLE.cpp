#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) ll((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,ll> psi; 
typedef pair<ll,ll> pii;
inline ll sll() {
   ll NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}


void update(ll ft[],ll n, ll p,ll v) {
    for(p; p<=n; p+=p&-p)
    ft[p] += v;
}

ll query(ll ft[],ll p) {
    ll s=0;
    for(p; p>0; p-=p&-p)
    s += ft[p];
    return s;
}

ll query(ll b1[],ll b2[],ll b) {
    return query(b1,b)*b - query(b2,b);
}

int main() {
	
    ll t;
    cin>>t;
    while(t--) {
        ll n=sll(),c=sll();
        ll b1[n+1]={0},b2[n+1]={0};
        ll i;
        rep(i,0,c) {
            ll x=sll();
            if(!x) {
                ll a=sll(),b=sll(),v=sll();
                update(b1,n,a,v);
                update(b1,n,b+1,-v);
                update(b2,n,a,v*(a-1));
                update(b2,n,b+1,-v*b);
            }
            else {
                ll a=sll(),b=sll();
                cout<<query(b1,b2,b) - query(b1,b2,a-1)<<endl;
            }
        }
    }
    
	
	return 0;
}
