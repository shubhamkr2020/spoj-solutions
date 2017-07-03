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
#define fin scan_int()
#define fout(x) fast_out(x)
#define mp make_pair
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scstr(x) scanf("%s",x)
#define pd(x) printf("%d",x)
#define pd2(x,y) printf("%d %d",x,y)
#define pll(x) printf("%lld",x)
#define pll2(x,y) printf("%lld %lld",x,y)
#define pstr(x) printf("%s",x)
#define newl printf("\n")
#define INF 1000001000
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,long> psi; 
typedef pair<int,int> pii;
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
inline void fast_out(ll x){
         register char buffor[35]; register ll i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
       }
       
struct node {
    int uob,ucb;  
};

node tr[1000000];
string str;

void merge(node &nd, node lt, node rt) {
    
    int nm = min(lt.uob,rt.ucb);
    nd.uob = lt.uob + rt.uob - nm;
    nd.ucb = lt.ucb + rt.ucb - nm;
    //nd.f = nd.uob + nd.ucb;
    
}

void assignNode(node &nd, char val) {
    if(val == '(')
    nd.uob=1, nd.ucb=0;
    else
    nd.ucb=1, nd.uob=0;
}

void build(int s,int e,int n) {
 
    if(s==e) {
        assignNode(tr[n],str[s]);
        return;
    }
    
    int m =(s+e)>>1;
    int lt = n<<1, rt = lt+1;
    build(s,m,lt);
    build(m+1,e,rt);
    
    merge(tr[n],tr[lt],tr[rt]);
    
}

void update(int k,int s,int e,int n) {
    
    if(s==e) {
        assignNode(tr[n],str[k]);
        
        return;
    }
    
    int m=(s+e)>>1;
    int lt=n<<1, rt=lt+1;
    
    if(k<=m)
    update(k,s,m,lt);
    else
    update(k,m+1,e,rt);
    
    merge(tr[n],tr[lt],tr[rt]);
    
}


int main() {
    
    int t=1;
    rep(t,1,11) {
        cout<<"Test "<<t<<":"<<endl;
        int n=fin;
        string s;
        cin>>s;
        str = " "+s;
        //cout<<s<<endl<<str;
        //cout<<s<<endl;
        build(1,n,1);
        //cout<<str<<endl;
        int m=fin;
        while(m--) {
            int k=fin;
            
            if(k!=0) {
            	if(str[k] == '(')
            	str[k] = ')';
            	else
            	str[k] = '(';
            	
                update(k,1,n,1);
            }
            
            else {
                
                if(tr[1].ucb==0 && tr[1].uob==0)
                cout<<"YES";
                else
                cout<<"NO";
                newl;
            }
            
        }
    }
	
	return 0;
}











