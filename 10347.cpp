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
    double m1,m2,m3;
    while(cin>>m1>>m2>>m3)
    {
        double s=(m1+m2+m3)/2.0;
//        cout<<fixed<<setprecision(2)<<s<<endl;
        double area=(4/3.0)*sqrt(s*(s-m1)*(s-m2)*(s-m3));
        if(area>0.0)cout<<fixed<<setprecision(3)<<area<<endl;
        else cout<<fixed<<setprecision(3)<<-1.000<<endl;

    }
    return 0;
}



