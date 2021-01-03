/**Problem Link -> https://codeforces.com/gym/101628/problem/K **/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mxn=1e6+10;
int node[mxn][26],cn[mxn],cnt=0;
set<int>s[mxn];
set<int>endmark[mxn];
void Insert(string str,int pos)
{
    int cur=0,l=str.size();
    for(int i=0;i<l;i++)
    {
        int idx=str[i]-'a';
        if(node[cur][idx]==0)
            node[cur][idx]=++cnt;
        cur=node[cur][idx];
        cn[cur]++;
        s[cur].insert(pos);
    }
    endmark[cur].insert(pos);
}
void query_type_1(string str,int pos)
{
    int cur=0,l=str.size();
    for(int i=0;i<l;i++)
    {
        int idx=str[i]-'a';
        cur=node[cur][idx];
        cn[cur]--;
        s[cur].erase(pos);
    }
    endmark[cur].erase(pos);
}
bool check(set<int>&x,int l,int r)
{
    //return x.lower_bound(l)!=x.upper_bound(r);
    auto it=x.lower_bound(l);
    if(it!=x.end() && *it<=r)
        return true;
    return false;
}
bool query_type_2(int l,int r,string str)
{
    int cur=0,len=str.size();
    for(int i=0;i<len;i++)
    {
        int idx=str[i]-'a';
        if(node[cur][idx]==0 || cn[node[cur][idx]]==0)
            return false;
        cur=node[cur][idx];
        if(!check(s[cur],l,r))
            return false;
        if(check(endmark[cur],l,r))
            return true;
    }
    return false;
}
bool query_type_3(int l,int r,string str)
{
    int cur=0,len=str.size();
    for(int i=0;i<len;i++)
    {
        int idx=str[i]-'a';
        if(node[cur][idx]==0 || cn[node[cur][idx]]==0)
            return false;
        cur=node[cur][idx];
        if(!check(s[cur],l,r))
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string str[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        Insert(str[i],i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int pos;
            string xd;
            cin>>pos>>xd;
            query_type_1(str[pos],pos);
            Insert(xd,pos);
            str[pos]=xd;
        }
        else if(type==2)
        {
            int l,r;
            string xd;
            cin>>l>>r>>xd;
            if(query_type_2(l,r,xd))
                cout<<"Y"<<endl;
            else   
                cout<<"N"<<endl;
        }
        else  
        {
            int l,r;
            string xd;
            cin>>l>>r>>xd;
            if(query_type_3(l,r,xd))
                cout<<"Y"<<endl;
            else   
                cout<<"N"<<endl;
        }
    }
    return 0;
}
