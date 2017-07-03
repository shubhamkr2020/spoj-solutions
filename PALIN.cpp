#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j; i<k; i++)
#define rrep(i,j,k) for(i=j; i>=k; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

void printArray (int arr[], int n);
int AreAll9s (int num[], int n );
 
void generateNextPalindromeUtil (int num[], int n )
{
    int mid = n/2;
 
    bool leftsmaller = false;
 
    int i = mid - 1;
 
    int j = (n % 2)? mid + 1 : mid;
 
    while (i >= 0 && num[i] == num[j])
        i--,j++;
 
    if ( i < 0 || num[i] < num[j])
        leftsmaller = true;
 
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
 
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        if (n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; // copy mirror to right
        }
    }
}
 
void generateNextPalindrome( int num[], int n )
{
    int i;
    if( AreAll9s( num, n ) )
    {
        printf( "1");
        for( i = 1; i < n; i++ )
            printf( "0" );
        printf( "1\n" );
    }
 
    else
    {
        generateNextPalindromeUtil ( num, n );
 
        printArray (num, n);
    }
}
 
int AreAll9s( int* num, int n )
{
    int i;
    for( i = 0; i < n; ++i )
        if( num[i] != 9 )
            return 0;
    return 1;
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n = s.length();
	    int num[n];
	    int i;
	    rep(i,0,n)
	    num[i] = int(s[i]-48);
	    generateNextPalindrome(num,n);
	}
	return 0;
}
