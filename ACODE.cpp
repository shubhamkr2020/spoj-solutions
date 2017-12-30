#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
    
    string s;
    cin>>s;
    while(s!="0")
    {
        ll l = s.length();
        ll i,dp[l];
        dp[0]=1;
        rep(i,1,l)
        {
            if(s[i]!='0')
            {
                if((s[i-1]-48)*10+(s[i]-48) > 26)
                dp[i] = dp[i-1];
                else {
                    if(i!=1)
                    dp[i] = dp[i-1]+dp[i-2];
                    if(i==1)
                    dp[i] = 2;
                }
            }
            else {
                if((s[i-1]-48)*10+(s[i]-48) > 26 || (s[i-1]-48)*10+(s[i]-48)==0)
                {
                    dp[i]=0;
                    dp[l-1] = 0;
                    break;
                }
                else {
                    if(i!=1)
                    {
                    dp[i] = dp[i-2];
                    dp[i-1] = 0;
                    }
                    if(i==1)
                    {
                    dp[i] = 1;
                    dp[0] = 0;
                }
            }
        }
        }
        
        cout<<dp[l-1];
        cin>>s;
        cout<<endl;
    }
    
	return 0;
}
