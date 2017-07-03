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
const ll MAX = pow(10,18);

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    vector< pii > g[n+1];
	    map<string,int> m;
	    rep(i,1,n+1)
	    {
	        string name;
	        cin>>name;
	        m.insert({name,i});
	        int p=sint();
	        while(p--)
	        {
	            int nr=sint(),r=sint();
	            g[i].pb({nr,r});
	        }
	    }
	    
	    int x=sint();
	    //cout<<x;
	    while(x--)
	    {
	        string s1,s2;
	        cin>>s1>>s2;
	        int p,q;
	        p = m[s1];
	        q = m[s2];
	        //cout<<p<<" "<<q<<endl;
	        set< pii > st;
	        st.insert({0,p});
	        ll dist[n+1];
	        rep(i,0,n+1)
	        dist[i] = MAX;
	        dist[p] = 0;
	        while(st.size())
	        {
	            int v = (*st.begin()).second;
	            st.erase(st.begin());
	            //cout<<v<<" "<<dist[v]<<endl;
	            if(v == q)
	            break;
	            rep(i,0,g[v].size())
	            {
	                int a = g[v][i].first, b=g[v][i].second;
	                if(dist[v]+b < dist[a])
	                {
	                    if(dist[a] != MAX)
	                    st.erase(st.find({dist[a],a}));
	                    dist[a] = dist[v]+b;
	                    st.insert({dist[a],a});
	                    
	                }
	            }
	        }
	        
	        cout<<dist[q]<<endl;
	    }
	    
	}
	
	return 0;
}



