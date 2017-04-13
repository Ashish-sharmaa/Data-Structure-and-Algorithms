#include <bits/stdc++.h>
using namespace std;
struct heapfun
{
    char val;
    int freq;
    heapfun *left, *right;

    heapfun(char val1,int freq1)
    {
        left = right = NULL;
        val =val1;
        freq = freq1;
    }
};
struct comp
{
    bool operator()(heapfun* a, heapfun* b)
    {
        return (a->freq > b->freq);
    }
};
void result(struct heapfun* pp, string s)
{
    if (!pp)
        return;

    if (pp->val!= '*')
        cout <<pp->val<< " with " << s <<endl;
    result(pp->left, s + "0");
    result(pp->right, s + "1");
}
void fun(char a[], int b[], int n)
{
    struct heapfun *left, *right, *temp;
    priority_queue<heapfun*, vector<heapfun*>, comp>s;
    for (int i = 0; i < n; ++i)
        s.push(new heapfun(a[i], b[i]));
    while (s.size() != 1)
    {
        left = s.top();
        s.pop();
        right = s.top();
        s.pop();
        temp = new heapfun('*', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        s.push(temp);
    }
    result(s.top(), "");
}
int main()
{
    int i,j,n,k;
    cout<<"Enter no. of values\n";
    cin>>n;
    char a[n];
    int b[n];
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    fun(a, b,n);
    return 0;
}
