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
typedef long long ll;
typedef vector<int > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int > psi; 
typedef pair<int ,int > pii;

string inttostr(int str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>=1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}
void parr(int a[],int n){int i;rep(i,0,n)cout<<a[i]<<" ";cout<<endl;}

/*/////////////////////////////////////////////*/////////////////////////////////////////////////////////
#define gc getchar
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

vector<string> g;
int vis[1111][1111], dis[1111][1111];
pii mv[] = {{-1,0},{0,-1},{1,0},{0,1}};

void bfs(int r, int c) {
    ll ans=0;
    deque<pii > dq;
    dq.pb({0,0});
    while(!dq.empty()) {
        pii p = dq.front();
        dq.pop_front();
        int px = p.xx, py = p.yy;
        if(vis[px][py]) continue;
        int i,j;
        rep(i,0,4) {
            int x = px+mv[i].xx, y = mv[i].yy+py;
            if(x>=0 && y>=0 && x<r && y<c && !vis[x][y]) {
                if(g[px][py] == g[x][y]) {
                    dq.push_front({x,y});
                    dis[x][y] = min(dis[px][py], dis[x][y]);
                }
                else {
                    dq.push_back({x,y});
                    dis[x][y] = min(dis[px][py]+1, dis[x][y]);
                }
            }
        }
        vis[px][py] = 1;
    }
}

int main(){
    int t=fin;
    while(t--) {
        int r=fin, c=fin;
        int i,j;
        g.clear();
        rep(i,0,r) {
            string s;
            cin>>s;
            g.pb(s);
        }
        //rep(i,0,r){ rep(j,0,c) cout<<g[i][j]<<" ";cout<<endl;}
        rep(i,0,r+1) rep(j,0,c+1) vis[i][j] = 0;
        rep(i,0,r+1) rep(j,0,c+1) dis[i][j] = INT_MAX;
        dis[0][0] = 0;
        bfs(r,c);
        pd(dis[r-1][c-1]);
        newl;
        //rep(i,0,r){ rep(j,0,c) cout<<dis[i][j]<<" ";cout<<endl;}
        
    }
    
    return 0;
}
