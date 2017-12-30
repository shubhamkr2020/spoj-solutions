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
	    set<string> st;
	    string s;
	    cin>>s;
	    int l = s.length();
	    int i,j,k;
	    
	    rep(i,0,l)
	    {
	        rrep(j,l-i,0)
	        {
	            string temp;
	            rep(k,i,i+j)
	            temp += s[k];
	            st.insert(temp);
	        }
	    }
	    
	    int f=1;
	    set<string>::iterator it;
	    it=st.begin();
	    for(it; it!=st.end();it++)
	    //cout<<*it<<endl;
	    {
	        string temp = *it;
	        reverse(temp.begin(),temp.end());
	        if(st.find(temp) == st.end())
	        f=0;
	    }
	    if(f)
	    cout<<"YES";
	    else cout<<"NO";
	    cout<<endl;
	    
	}
	
	return 0;
}

