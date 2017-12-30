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
    string s;
    cin>>t;
    while(t--)
    {
        string s;
        getline(cin,s);
        while(s.length() == 0)
        getline(cin,s);
        int i=0,l=s.length();
        int t[3];
        t[0]=0;t[1]=0;t[2]=0;
        int n=0,m=0,num;
            num=0;
        for(; s[i] != ' '; i++)
        {
            if(s[i]>47 && s[i]<58)
                num = num*10 + s[i]-48;
            else
            t[0]++;
        }
        i++;
        if(t[0]==0)
        n=num;
        while(s[i]!=' ')
        i++;
        i++;
            num=0;
        while(s[i]!=' ')
        {
            if(s[i]>47 && s[i]<58)
            num = num*10 + s[i]-48;
            else
            t[1]++;
            i++;
        }
        if(!n)
        n=num;
        else if(t[1]==0)
        m=num;
        i++;
        while(s[i] != ' ')
        i++;
        i++;
            num=0;
        while(i<l)
        {
            if(s[i]>47 && s[i]<58)
            num = num*10 + s[i]-48;
            else
            t[2]++;
            i++;
        }
        if(!m)
        m=num;
        int ans=0;
        if(t[0]!=0)
        {
            ans = m-n;
            cout<<ans<<" + "<<n<<" = "<<m<<endl;
        }
        else if(t[1]!=0)
        {
            ans = m-n;
            cout<<n<<" + "<<ans<<" = "<<m<<endl;
        }
        else {
            ans = n+m;
            cout<<n<<" + "<<m<<" = "<<ans<<endl;
        }
        
    }
	return 0;
}
