#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
char s;ll n;
ll heap[15001],a[15001];
void Up(ll i)
{
    ll x=heap[i],p=i/2;
    while (p>0 && heap[p]<x)
    {
        heap[i]=heap[p];
        i=p;
        p=i/2;
    }
    heap[i]=x;
}
void Down(ll i)
{
    ll x=heap[i],c;
    while (2*i<=n)
    {
        c=2*i;
        if (c+1<=n && heap[c+1]>heap[c]) c++;
        if (x>=heap[c]) break;
        heap[i]=heap[c];
        i=c;
    }
    heap[i]=x;
}
void pop(ll i)
{
    ll x=heap[1];
    heap[1]=heap[n];
    n--;
    Down(1);
}
int main()
{
    ll i;
    while ((cin>>s))
    {
        if (n<15000 && s=='+' )
        {
            ll d;
            cin >>d;
            n++;
            heap[n]=d;
            Up(n);
        }
        if (s=='-' && n>0)
        {
            ll x=heap[1];
            while (x==heap[1] && n>0)
            {
                pop(1);
            }
        }
    }
    ll k=0;
    while (n>0)
    {
        k++;
        a[k]=heap[1];
        while (n>0 && heap[1]==a[k]) pop(1);
    }
    cout <<k<<endl;
    for (i=1;i<=k;i++) cout <<a[i]<<endl;
    return 0;
}
