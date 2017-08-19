#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define ZERO(a) memset(a,0,sizeof(a))
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
 
vi v(100000);
int n,c;
int checkMid(int mid) {
    int cow=1,pos=v[0],i;
    rep(i,1,n)
    {
        if(v[i] - pos >= mid)
        {cow++;pos = v[i];
        if(c==cow)
        return 1;}
    }
    return 0;
}

int binarySearch(int start,int end)
{
    int mid = (start+end)/2, max = -1;
    while(end>start) {
    if(checkMid(mid) == 1)
    {
        if(mid > max)
        max = mid;
        start = mid+1;
    }
    else
    end = mid;
    mid = (start+end)/2;
    }
    return max;
}

int main() {
    
    int t = sint();
    while(t--)
    {
        n=sint();
        c=sint();
        int i;
        rep(i,0,n)
        cin>>v[i];
        sort(v.begin(),v.begin()+n);
        int ans = binarySearch(v[0],v[n-1]);
        cout<<ans<<endl;
        
    }
    
	return 0;
}
