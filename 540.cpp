#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

void clr(ll t)
{

}

int main()
{
    queue<ll>tQ,Q[1001];
    static int team[1000000];
    ll cnt[1001] ={};
    ll t,ks=0;
    while(cin>>t&&t!=0)
    {
        ks++;
        cout<<"Scenario #"<<ks<<endl;
        for(ll i=1;i<=t;i++)
        {
            ll n;
            cin>>n;
            for(ll j=0;j<n;j++)
            {
                ll a;
                cin>>a;
                team[a]=i;
            }
        }

        string cmd;
        while(cin>>cmd&&cmd!="STOP")
        {
            if(cmd[0]=='E')
            {
                ll n;
                cin>>n;
                ll tm=team[n];
                if(!cnt[n])
                {
                    tQ.push(tm);
                }
                Q[tm].push(n);
                cnt[tm]++;
//                cout<<tm<<endl;
            }

            else
            {
                ll tm=tQ.front();
//                cout<<tm<<endl;
                cout<<Q[tm].front()<<endl;
                Q[tm].pop();
                cnt[tm]--;
                if(!cnt[tm])
                {
                    tQ.pop();
                }
            }
        }
        cout<<endl;

        while(!tQ.empty())
        tQ.pop();
    for(ll i=0;i<=t;i++)
        while(!Q[i].empty())
            Q[i].pop();
    for(ll i=0;i<=t;i++)
        cnt[i]=0;
    }
    return 0;
}
