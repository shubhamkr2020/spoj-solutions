#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
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
#define xx first
#define yy second
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;
inline ll scan_int() {
   ll NR=0,sign=1;    char c=gc();
    while( c < 48 || c > 57 ){if(c=='-')sign=0; c=gc();}
    while(c>47 && c< 58)
    {    NR = (NR << 3) + (NR << 1) + (c - 48);    c=gc();    }
    return (sign?NR:(-NR));}
inline void fast_out(int x){
         register char buffor[35]; register int i=0;
         do{buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x); i--;
            while(i>=0) putchar(buffor[i--]);
            putchar('\n');
}


int main(){
    
    int t=fin;
    while(t--) {
        
        int n,m;
        n=fin;
        vi a(n);
        int i;
        rep(i,0,n)
        cin>>a[i];
        sort(all(a));
        m=fin;
        vi b(m);
        rep(i,0,m)
        cin>>b[i];
        sort(all(b));
        
        int m1=INT_MAX,m2=INT_MAX;
        
        rep(i,0,n) {
            int lo = lower_bound(all(b),a[i]) - b.begin();
            //cout<<b[lo]-a[i]<<" ";
            if(b[lo]-a[i] < m1 && lo<m)
            m1 = b[lo]-a[i];
        }
        //cout<<endl;
        rep(i,0,m) {
            int lo = (lower_bound(all(a),b[i]) - a.begin());
            //cout<<a[lo]-b[i]<<" ";
            if(a[lo] - b[i] < m2 && lo<n)
            m2 = a[lo]-b[i];
        }
        //cout<<endl;
        
        //cout<<m1<<" "<<m2<<endl;
        
        int ans = m1<m2?m1:m2;
        cout<<ans<<endl;
        
    }
   
    return 0;
}
