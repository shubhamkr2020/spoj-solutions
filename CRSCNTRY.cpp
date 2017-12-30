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

int dp[2009][2009];

int lcs(vi a, vi b) {
    
    int i,j;
    
    rep(i,1,a.size()+1) {
        rep(j,1,b.size()+1) {
            
            if(a[i-1] == b[j-1])
                dp[i][j] = max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[a.size()][b.size()];
}
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    
    int t=fin,i,j;
    while(t--) {
        
        vi a;
        int i=fin;
        while(i!=0) {
            a.pb(i);
            i=fin;
        }
        int z=fin,m=INT_MIN;
        while(z!=0) {
            
            vi b;
            b.pb(z);
            i=fin;
            while(i!=0) {
                b.pb(i);
                i=fin;
            }
            ZERO(dp);
            int l = lcs(a,b);
            if(l > m)
            m = l;
            
            z=fin;
        }
        
        cout<<m<<endl;
        
    }
    
    return 0;
}
