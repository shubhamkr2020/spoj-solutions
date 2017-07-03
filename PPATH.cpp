#include<bits/stdc++.h>
using namespace std;
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

vi g[100009];

bool ifPrime(int n) {
    int i;
    for(i=2; i*i<=n; i++)
    if(n%i==0)
    return false;
    
    return true;
}

string str(int n) {
    string s;
    s += char(n/1000)+'0';
    n = n%1000;
    s += char(n/100)+'0';
    n = n%100;
    s += char(n/10)+'0';
    n = n%10;
    s += char(n)+'0';
    return s;
}

bool check(int n,int m) {
    string a = str(n);
    string b = str(m);
    int c=0,i;
    rep(i,0,4)
    if(a[i]!=b[i])
    c++;
    
    if(c==1)
    return true;
    
    return false;
}
 
int main(){
    
    vi p;
    int i,j;
    rep(i,1000,9999)
    if(ifPrime(i))
    p.pb(i);
    
    rep(i,0,p.size()) {
        rep(j,i+1,p.size()) {
            if(check(p[i],p[j])){
                g[p[i]].pb(p[j]);
                g[p[j]].pb(p[i]);
            }
        }
    }
    
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        
        int ans=INT_MAX;
        queue<int> q;
        int visited[100000]={0};
        int dis[100000];
        rep(i,0,100000)
        dis[i] = INT_MAX;
        dis[a] = 0;
        visited[a] = 1;
        q.push(a);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            visited[v] = 1;
            if(v==b)
            break;
            rep(i,0,g[v].size()) {
                if(!visited[g[v][i]]) {
                    if(dis[g[v][i]] > dis[v]+1) {
                    dis[g[v][i]] = dis[v]+1;
                    q.push(g[v][i]);
                    }
                }
            }
            
        }
        
        if(dis[b] == INT_MAX)
        cout<<"Impossible"<<endl;
        
        else
        cout<<dis[b]<<endl;
        
    }
    
    
    
    return 0;
}
