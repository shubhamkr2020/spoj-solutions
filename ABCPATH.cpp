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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
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

/*/////////////////////////////////////////////////////////////////////////////////////////////////////*/
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
 
 char a[111][111];
 int visited[111][111];
 
 int dfs(int i,int j) {
     visited[i][j] = 1;
     int x,y,res=-1;
     rep(x,i-1,i+2) {
         rep(y,j-1,j+2) {
             if(x==i && y==j) continue;
             if(a[x][y] == a[i][j]+1 && !visited[x][y])
             res = max(res, 1 + dfs(x,y));
         }
     }
     if(res == -1)
     return 1;
     else return res;
 }
 
 
int main(){
    //FAST
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);
    
    int n=fin,m=fin,z=0;
    while(n || m) {
        cout<<"Case "<<++z<<": ";
        //char a[n+2][m+2];
        int i,j;
        rep(i,0,n+2) rep(j,1,m+2) visited[i][j] = 0;
        rep(i,0,n+2) rep(j,0,m+2) a[i][j] = '0';
        rep(i,1,n+1) {
            string s;
            cin>>s;
            //cout<<s<<" ";
            rep(j,1,m+1)
            a[i][j] = s[j-1];
        }
        
        //rep(i,0,n+2) {rep(j,0,m+2) cout<<a[i][j];cout<<endl;}
        
        //rep(i,1,n+1) rep(j,1,m+1) ans[i][j] = -1;
        vector<pii > v;
        rep(i,1,n+1) rep(j,1,m+1) if(a[i][j] == 'A') v.pb({i,j});
        
        int k,ma=0;
        rep(k,0,v.size()) {
            int p = dfs(v[k].xx,v[k].yy);
            if(p > ma)
            ma = p;
        }
        cout<<ma<<endl;
        n=fin;m=fin;
    }
    return 0;
}
