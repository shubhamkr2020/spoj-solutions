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

int dp[1111][1111][3];

int solve(int h,int a,int p) {
    
    if(h<=0 || a<=0)
    return 0;
    
    if(dp[h][a][p]!=-1)
    return dp[h][a][p];
    
    int x=INT_MIN,y=x,z=x;
    if(p==0) {
        y = 1+solve(h-5,a-10,1);
        z = 1+solve(h-20,a+5,2);
    }
    else if(p==1) {
        x = 1+solve(h+3,a+2,0);
        z = 1+solve(h-20,a+5,2);
    }
    else if(p==2) {
        x = 1+solve(h+3,a+2,0);
        y = 1+solve(h-5,a-10,1);
    }
    dp[h][a][p] = max(x,max(y,z));
    return dp[h][a][p];
    
}
 
int main(){
    FAST
    int t=fin;
    while(t--) {
        int h=fin,a=fin;
        int i,j,k;
        rep(i,0,h+30)
        rep(j,0,a+30)
        rep(k,0,3)
        dp[i][j][k] = -1;
        
        int x = solve(h+3,a+2,0);
        int y = solve(h-5,a-10,1);
        int z = solve(h-20,a+5,2);
        
        cout<<max(x,max(y,z))<<endl;
        
        
    }
    
    return 0;
}
