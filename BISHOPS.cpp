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
 
 template<class T>
string toString(T s){
  stringstream tin;
  tin<<s;
  string res;
  getline(tin,res);
  return(res);
}

int main() {
	string n;
	while(cin>>n)
	{
	    int i,c=0,l=n.length();
	    
	    if(l==1 && n[0] == '1')
	    cout<<1<<endl;
	    else {
	    rrep(i,l-1,0)
	    {
	        char o,t;
	        o = ((n[i]-48)*2+c)%10;
	        t = ((n[i]-48)*2+c)/10;
	        n[i] = o+48;
	        c = t;
	    }
	    if(c)
	    n = toString(c)+n;
	    l = n.length();
	    if(n[l-1] != '0')
	    n[l-1] = n[l-1]-2;
	    else {
	        n[l-1] = '8';
	        i=l-2;
	        while(n[i]=='0')
	        n[i]='9',i--;
	        //if(i!=l-2)
	        n[i] = n[i]-1;
	    }
	    if(n[0] == '0')
	    n.erase(0,1);
	    cout<<n<<endl;
	    }
	}
	return 0;
}
