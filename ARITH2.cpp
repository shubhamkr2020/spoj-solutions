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
	    char c=gc();
	    char o;
	    int n,ans=0;
	    
	    while(c==' ' || c=='\n')
	    c=gc();
	    
	    while(c>47 && c<58) {
	        ans = ans*10+c-48;
	        c=gc();
	    }
	    
	    while(c==' ' || c=='\n')
	    c=gc();
	    
	    while(c!='=')
	    {
	        o=c;
	        c=gc();
	        
	        while(c==' ' || c=='\n')
	        c=gc();
	        
	        n=0;
	        while(c>47 && c<58)
	        {
	            n=n*10+(c-48);
	            c=gc();
	        }
	        
	        switch(o)
	        {
	            case '+':   ans = ans+n;    break;
	            case '-':   ans = ans-n;    break;
	            case '*':   ans = ans*n;    break;
	            case '/':   ans = ans/n;    break;
	        }
	        
	        while(c==' ' || c=='\n')
	        c=gc();
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}
