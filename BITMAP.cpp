#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define lowbit(x) (x&(-x))
#define it(x) x::iterator it
#define gc getchar_unlocked
inline int sint()
   {int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));
}

 typedef long long ll;
 typedef vector<int> vi;
 typedef vector<string> vs;
 typedef vector<vi> vvi;
 typedef pair<string,int> psi;
 typedef pair<int,string> pis;
 typedef pair<int,int> pii;
 
 int a[200][200];
 int p,q;
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>p>>q;
	    vs v;
	    string s;
	    int i,j,k;
	    rep(i,0,p)
	    {
	        cin>>s;
	        v.pb(s);
	    }
	    rep(i,0,200)
	    rep(j,0,200)
	    a[i][j] = INT_MAX;
	    
	    queue< pii > Q;
	    map< pii,int > mp;
	    rep(i,0,p)
	    rep(j,0,q)
	    if(v[i][j] == '1')
	    {
	        a[i][j] = 0;
	        Q.push({i,j});
	    }
	    
	    while(!Q.empty()) {
	                    int x,y;
	                    pii node;
	                    node = Q.front();
	                    Q.pop();
	                    x = node.first;
	                    y = node.second;
	                       
	                       if(x-1>-1 && a[x-1][y]>a[x][y]+1) {
	                       a[x-1][y] = a[x][y]+1;    
	                       Q.push({x-1,y});
	                       }
	                       if(y-1>-1 && a[x][y-1]>a[x][y]+1) {
	                       a[x][y-1] = a[x][y]+1;    
	                       Q.push({x,y-1});
	                       }
	                       if(x+1<p && a[x+1][y]>a[x][y]+1) {
	                       a[x+1][y] = a[x][y]+1;    
	                       Q.push({x+1,y});
	                       }
	                       if(y+1<q && a[x][y+1]>a[x][y]+1) {
	                       a[x][y+1] = a[x][y]+1;    
	                       Q.push({x,y+1});
	                       }
	                }
	    
	    rep(i,0,p) {
	    rep(j,0,q)
	    cout<<a[i][j]<<" ";
	    cout<<endl;
	    }
	}
	return 0;
}
