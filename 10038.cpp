#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair



int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll arr[3010],cum[3010],n;
    while(cin>>n)
    {
        bool flag=true;

        for(ll i=0;i<n;i++) cin>>arr[i];

        for(ll i=0;i<n-1;i++) cum[i]=abs(arr[i+1]-arr[i]);

        sort(cum,cum+n-1);

        for(ll i=1;i<n;i++)
        {
            if(cum[i]==cum[i-1])
            {
                flag=0;
                break;
            }
        }

        if(flag) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;

    }
    return 0;
}
