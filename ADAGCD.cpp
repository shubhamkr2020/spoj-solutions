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

const ll mod = 1000000007;

long long modexpo(long long a,long long b,long long n) {
    long long d=1;
    while(b) {
        if(b&1)
            d=(d*a)%n;
        b>>=1;
        a=(a*a)%n;
    }
    return d;
}
int p[10000001],lp[10000001];
int cnt[10000001];
int gp[10000001];

int main(){
    
    int n=fin;
    int t,i;
    rep(i,2,10000001) gp[i]=INT_MAX;
    
    for(int i = 2; i < 10000001; i ++)
        if(!lp[i]){
            for(int j = i; j < 10000001; j += i)
                lp[j] = i;
    	}
    
    rep(t,0,n) {
        int m=fin;
        int i,j;
        set<int> v;
        
        rep(i,0,m) {
            int x=fin;
            while(x>1) {
            	int d = lp[x];
            	v.insert(d);
            	while(x%d==0) {
            		p[d]++;
            		x = x/d;
            	}
            }
        }
        tr(v,it) {
        	cnt[*it]++;
            if(p[*it] < gp[*it])
            gp[*it] = p[*it];
            p[*it] = 0;
        }
    }
    
    int g=1;
    
    //rep(i,2,10000001) if(cnt[i]) cout<<i<<" "<<cnt[i]<<endl;
    
    //rep(i,2,10000001) {if(cnt[i]==n) {cout<<i<<" "<<gp[i]<<endl;}}
    
    rep(i,2,10000001) {
    	if(cnt[i]==n)
        g = (1ll*g*modexpo(i,gp[i],mod))%mod;
    }
    pd(g);
    return 0;
}
