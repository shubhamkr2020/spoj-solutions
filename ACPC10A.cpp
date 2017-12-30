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
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==0 && b==0 && c==0)
        break;
        
        int z,ans;
        if(b-a == c-b)
        {
            z=0;
            ans = c+b-a;
        }
        else
        if((1.0*b/a) == (1.0*c/b))
        {
            z=1;
            ans = c*1.0*b/a;
        }
        if(z)
        cout<<"GP";
        else cout<<"AP";
        cout<<" "<<ans;
        
        cout<<endl;
    }
    return 0;
}
