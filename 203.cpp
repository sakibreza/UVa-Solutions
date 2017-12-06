
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

string author,book;

void string_process(string s)
{
     string res;
//     getline(cin,s);
     ll i=1;
     while(s[i]!='"')
     {
         res.pb(s[i]);
         i++;
     }
     book=res;
     res.clear();
     i++;
     while(s[i]==' '||(s[i]=='b'&&s[i+1]=='y'))
     {
        if(s[i]=='b'&&s[i+1]=='y')i+=2;
        else i++;
     }

     while(s[i]!='\0')
     {
         res.pb(s[i]);
         i++;
     }
     author=res;
}

map<string,ll>serial;
map<ll,bool>borrowed;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    string s,dummy;
    vector<pair<string,string> >v,returned;
    while(getline(cin,s))
    {
//        cout<<s<<endl;
        if(s=="END") break;
//        getline(cin,dummy);
        string_process(s);
//        cout<<
        v.pb(mp(author,book));
    }
//    cout<<"y"<<endl;

    sort(v.begin(),v.end());

    for(ll i=0;i<v.size();i++)
    {
        serial[v[i].second]=i;
        borrowed[i]=false;
//        cout<<v[i].second<<" "<<serial[v[i].second]<<endl;
    }
//    cout<<"Y"<<endl;
    string s1,s2;
    while(cin>>s1)
    {
        if(s1=="END")break;
//        getline(cin,dummy);
        if(s1=="SHELVE") goto shelve;
        getline(cin,s2);
        s2=s2.substr(2,s2.size()-3);
//         cout<<s1<<endl;
//        cout<<s1<<endl<<s2<<endl;
        if(s1=="BORROW")
        {
            ll pos=serial[s2];
            borrowed[pos]=true;
        }

        else if(s1=="RETURN")
        {
//            cout<<"Y"<<endl;
//            cout<<s2<<endl;
            ll pos=serial[s2];
//            cout<<pos<<" "<<v[pos].second<<endl;
            returned.pb(v[pos]);
        }

        else if(s1=="SHELVE")
        {
            shelve:
//            cout<<returned.size()<<endl;
            sort(returned.begin(),returned.end());

            for(ll i=0;i<returned.size();i++)
            {
                ll pos=serial[returned[i].second];
                bool flag=false;
                ll after=pos-1;

                while(after>=0)
                {
                    if(borrowed[after]==false)
                    {
                        flag=true;
                        break;
                    }
                    after--;
                }

                if(flag)
                {
                    cout<<"Put \""<<v[pos].second<<"\" after \""<<v[after].second<<"\""<<endl;
                }
                else
                {
                    cout<<"Put \""<<v[pos].second<<"\" first"<<endl;
                }
                borrowed[pos]=false;
            }
            cout<<"END"<<endl;

            returned.clear();
//            return 0;
        }
    }
    return 0;
}









