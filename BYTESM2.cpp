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
 
int max(int a,int b,int c)
{
    return a>b?(a>c?a:c):(b>c?b:c);
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int dp[101][101],a[102][102];
	    int h,w;
	    cin>>h>>w;
	    int i,j,m=0;
	    ZERO(a);
	    mem(dp,-1);
	    rep(i,1,h+1)
	    rep(j,1,w+1)
	    cin>>a[i][j];
	    
        rep(i,1,w+1)
        dp[1][i] = a[1][i];
        rep(i,2,h+1)
        rep(j,1,w+1)
        dp[i][j] = max(a[i][j]+dp[i-1][j-1],a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j+1]);

	    rep(i,1,w+1)
	    if(dp[h][i] > m)
	    m = dp[h][i];
	    
	    cout<<m<<endl;
	}
	
	return 0;
}
