#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define sin scan_int()
#define mp make_pair
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scstr(x) scanf("%s",x)
#define pd(x) printf("%d",x)
#define pd2(x,y) printf("%d %d",x,y)
#define pll(x) printf("%lld",x)
#define pll2(x,y) printf("%lld %lld",x,y)
#define pstr(x) printf("%s",x)
#define newl printf("\n")
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
    

ll merge(ll a[],ll l,ll mid,ll r) {
    ll i=l,j=mid+1,ans=0;
    ll b[r-l+2],k=0;
    while(i<mid+1 && j<r+1) {
        if(a[i]<a[j]) {
            b[k++] = a[i];
            i++;
        }
        else {
            b[k++] = a[j];
            j++;
            ans+=mid-i+1;
        }
    }
    if(i<mid+1) {
        while(i<mid+1) {
        b[k++] = a[i];
        i++;
        }
    }
    if(j<r+1) {
        while(j<r+1) {
        b[k++] = a[j];
        j++;
        //ans+=mid-i+1;
        }
    }
    
    rep(k,0,r-l+1)
    a[l+k] = b[k];
    
    return ans;
}

ll mSort(ll a[],ll l, ll r) {
    if(l<r) {
        ll mid=(l+r)/2;
        ll x = mSort(a,l,mid);
        ll y = mSort(a,mid+1,r);
        ll z = merge(a,l,mid,r);
        
        return x+y+z;
    }
    return 0;
}

int main() {
	
	ll t=sin;
	//cin>>t;
	//cout<<t;
	//ll c=0;
	while(t--) {
	    //c++;
	    ll n=sin;
	    //cin>>n;
	    //cout<<"a"<<n<<endl;
	    ll a[n];
	    ll i;
	    rep(i,0,n)
	    //cin>>a[i];
	    a[i]=sin;
	    ll ans = mSort(a,0,n-1);
	    //cout<<n<<endl;
	    //rep(i,0,n)
	    //cout<<a[i]<<" ";
	    //cout<<endl;
	    cout<<ans<<endl;
	}
	return 0;
}
