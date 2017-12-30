#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,maxa=0,maxb=0;
        cin>>n>>m;
        int a[n],b[m];
        int i;
        rep(i,0,n)
        {
            cin>>a[i];
            if(a[i] > maxa)
            maxa = a[i];
        }
        rep(i,0,m)
        {
            cin>>b[i];
            if(b[i] > maxb)
            maxb = b[i];
        }
        
        if(maxa >= maxb)
        cout<<"Godzilla";
        else if(maxb > maxa)
        cout<<"MechaGodzilla";
        cout<<endl;
        
    }
	return 0;
}
