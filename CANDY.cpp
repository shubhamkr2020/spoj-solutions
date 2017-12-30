#include<bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked

#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1)
        break;
        
        int a[n],s=0,i;
        rep(i,0,n)
        {
            cin>>a[i];
            s += a[i];
        }
        float co = 1.0*s/n;
        int f,j;
        if(floor(co) == co)
        {
            int ans=0;
            rep(i,0,n)
            {
                if(a[i]>co)
                ans += a[i]-co;
            }
            
            cout<<ans;
            
        }
        else
        cout<<"-1";
        
        cout<<endl;
    }
    return 0;
}
