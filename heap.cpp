//Every child is smaller/larger than its parent
#include<bits/stdc++.h>
using namespace std;
vector<int>a,B;
void swaa(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void heapify(int st,int siz)
{
    int i,j;
    for(i=st;2*i+1<siz;)
    {
        j=2*i+1;
        if(j+1==siz)
        {
            if(a[j]<a[i])
                {
                    swaa(a[j],a[i]);
                }
                break;
        }
        else
        {
            if(a[j]<a[i]&&a[j]<=a[j+1])
                {
                    swaa(a[j],a[i]);
                    i=j;
                }
            else if(a[j+1]<a[i]&&a[j+1]<a[j])
                {
                    swaa(a[j+1],a[i]);
                    i=j+1;
                }
            else
                break;
        }
    }
}
int main()
{
    //creating heap
    int i,n,j,j1,ele;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        a.push_back(j);
    }
    for(i=n/2;i>=0;i--)
    {
        heapify(i,n);
    }/*
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;*/
    //Inserting a new element into heap
    /*int p;
    cin>>p;
    while(p--)
    {
      cout<<"\nEnter new element\n";
    cin>>ele;
    a.push_back(ele);
    if(n%2==0)
        i=n/2-1;
    else
        i=n/2;
        j=n;
        n++;
    while(i>=0)
    {
        if(a[i]>a[j])
            swaa(a[i],a[j]);
        else
        break;
        j=i;
        if(i%2==0)
            i=i/2-1;
        else
            i=i/2;
    }
    for(i=0;i<n;i++)
       cout<<a[i]<<" ";
    }*/
    //Deleting an element
   /*cout<<" Enter element to be deleted\n";
    cin>>ele;
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
            break;
    }
    if(i==n)
        cout<<" No such element exists\n";
    else
    {
        swaa(a[i],a[n-1]);
        a.pop_back();
        n--;
        heapify(i,n);
    }*/
   //Representing the array in sorted form
   int nn=n;
   for(i=0;i<nn;i++)
   {
       B.push_back(a[0]);
       swaa(a[0],a[n-1]);
       n--;
       heapify(0,n);
   }
   cout<<"Sorted Array\n";
    i=0;
   j1=log2(nn+1);
   int cc;
   for(j=1;i<nn;j=j*2)
   {
       ele=j;
       cc=j1;
       j1--;
      while(cc--)
       cout<<" ";
       while(ele--)
       {
           cout<<B[i]<<"  ";
           i++;
           if(i==nn)
            break;
       }
       cout<<endl<<endl;
}
    return 0;
}
