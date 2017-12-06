#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7
#define INF 1e18

class point
{
public:
    double x,y;
    point(double a,double b)
    {
        x=a;
        y=b;
    }

    double dis(point a)
    {
        double t1=fabs(x-a.x);
        double t2=fabs(y-a.y);
        return sqrt(t1*t1+t2*t2);
    }
};

ll n;
class edge
{
public:
    ll u,v;
    double w;
    edge(ll x,ll y,double z)
    {
        u=x,v=y,w=z;
    }
    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

ll pr[101], rk[101];
vector<edge>vc;

ll find_(ll r)
{
    if(pr[r]==r) return r;
    else return find_(pr[r]);
}

void Union(ll a,ll b)
{
    if(rk[a]<rk[b])
        pr[a]=find_(b);
    else
    {
        pr[b]=find_(a);
        if(rk[a]==rk[b])
        rk[a]++;
    }
}

double MST()
{
    memset(pr,0,sizeof pr);
    sort(vc.begin(),vc.end());
    for(ll i=1;i<=n;i++)
        pr[i]=i,rk[i]=0;
    ll cnt=0;
    double mcost=0;
    for(ll i=0;i<vc.size();i++)
    {
        ll u=find_(vc[i].u);
        ll v=find_(vc[i].v);

        if(u!=v)
        {
            Union(u,v);
            cnt++;
            mcost+=vc[i].w;
            if(cnt==n-1)
                break;
        }
    }

    return mcost;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    bool flag=false;
    while(t--)
    {
        vc.clear();
        vector<point>vp;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            double x,y;
            cin>>x>>y;
            point temp(x,y);
            vp.pb(temp);
        }

        for(ll i=0;i<vp.size();i++)
        {
            for(ll j=i+1;j<vp.size();j++)
            {
                point a=vp[i];
                point b=vp[j];
                double dis=a.dis(b);
                vc.pb(edge(i,j,dis));
            }
        }
        if(flag)cout<<endl;
        cout<<fixed<<setprecision(2)<<MST()<<endl;
        flag=true;
    }
    return 0;
}
