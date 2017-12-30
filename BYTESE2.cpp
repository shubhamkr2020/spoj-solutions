#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++)
#define ZERO(a) memset(a,0,sizeof(a))
#define lastbit(x) (x&(-x)) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define fin scan_int()
#define pd(x) printf("%d",x)
#define newl printf("\n")
#define xx first
#define yy second
#define mod 1000000007
#define FIND(x,y) ((y).find((x))!=(y).end())
#define dbg(a) cerr << #a << endl;
#define dbgv(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define compress(s) sort(all(s)); s.resize(unique(s.begin(),s.end())-s.begin());
#define strtoint(s,n) if (!(istringstream(s) >> n) ) n = 0;
typedef long long ll;
typedef vector<int > vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<string,int > psi; 
typedef pair<int ,int > pii;

string inttostr(int str){stringstream stream;stream << str;return stream.str();}
ll modexpo(ll a,ll b,ll n){ll d=1;while(b){if(b&1)d=(d*a)%n;b>>=1;a=(a*a)%n;}return d;}
ll expo(ll a,ll b){ll d=1;while(b){if(b&1)d=d*a;b>>=1;a=a*a;}return d;}
inline ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b) {return (a*b)/gcd(a,b);}
ll inv(ll a,ll m){return modexpo(a,m-2,m);}

/*/////////////////////////////////////////////*/////////////////////////////////////////////////////////
#define gc getchar
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
////////////////////////////////////////////////////////////////////////////////////////////////////////*/

bool cmp(pii l, pii r) {
    if(l.xx == r.xx) return l.yy < r.yy;
    return l.xx < r.xx;
}

int main(){
    int t=fin;
    while(t--) {
        int n=fin;
        pii a[n];
        int i;
        rep(i,0,n) {
            a[i].xx = fin;
            a[i].yy = fin;
        }
        
        sort(a,a+n,cmp);
        /*
        set<pii > st;
        st.insert(a[0]);
        
        int ans=INT_MIN;
        i=0;
        int save=0;
        while(i<n && save<n) {
            while(a[i].xx < a[save].yy)
            st.insert(a[i]);
            i++;
        }*/
        
        //rep(i,0,n) cout<<a[i].xx<<" "<<a[i].yy<<endl;
        
        int ist[n+1] = {0};
        int c=0, ans = INT_MIN;
        rep(i,0,n) {
            int j;
            c=1;
            rep(j,0,i) {
                if(ist[j]) {
                    if(a[j].yy < a[i].xx)
                    ist[j] = 0;
                    else c++;
                }
            }
            ans = max(ans, c);
            ist[i] = 1;
            //cout<<i<<" "<<c<<endl;
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}
