#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n;
    while(cin>>n&&n)
    {
        queue<ll>q;
        for(ll i=1;i<=n;i++)
            q.push(i);

        cout<<"Discarded cards:";
        while(q.size()>= 2)
        {
            cout<<" "<<q.front();
            q.pop();

            ll temp=q.front();
            q.pop();
            if(!q.empty())
                cout<<",";
            q.push(temp);
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}




