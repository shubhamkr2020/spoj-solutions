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
	ll n;
	cin>>n;
	while(n!=-1)
	{
	    ll s=1,i=1;
	    int f=0;
	    while(s<n+1)
	    {
	        if(s==n) {
	        f=1;
	        break;
	        }
	        s += 6*i;
	        i++;
	       // cout<<s<<" ";
	    }
	    if(f)
	    cout<<"Y";
	    else cout<<"N";
	    cout<<endl;
	    
	    cin>>n;
	}
	return 0;
}
