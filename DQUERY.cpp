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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int> psi; 
typedef pair<int,int> pii;
inline int scan_int() {
   int NR=0,sign=1;    char c=gc();
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

int a[1000009],cnt[1000009],ans,bound;
struct query {
    int l,r,ind;
};

void Add(int p) {
    //cout<<"added "<<p<<endl;
    cnt[a[p]]++;
    if(cnt[a[p]] == 1)
    ans++;
}
void Remove(int p) {
    //cout<<"removed "<<p<<endl;
    cnt[a[p]]--;
    if(cnt[a[p]] == 0)
    ans--;
}
bool cmp(query x,query y) {
    if(x.l/bound == y.l/bound)
    return x.r > y.r;
    
    return x.l/bound < y.l/bound;
}
 
int main(){
    
    int n=fin;
    bound = sqrt(n);
    int i;
    rep(i,1,n+1) a[i]=fin;
    
    int q=fin;
    vector<query> v;
    rep(i,0,q) {
        int x=fin,y=fin;
        v.pb({x,y,i});
    }
    
    sort(all(v),cmp);
    //rep(i,0,q) cout<<v[i].l<<" "<<v[i].r<<" "<<v[i].ind<<endl;
    
    int cl=v[0].l,cr=v[0].l-1;
    vector<pii > ansv;
    rep(i,0,q) {
        while(cl<v[i].l && cl<n+1) {
      //      cout<<"a";
            Remove(cl);
            cl++;
        }
        while(cl>v[i].l && cl>0) {
        //    cout<<"b";
            Add(cl-1);
            cl--;
        }
        while(cr>v[i].r && cr>0) {
          //  cout<<"c";
            Remove(cr);
            cr--;
        }
        while(cr<v[i].r && cr<n+1) {
            //cout<<"d";
            Add(cr+1);
            cr++;
        }
        //cout<<ans<<endl;
        ansv.pb({v[i].ind,ans});
    }
    
    sort(all(ansv));
    
    rep(i,0,q) {
    	pd(ansv[i].yy);
    	newl;
    }
    
    return 0;
}



