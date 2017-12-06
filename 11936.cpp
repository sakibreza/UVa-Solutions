#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a[3];
        for(ll i=0;i<3;i++) cin>>a[i];
        sort(a,a+3);
        if(a[0]+a[1]>a[2])cout<<"OK"<<endl;
        else cout<<"Wrong!!"<<endl;
    }
    return 0;
}


