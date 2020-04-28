#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[50001],b[50001];
ll n,m,k,nheap;
struct data
{
    ll v,i,j;
};
data heap[50001],tam;

void push(ll i,ll j,ll z)
{
    nheap++;
    data s;
    s.v=i;
    s.i=j;
    s.j=z;
    i=nheap;
    ll parent;
    parent=i/2;
    while (parent>0 && heap[parent].v>s.v)
    {
        heap[i]=heap[parent];
        i=parent;
        parent=i/2;
    }
    heap[i]=s;
}

data pop()
{
    data x=heap[1];
    data t=heap[nheap];
    nheap--;
    ll i=1,child;
    while (i*2<=nheap)
    {
        child=i*2;
        if ((child<nheap) && (heap[child+1].v<heap[child].v)) child = child + 1;
        if (heap[child].v>=t.v) break;
        heap[i]=heap[child];
        i=child;
    }
    heap[i]=t;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    ll i;
    cin >>m>>n>>k;
    for (i=1; i<=m; i++) cin >>a[i];
    for (i=1; i<=n; i++) cin >>b[i];
    sort(1+a,1+a+m);
    sort(1+b,1+b+n);
    for (i=1; i<=m; i++) push(a[i]+b[1],i,1);
    for (i=1; i<=k; i++)
    {
        tam=pop();
        cout <<tam.v<<endl;
        push(a[tam.i]+b[tam.j+1],tam.i,tam.j+1);
    }
    return 0;
}
