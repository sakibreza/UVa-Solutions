#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

ll id;
map<set<ll>,ll>m;
stack<set<ll> >stk;

void set_id(set<ll>st)
{
    if(m.count(st)) return;
    m[st]=id++;
}

void push()
{
    set<ll>st;
    set_id(st);
    stk.push(st);
}

void dup()
{
    stk.push(stk.top());
}

void uni()
{
    set<ll>st1,st2;
    st1=stk.top();
    stk.pop();
    st2=stk.top();
    stk.pop();
    for(set<ll>::iterator it=st1.begin();it!=st1.end();it++)
    {
        st2.insert(*it);
    }

    set_id(st2);
    stk.push(st2);
}

void add()
{
    set<ll>s1,s2;
    s1=stk.top();
    stk.pop();
    s2=stk.top();
    stk.pop();
    s2.insert(m[s1]);
    set_id(s2);
    stk.push(s2);
}

void intersect()
{
    set<ll>s,s1,s2;
    s1=stk.top();
    stk.pop();
    s2=stk.top();
    stk.pop();
    for(set<ll>::iterator it=s1.begin();it!=s1.end();it++)
    {
        if(s2.count(*it))
            s.insert(*it);
    }
    set_id(s);
    stk.push(s);
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        id=0;
        m.clear();
        while(!stk.empty())
        {
            stk.pop();
        }

        ll n;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            if(s=="PUSH") push();
            else if(s=="DUP") dup();
            else if(s=="UNION") uni();
            else if(s=="INTERSECT") intersect();
            else if(s=="ADD") add();
            cout<<stk.top().size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}

