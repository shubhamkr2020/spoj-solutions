#include<bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked

#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int reverse(int n)
{
    int l=0,m=n,ans=0;
    while(m)
    {
        ans = 10*ans + m%10;
        m=m/10;
    }
    return ans;
    
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<reverse(reverse(n)+reverse(m))<<endl;
    }
    return 0;
} 






