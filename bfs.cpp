//With Queue and dequeue
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,j,k,n,m,l,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        struct node
        {
            int val,dat;
            node * ptr;
        }a[n+1],*pp,*head;
    for(i=0;i<=n;i++)
    {
        a[i].val=-1;
        a[i].dat=0;
        a[i].ptr=NULL;
    }
    while(m--)
    {
        cin>>l>>k>>j;
        pp=&a[l];
        while(pp->ptr!=NULL)
            pp=pp->ptr;
        head=new node;
        head->val=k;
        head->dat=j;
        head->ptr=NULL;
        pp->ptr=head;
        pp=&a[k];
        while(pp->ptr!=NULL)
            pp=pp->ptr;
        head=new node;
        head->val=l;
        head->dat=j;
        head->ptr=NULL;
        pp->ptr=head;
    }
    /*for(i=1;i<=n;i++)
    {
        pp=a[i].ptr;
        cout<<" For i="<<i<<" : ";
        while(pp!=NULL)
        {
            cout<<pp->val<<" ";
            pp=pp->ptr;
        }
    }*/
    deque<ll>s;
   // queue<ll >s;
    //ll s[n+1];
    //for(i=0;i<=n;i++)
      //  s[i]=0;
    i=1;
    j=0;
    ll r=0;
    a[i].val=0;
    while(i<n)
    {
        //cout<<" \nScanning element "<<i<<endl;
        pp=a[i].ptr;
        while(pp!=NULL)
        {
            if(a[pp->val].val==-1)
            {
                //cout<<" Element added are :"<<pp->val<<" ";
                a[pp->val].val=a[i].val+1;
                s.push_back(pp->val);
                //s[j++]=pp->val;
                if(pp->val==n)
                {
                    cout<<a[i].val+1<<endl;
                    break;
                }
            }
            pp=pp->ptr;
        }
        //cout<<"s is "<<s.front()<<endl;
        i=s.front();
        s.pop_front();
        //s.pop();
    }
    }
    return 0;
}
