#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int>c;
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int j;
        cin>>j;
        c.insert(j);
    }
    for(auto pos=c.begin();pos!=c.end();++pos)
    {
        cout<<*pos<<" ";
    }
    cout<<endl;
    cout << "lower_bound(4): " << *c.lower_bound(4) << endl;
cout << "upper_bound(4): " << *c.upper_bound(4) << endl;
cout << "equal_range(4): " << *c.equal_range(4).first << " "
<< *c.equal_range(4).second << endl;
cout << endl;
cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
cout << "equal_range(5): " << *c.equal_range(5).first << " "
<< *c.equal_range(5).second << endl;
}
