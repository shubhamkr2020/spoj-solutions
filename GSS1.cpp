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
#define fin scan_ll()
#define fout(x) fast_out(x)
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
#define INF 1000001000
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,long> psi; 
typedef pair<long,long> pii;
inline ll scan_ll() {
   ll NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
inline void fast_out(ll x){
         register char buffor[35]; register ll i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
       }
       
struct node {
    ll pms,sms,ms,sum; 
};

node tr[1000000];
node infinity;

void build(ll a[],ll l,ll r,ll n) {
    
    if(l==r) {
        tr[n] = {a[l],a[l],a[l],a[l]};
        return;
    }
    
    ll m = (l+r)/2;
    ll lt = n*2, rt = n*2+1;
    build(a,l,m,lt);
    build(a,m+1,r,rt);
    
    tr[n].pms = max(tr[lt].pms, tr[lt].sum+tr[rt].pms);
    tr[n].sms = max(tr[rt].sms, tr[rt].sum+tr[lt].sms);
    tr[n].sum = tr[lt].sum + tr[rt].sum;
    tr[n].ms = max(tr[n].pms, max(tr[lt].ms, max(tr[lt].sms+tr[rt].pms,
                        max(tr[rt].ms, tr[n].sms))));
                        
}

node query(ll a[],ll l,ll r,ll s,ll e,ll n) {
    
    if(r<s || l>e)
    return infinity;
    
    else if(l<=s && r>=e)
    return tr[n];
    
    else {
        ll m = (s+e)/2;
        ll lt = n*2, rt = n*2+1;
        node x1 = query(a,l,r,s,m,lt);
        node x2 = query(a,l,r,m+1,e,rt);
        node ans;
        ans.pms = max(x1.pms, x1.sum+x2.pms);
        ans.sms = max(x2.sms, x2.sum+x1.sms);
        ans.sum = x1.sum + x2.sum;
        ans.ms = max(ans.pms, max(x1.ms, max(x1.sms+x2.pms,
                        max(x2.ms, ans.sms))));
        return ans;
    }
    
}

int main() {
	
	infinity = {-9999999,-999999,-999999,-999999};
	ll n=fin;
	ll a[n+1];
	ll i;
	rep(i,1,n+1)
	a[i] = fin;
	ll m=fin;
	build(a,1,n,1);
	rep(i,0,m) {
	    ll l=fin,r=fin;
	    pll(query(a,l,r,1,n,1).ms);
	    newl;
	}
	
	//rep(i,1,4*n)
	//cout<<tree[i]<<" ";
	
	return 0;
}
