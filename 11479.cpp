#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    ll t,k=0;
    cin>>t;
    while(t--)
    {
        k++;
        ll a[3];
        for(ll i=0;i<3;i++) cin>>a[i];
        sort(a,a+3);
        cout<<"Case "<<k<<": ";
        if(a[0]+a[1]>a[2])
        {
            if(a[0]==a[1]&&a[1]==a[2])cout<<"Equilateral"<<endl;
            else if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2])cout<<"Isosceles"<<endl;
            else cout<<"Scalene"<<endl;
        }
        else cout<<"Invalid"<<endl;
    }
    return 0;
}



