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

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vi v(n);
	    int i;
	    rep(i,0,n)
	    cin>>v[i];
	    sort(all(v));
	    
	    int ans = INT_MAX;
	    if(k==1)
	    cout<<0;
	    else {
	    rep(i,0,n-k+1)
	    {
	        if(v[i+k-1] - v[i] < ans)
	        ans = v[i+k-1] - v[i];
	    }
	    cout<<ans;
	    }
	    cout<<endl;
	}
	
	return 0;
}
