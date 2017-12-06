#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        double s=(a+b+c)/2.0;
        double area_t=sqrt(s*(s-a)*(s-b)*(s-c));
        double R=(a*b*c)/(4*area_t);
        double r=sqrt((s-a)*(s-b)*(s-c)/s);

        double yellow,blue,red;
        yellow=PI*R*R-area_t;
        red=PI*r*r;
        blue=area_t-red;
        cout<<fixed<<setprecision(4)<<yellow<<" "<<blue<<" "<<red<<endl;
    }
    return 0;
}



