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
#define mod 1000000007
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

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);
/* function that returns nth Fibonacci number */
ll fibo(ll n) {
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
void power(ll F[2][2], ll n) {
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
  power(F, n/2);
  multiply(F, F);
  if (n%2 != 0)
     multiply(F, M);
}
void multiply(ll F[2][2], ll M[2][2]) {
  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0]+mod)%mod;
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1]+mod)%mod;
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0]+mod)%mod;
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1]+mod)%mod;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}


int main() {
    
    int t=fin;
    while(t--) {
        int n=fin,m=fin;
        cout<<(fibo(m+2)-fibo(n+1)+mod)%mod<<endl;
    }
    
    return 0;
}
