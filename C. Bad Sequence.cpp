#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,cn=0;
    cin>>n;
    string str;
    cin>>str;
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
            st.push('(');
        else
        {
            if(st.empty())
                cn++;
            else
                st.pop();
        }
    }
    if((cn==1 && st.size()==1)|| (st.empty() && cn==0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
