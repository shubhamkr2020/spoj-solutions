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

bool bfs(vi g[],int v,int sex[]) {
    int i;
    queue<int> q;
    q.push(v);
    sex[v] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int i;
        rep(i,0,g[v].size()) {
            if(sex[g[v][i]]!=-1 && sex[g[v][i]]==sex[v])
            return true;
            if(sex[g[v][i]] == -1) {
                sex[g[v][i]] = 1-sex[v];
                q.push(g[v][i]);
            }
        }
    }
    return false;
}

int main(){
    
    int t=fin,q;
    for(q=0;q<t;q++) {
        cout<<"Scenario #"<<q+1<<":"<<endl;
        int n=fin,m=fin;
        int i;
        vi g[n+1];
        rep(i,0,m) {
            int a=fin,b=fin;
            g[a].pb(b);
            g[b].pb(a);
        }
        int sex[n+1],ans=1;
        rep(i,0,n+1)
        sex[i] = -1;
        rep(i,1,n+1) {
            if(sex[i] == -1) {
                if(bfs(g,i,sex)) {
                    ans=0;
                    break;
                }
            }
        }
        
        if(ans==1)
        cout<<"No suspicious bugs found!"<<endl;
        else
        cout<<"Suspicious bugs found!"<<endl;
        
    }
    
    return 0;
}
