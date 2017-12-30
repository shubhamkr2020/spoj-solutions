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
#define xx first
#define yy second
typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,ll> psi; 
typedef pair<ll,ll> pii;

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


int main() {
	
	char s[10000];
	int t=1;
	scstr(s);
	while(s[0]!='-') {
	    int ans=0,l=0;
	    
	    cout<<t++<<". ";
	    while(s[l]!='\0')
	    l++;
	    int i;
	    int o=0;
	    
	    rep(i,0,l) {
	        if(s[i] == '{')
	        o++;
	        else {
	            if(o==0) {
	                ans++;
	                o++;
	            }
	            else o--;
	        }
	    }
	    ans+=o/2;
	    cout<<ans<<endl;
	    
	    
	    scstr(s);
	}
	
	return 0;
}
