
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

queue<ll>q;
priority_queue<ll>pq;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        while(!pq.empty())
            pq.pop();
        while(!q.empty())
            q.pop();

        ll n,m,res=0;
        cin>>n>>m;
        for(ll i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            q.push(a);
            pq.push(a);
        }

        while(1)
        {
            if(q.front()==pq.top())
            {
                res++;
                if(m==0) break;
                m--;
//                cout<<m<<endl;
                q.pop();
                pq.pop();
            }

            else
            {
                if(m==0)
                    m=q.size()-1;
                else
                    m--;
//                cout<<m<<endl;
                q.push(q.front());
                q.pop();
            }
        }
        cout<<res<<endl;
    }

    return 0;
}







