#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
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
#define xx first
#define yy second
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
inline void fast_out(int x){
         register char buffor[35]; register int i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
}

ll c[20000],dp[100000];


ll solve(ll c[],vi v,int n,int k) {
    
    ll i;
    dp[0] = 0;
    
    rep(i,0,v.size())
    dp[v[i]]=c[v[i]];
    
    rep(i,1,k+1) {
        ll j=0;
        while(j<v.size()) {
            if(i-v[j]>=0 && dp[i-v[j]]+c[v[j]] < dp[i])
            dp[i] = dp[i-v[j]]+c[v[j]];
            
            j++;
        }
    }
    return dp[k];
    
}
 
 
int main(){
    
    int t=fin;
    while(t--) {
        
        ll n=fin,k=fin;
        vi v;
        ll i;
        rep(i,0,n+2)
        c[i]=0;
        rep(i,1,k+1) {
        cin>>c[i];
        if(c[i] != -1)
        v.pb(i);
        }
        
        rep(i,0,k+2)
        dp[i]=INT_MAX;
        
        ll ans = solve(c,v,n,k);
        
        if(ans == INT_MAX)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;
    }
    
    return 0;
}
