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
#define fin scan_int()
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
typedef pair<int,int> pii;
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
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
    ll pms,sms,sum,ms; // prefixMaxSum,suffixMaxSum,sum,maxSum
};

node tr[1000000]; //  segment tree
ll a[1000000];  //  input array

void assignNode(node &nd, ll val) {
    //cout<<"assigning leaf...........";
    nd.pms = nd.sms = nd.ms = nd.sum = val;
    //cout<<"leaf assigned with value "<<val<<endl;
}

void merge(node &nd, node lt, node rt) {
    //cout<<"merging....";
    nd.sum = lt.sum + rt.sum;
    nd.pms = max(lt.pms, lt.sum+rt.pms);
    nd.sms = max(rt.sms, rt.sum+lt.sms);
    nd.ms = max(lt.ms, max(rt.ms, lt.sms+rt.pms));

    //cout<<"merging complete "<<endl;
}

void build(ll s, ll e, ll n) {
    
    //cout<<"building......"<<endl;
    if(s == e) {
    assignNode(tr[n], a[s]);
    return;
    }
    
    ll m = (s+e)/2;
    ll lt = n*2, rt = n*2+1;
    build(s, m, lt);
    build(m+1, e, rt);
    merge(tr[n], tr[lt], tr[rt]);
    //cout<<"building complete "<<n<<endl;
}

node query(ll l, ll r, ll s, ll e, ll n) {
    
    //cout<<"querying...."<<n<<endl;
    if(l>e || r<s)
        return node{INT_MIN,INT_MIN,INT_MIN,INT_MIN};
        
    if(l<=s && r>=e)
    return tr[n];
    
    ll m = (s+e)>>1;
    ll lt = n<<1;
    ll rt = lt+1;
    
    node left = query(l,r,s,m,lt);
    node right = query(l,r,m+1,e,rt);
    node ans;
    merge(ans, left, right);
    return ans;
    
}

void update(ll p, ll val, ll s, ll e, ll n) {
    
    if(s == e) {
        assignNode(tr[n],val);
        return;
    }
    
    ll m = (s+e)>>1;
    ll lt = n<<1, rt = lt+1;
    
    if(p<=m) {
        update(p,val,s,m,lt);
    }
    else {
        update(p,val,m+1,e,rt);
    }
    
    merge(tr[n],tr[lt],tr[rt]);
    
}

int main() {
    
    int n=fin;
	int i;
	rep(i,1,n+1)
	a[i] = fin;
	
	build(1,n,1);
	
	int m=fin;
	while(m--) {
	    int p=fin,x=fin,y=fin;
	    
	    if(!p) {
	        update(x,y,1,n,1);
	    }
	    
	    if(p) {
	        node ans = query(x,y,1,n,1);
	        cout<<ans.ms;
	        newl;
	    }
	    
	}
	
	return 0;
}











