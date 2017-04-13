// chaining in hash( %5 solution with array size of 5)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    struct side
    {
        int val;
        side*ptr;
    };
    struct main
    {
        int val;
        side * cc;
    }a[5];       // main array
    int i,j,n,ele;
    //Creating new array
    cout<<" Enter size of array\n";
    cin>>n;
    for(i=0;i<5;i++)
    {
        a[i].val=-1;
        a[i].cc=NULL;
    }
    for(i=0;i<n;i++)
    {
        cin>>ele;
        j=ele%5;
        if(a[j].val==-1)
            a[j].val=ele;
        else if (a[j].cc==NULL)
        {
            side *m=new side;
            m->val=ele;
            m->ptr=NULL;
            a[j].cc=m;
        }
        else
        {
            side* q=a[j].cc;
            while(q->ptr!=NULL)
            {
                if(q->val==ele)
                    break;
                q=q->ptr;
            }
            if(q->ptr==NULL)
            {
                side *m=new side;
                m->val=ele;
                m->ptr=NULL;
                q->ptr=m;
            }
        }
    }
    //Searching for an element
    cout<<" Enter element to search\n";
    cin>>ele;
    j=ele%5;
    if(a[j].val==ele)
    {
        cout<<" found in main at position "<<j<<endl;
    }
    else
    {
        side *q=a[j].cc;
        while(q!=NULL)
        {
            if(q->val==ele)
            {
                cout<<" found in side at position "<<j<<endl;
                break;
            }
            q=q->ptr;
        }
        if(q==NULL)
            cout<<" Not found\n";
    }
    //Displaying all elements
    cout<<endl;
    for(i=0;i<5;i++)
    {
        if(a[i].val!=-1)
        {
            cout<<a[i].val<<"  with- ";
            side *q=a[i].cc;
            while(q!=NULL)
            {
                cout<<q->val<<" ";
                q=q->ptr;
            }
            cout<<endl;
        }
        else
            cout<<"No element at "<<i<<endl;
    }
    return 0;
}
