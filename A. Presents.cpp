#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        mp[a]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<mp[i]<<" ";
    return 0;
}
