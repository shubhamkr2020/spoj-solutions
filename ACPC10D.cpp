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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
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

 
int main(){
    FAST
    
    ll n,z=1;
    cin>>n;
    while(n) {
        cout<<z++<<". ";
        
        ll a[n][3];
        ll i;
        rep(i,0,n)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        
        ll dp[n][3];
        rep(i,0,n)
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
        
        dp[0][0] = INT_MAX;
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][1] + a[0][2];
        
        rep(i,1,n) {
            dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + a[i][0];
            dp[i][1] = min(dp[i-1][0],min(dp[i-1][1],min(dp[i-1][2],dp[i][0]))) + a[i][1];
            dp[i][2] = min(dp[i-1][1],min(dp[i-1][2],dp[i][1])) + a[i][2];
        }
        
        cout<<dp[n-1][1]<<endl;
        cin>>n;
    }
    
    return 0;
}
