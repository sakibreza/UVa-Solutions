
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==0||b==0||c==0)
        {
            cout<<"The radius of the round table is: "<<fixed<<setprecision(3)<<0.000<<endl;
        }

        else
        {
            double s=(a+b+c)/2.0;
            double area=sqrt(s*(s-a)*(s-b)*(s-c));
            cout<<"The radius of the round table is: "<<fixed<<setprecision(3)<<area/s<<endl;

        }
    }
    return 0;
}



