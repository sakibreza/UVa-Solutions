#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007
#define INF 1e12

using namespace std;

double x[210],y[210],dis[210][210];

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(dis,0,sizeof dis);

        cin>>x[0]>>y[0]>>x[1]>>y[1];

        ll k=2;
        string s;
        getline(cin,s);
        while(getline(cin,s) && s!="")
        {
            stringstream ss;
            ss<<s;
            ss>>x[k]>>y[k];
            k++;
            while(ss>>x[k]>>y[k] && x[k]!=-1)
            {
                dis[k][k-1] = dist(x[k],y[k],x[k-1],y[k-1]);
//                cout<<x[k]<<" "<<y[k]<<" "<<x[k-1]<<" "<<y[k-1]<<endl;
                dis[k-1][k] = dis[k][k-1];
                k++;
            }
        }

        for(ll i=0;i<k;i++)
        {
            for(ll j=0;j<k;j++)
            {
                if(dis[i][j]==0)
                    dis[i][j]=dist(x[i],y[i],x[j],y[j])*4;

//                cout<<i<<" "<<j<<" >> "<<dis[i][j]<<endl;
//                cout<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<" "<<dist(x[i],y[i],x[j],y[j])<<endl;
            }
        }

        for(ll l=0;l<k;l++)
        {
            for(ll i=0;i<k;i++)
            {
                for(ll j=0;j<k;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
                }
            }
        }

        cout<<(ll)round(dis[0][1]*6.0/4000.0)<<endl;

        if(t) cout<<endl;
    }
}
