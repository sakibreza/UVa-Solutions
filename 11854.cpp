#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    ll a[3];
    while(cin>>a[0]>>a[1]>>a[2]&&a[0]!=0&&a[1]!=0&&a[2]!=0)
    {
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
    }
    return 0;
}


