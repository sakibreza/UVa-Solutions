#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int,int>mac;
    vector<int>v;

    for(int x=0;x<n;x++)
    {
        int i,j;
        cin>>i>>j;
        mac[i]++;
        v.push_back(j);
    }

    for(int x=0;x<n;x++)
    {
        int home=n-1;
        home+=mac[v[x]];
        int away=2*(n-1)-home;

        cout<<home<<" "<<away<<endl;
    }

    return 0;

    /*vector<int>h;
    vector<int>a;

    int ac[100005],hc[100005];


    for(int x=0;x<t;x++)
    {
        int i,j;
        cin>>i>>j;
        h.push_back(i);
        a.push_back(j);

        ac[x]=0,hc[x]=0;
    }

    for(int x=0;x<t;x++)
    {
        int y=x+1;
        while(y<t)
        {
            if(h[x]!=a[y])hc[x]++,ac[y]++;
            else hc[x]++,hc[y]++;

            if(a[x]!=h[y])ac[x]++,hc[y]++;
            else hc[x]++,hc[y]++;
            y++;
        }
    }

    for(int x=0;x<t;x++)
    {
        cout<<hc[x]<<" "<<ac[x]<<endl;
    }*/

    return 0;
}
