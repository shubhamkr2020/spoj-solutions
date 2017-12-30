#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define ZERO(a) memset(a,0,sizeof(a))
#define lastbit(x) (x&(-x)) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define pd(x) printf("%d",x)
#define newl printf("\n")
#define xx first
#define yy second
#define mod 1000000007
#define FIND(x,y) ((y).find((x))!=(y).end())
#define dbg(a) cerr << #a << endl;
#define dbgv(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
#define mod 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;

string inttostr(int str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}

/*/////////////////////////////////////////////////////////////////////////*/////////////////////////////
#define gc getchar_unlocked
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
////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int dm[111][111],dc[111][111],dd[111][111],n,m;

int main(){
    n=fin,m=fin;
    int t=fin;
    while(t--) {
        pii o,c,d;
        int x,y;
        x=fin;y=fin; o={x,y};
        x=fin;y=fin; c={x,y};
        x=fin;y=fin; d={x,y};
        
        int i,j,f=0;
        rep(i,1,m+1) {
            if(abs(o.xx-1)+abs(o.yy-i) < min(abs(c.xx-1)+abs(c.yy-i),abs(d.xx-1)+abs(d.yy-i)))
            {f=1;break;}
            if(abs(o.xx-n)+abs(o.yy-i) < min(abs(c.xx-n)+abs(c.yy-i),abs(d.xx-n)+abs(d.yy-i)))
            {f=1;break;}
        }
        if(!f)
        rep(i,1,n+1) {
            if(abs(o.xx-i)+abs(o.yy-1) < min(abs(c.xx-i)+abs(c.yy-1),abs(d.xx-i)+abs(d.yy-1)))
            {f=1;break;}
            if(abs(o.xx-i)+abs(o.yy-m) < min(abs(c.xx-i)+abs(c.yy-m),abs(d.xx-i)+abs(d.yy-m)))
            {f=1;break;}
        }
        
        if(f) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    
    return 0;
}
