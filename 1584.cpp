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
    ll t,arr[20],temp[20];
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll i,sum=0;
        for(i=0;i<1000;i++)
        {
            for(ll j=0;j<n;j++)
                temp[j]=abs(arr[(j+1)%n]-arr[j]);
            for(ll j=0;j<n;j++)
                arr[j]=temp[j];

            sum=0;
            for(ll j=0;j<n;j++)
            {
//                cout<<arr[j]<<" ";
                sum+=arr[j];
            }
//            cout<<endl;
            if(sum==0)break;
        }

        if(!sum)cout<<"ZERO"<<endl;
        else cout<<"LOOP"<<endl;
    }
    return 0;
}




