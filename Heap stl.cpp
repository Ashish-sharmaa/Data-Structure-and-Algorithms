#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll>a;
    ll i,j,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j;
        a.push_back(j);
    }
    make_heap(a.begin(),a.end());  //! Max. Heapify( complexity linear)
    for(auto pos=a.begin();pos!=a.end();++pos)
        cout<<*pos<<" ";
    cout<<endl;
    pop_heap(a.begin(),a.end());  //! Complexity O(logn)
    a.pop_back();  //! As after pop_heap first element moves to the last position so have to decrease size by 1
    for(auto pos=a.begin();pos!=a.end();++pos)
        cout<<*pos<<" ";
    cout<<endl;
    a.push_back(99);
    make_heap(a.begin(),a.end());  //! Complexity O(logn)
    for(auto pos=a.begin();pos!=a.end();++pos)
        cout<<*pos<<" ";
    cout<<endl;
    sort_heap(a.begin(),a.end());   //! No longer a heap
    for(auto pos=a.begin();pos!=a.end();++pos)   //! Ascending order of elements
        cout<<*pos<<" ";
    return 0;
}
