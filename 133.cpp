#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll nex[30],pre[30];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,k,m;
    while(cin>>n>>k>>m&&((n||k)||m))
    {
        for(ll i=1;i<=n;i++)
        {
            nex[i]=i+1;
            pre[i]=i-1;
        }
        nex[n]=1,pre[1]=n;

        ll used[30]={};
        ll id1=1,id2=n;
        ll flag=0;
        while(n)
        {
            for(ll i=1;i<k;i++)
                id1=nex[id1];
            for(ll i=1;i<m;i++)
                id2=pre[id2];

            if(flag) cout<<",";
            flag=1;

            if(id1==id2)
            {
                printf("%3lld",id1);
                used[id1]=1;
                nex[pre[id1]]=nex[id1];
                pre[nex[id1]]=pre[id1];
                n--;
            }
            else
            {
                printf("%3lld%3lld",id1,id2);
                n--;n--;
                used[id1]=used[id2]=1;
                nex[pre[id1]]=nex[id1];
                pre[nex[id1]]=pre[id1];
                nex[pre[id2]]=nex[id2];
                pre[nex[id2]]=pre[id2];
            }

            if(!n) break;

            while(used[id1])
                id1=nex[id1];
            while(used[id2])
                id2=pre[id2];
        }
        cout<<endl;
    }

    return 0;
}
