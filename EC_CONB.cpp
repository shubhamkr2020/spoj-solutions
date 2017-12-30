#include<bits/stdc++.h>
using namespace std;
int main(){
int n,i,x,z;
cin>>n;
for(i=0;i<n;i++){
cin>>z;
if(z%2==0){
x=0;
while(z) {
x=x|(z&1);
x=x<<1;
z=z>>1;
}
x=x>>1;
z = x;
}
cout<<z<<endl;
}
}
