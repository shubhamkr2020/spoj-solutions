#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
#define lowbit(x) (x&(-x))
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
inline int sint() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;

vi p,q;

int main() {
	
	int n;
	cin>>n;
	int ar[n];
	int i;
	rep(i,0,n)
	cin>>ar[i];
	int a,b,c;
	rep(a,0,n) {
	    rep(b,0,n) {
	        rep(c,0,n) {
	            int x=ar[a],y=ar[b],z=ar[c];
	            int k = x*y+z;
	            int l = (x+y)*z;
	            //p.insert(k);
	            //q.insert(l);
	            p.pb(k);
	            if(z!=0)
	            q.pb(l);
	        }
	    }
	}
	sort(all(p));
	sort(all(q));
    
    int ans=0;
    int si = p.size();
	rep(i,0,si) {
	    int l = lower_bound(q.begin(),q.end(),p[i])-q.begin();
	    int h = upper_bound(q.begin(),q.end(),p[i])-q.begin();
	    ans += (h-l);
	}
	
	cout<<ans<<endl;
	return 0;
}
