#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool Binary_Search(ll *a,ll left,ll right,ll num)
{
    ll mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==num)
            return true;
        else if(a[mid]<num)
            left=mid+1;
        else
            right=mid-1;
    }
    return false;
}
int main()
{
    ll n;
    cin>>n;
    ll arr[n],brr[n],s=0,l=0,ans=0;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
        if(i)
            arr[i]+=arr[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        l+=brr[i];
        found=Binary_Search(arr,0,i-1,l);
        if(found)
            ans=max(ans,l);
    }
    cout<<ans<<endl;
    return 0;
}
