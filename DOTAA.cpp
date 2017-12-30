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
	    int n,m,d;
	    cin>>n>>m>>d;
	    int h[n];
	    int i;
	    rep(i,0,n)
	    cin>>h[i];
	    
	    int f=0;
	    int twr = m;
	    i=0;
	    while(twr>0 && i<n)
	    {
	        if(h[i] > d)
	            twr -= (h[i]-1)/d;
	            //h[i] = h[i]%d;
	        i++;
	    }
	    if(twr<=0)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	
	
	return 0;
}

