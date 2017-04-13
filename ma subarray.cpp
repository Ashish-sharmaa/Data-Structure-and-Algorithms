// Finding max. subarray in a given array with +ive and -ive nos.
#include<iostream>
using namespace std;
int fin[3];  //Array storing final result after each recursion ends(first- val,second - i and final j)
void comp(int s[],int st,int mid,int ed)
{
    int i,j,q=1;
    int b[mid-st+1],c[2];
    c[0]=s[mid];
    c[1]=mid;
    b[mid-st]=s[mid];
    for(j=mid-1;j>=st;j--)    // first half before mid
    {
        b[mid-st-q]=b[mid-st-q+1]+s[j];
        if(b[mid-st-q]>c[0])
        {
            c[0]=b[mid-st-q];
            c[1]=j;
        }
        q++;
    }
    q=1;
    int j1,c1[3],b1[ed-mid];
    c1[0]=s[mid+1];
    c1[1]=mid+1;
    b1[0]=c1[0];
    for(j1=mid+2;j1<=ed;j1++)
    {
       b1[q]=b1[q-1]+s[j1];
       if(b1[q]>c1[0])
       {
           c1[0]=b1[q];
           c1[1]=j1;
       }
       q++;
    }
    c[0]+=c1[0];
    if(c[0]>fin[0])
    {
        fin[0]=c[0];
        fin[1]=c[1];
        fin[2]=c1[1];
    }
}
void rec(int s[],int low,int high)   //Dividing upto three elements size
{
    int mid=(low+high)/2,i;
    if(high-low<=2)
    {
        int b[high-low+1],c=0;
        b[0]=s[low];
        for(i=low+1;i<=high;i++)   //getting values stored in b[] starting from low element
        {
            c++;
            b[c]=b[c-1]+s[i];
            if(b[c]>fin[0])
            {
                fin[0]=b[c];
                fin[2]=i;
                fin[1]=low;
            }
        }
        //getting values for low +1 and other elements
        int m,j,d,siz=0;
        for(m=low;m<high;m++)
        {
            d=siz;
            siz++;
            while(d<c)
            {
                d++;
                b[d]=b[d]-s[m];
                if(b[d]>fin[0])
                {
                    fin[0]=b[d];
                    fin[1]= m+1;
                    fin[2]=d;
                }
            }
        }
    }
    else
        {
            rec(s,low,mid);
            rec(s,mid+1,high);
            comp(s,low,mid,high);
        }
}
int main()
{
    int i,n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int s[n];
    cin>>s[0];
    fin[0]=s[0];
    fin[1]=fin[2]=0;
    for(i=1;i<n;i++)
        {
            cin>>s[i];
            if(fin[0]<s[i])
            {
                fin[0]=s[i];
                fin[1]=fin[2]=i;
            }
        }
    rec(s,0,n-1);
    cout<<" Final result  value is\t"<< fin[0]<<" found between "<<fin[1]+1<<" and "<<fin[2]+1<<endl;
}

