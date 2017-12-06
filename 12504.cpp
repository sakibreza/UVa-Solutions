
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

    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        string whole[201],post[201],negt[201],chng[201];
        ll cnt=0,cntp=0,cntn=0,cntc=0;
        map<string,ll>key1,key2;
        map<string,string>value1,value2;
        string s1,s2;
        cin>>s1>>s2;

        string st1,st2;
        for(ll i=1;i<s1.size()-1;i++)
        {
            st1.clear();st2.clear();
            while(s1[i]!=':')
            {
                st1.pb(s1[i++]);
            }
            whole[cnt++]=st1;
            key1[st1]++;
            i++;
            while(s1[i]!=','&&s1[i]!='}')
            {
                st2.pb(s1[i++]);
            }

            value1[st1]=st2;
        }

        st1.clear();st2.clear();
        for(ll i=1;i<s2.size()-1;i++)
        {
             st1.clear();st2.clear();
            while(s2[i]!=':')
            {
                st1.pb(s2[i++]);
            }
            if(!key1[st1])
                whole[cnt++]=st1;
            key2[st1]++;
            i++;
            while(s2[i]!=','&&s2[i]!='}')
            {
                st2.pb(s2[i++]);
            }

            value2[st1]=st2;
        }
//
//        for(ll i=0;i<cnt;i++) cout<<whole[i]<<endl;
//        return 0;

        for(ll i=0;i<cnt;i++)
        {
            if(!key1[whole[i]]&&key2[whole[i]])
                post[cntp++]=whole[i];
            else if(key1[whole[i]]&&!key2[whole[i]])
                negt[cntn++]=whole[i];
            else if(value1[whole[i]]!=value2[whole[i]])
                chng[cntc++]=whole[i];
        }

        sort(post,post+cntp);
        sort(negt,negt+cntn);
        sort(chng,chng+cntc);

        if(!cntp&&!cntc&&!cntn)
            cout<<"No changes"<<endl;
        else
        {
            if(cntp)
            {
                cout<<"+"<<post[0];
                for(ll i=1;i<cntp;i++)
                    cout<<","<<post[i];
                cout<<endl;
            }

            if(cntn)
            {
                cout<<"-"<<negt[0];
                for(ll i=1;i<cntn;i++)
                    cout<<","<<negt[i];
                cout<<endl;
            }

            if(cntc)
            {
                cout<<"*"<<chng[0];
                for(ll i=1;i<cntc;i++)
                    cout<<","<<chng[i];
                cout<<endl;
            }
        }

        cout<<endl;
    }
    return 0;
}








