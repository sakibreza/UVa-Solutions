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
        double l;
        cin>>l;
        double w=l*6/10.0;
        double r=l/5.0;
        double area=PI*r*r;
        cout<<fixed<<setprecision(2)<<area<<" "<<l*w-area<<endl;
    }
    return 0;
}


