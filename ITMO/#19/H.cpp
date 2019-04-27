#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int mr(){return (rand()<< 15) + rand();}
struct node{
    int x, y, sz = 0;
    node *l = nullptr, *r = nullptr;
    node(int x):x(x),y(mr()),sz(1){}
};
typedef node* np;
int sz(np rt){return rt ? rt->sz : 0;}
void upd(np rt){if(rt)rt->sz = sz(rt->l) + sz(rt->r) + 1;}
void spl(np rt, np& l, np& r, int x){
    if(!rt) return void(l = r = nullptr);
    if(rt->x < x) {spl(rt->r, rt->r, r, x); l = rt; upd(l);}
    else          {spl(rt->l, l, rt->l, x); r = rt; upd(r);}
}
void mer(np& rt, np l, np r){
    if(!l || !r) return void(rt = l ? l : r);
    if(l->y < r->y) {mer(r->l, l, r->l); rt = r; upd(rt);}
    else            {mer(l->r, l->r, r); rt = l; upd(rt);}
}
void ins(np &rt, int x)
{
    np x1, x2, x3, x0 = new node(x);
    spl(rt, x1, x2, x);
    mer(x3, x1, x0);
    mer(rt, x3, x2);
}
void print(np rt, int d)
{
    if(!rt)return;
    print(rt->l, d);
    cout << '(' << rt->x << ' ' << d << ')' << ' ';
    print(rt->r, d + 1);
}
void era(np &rt, int x)
{
    np x1, x2, x3, x4, x5, x6;
    spl(rt, x1, x2, x + 1);
    spl(x1, x3, x4, x);
    mer(x5, x4->l, x4->r);
    mer(x6, x3, x5);
    mer(rt, x6, x2);
}
int gt(np rt, int i){
    if(i == sz(rt->l))return rt->x;
    if(i < sz(rt->l))return gt(rt->l, i);
    return gt(rt->r, i - sz(rt->l) - 1);
}
int arr[200010];
int main()
{
    srand(42);
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    np rt = new node(arr[0]);
    for(int i = 1; i < n; i++)
    {
        ins(rt, arr[i]);
    }
    for(int i = 0; i < n; i++)
    {
        era(rt, arr[i]);
        cout << gt(rt, (n - 1) / 2) << ' ';
        ins(rt, arr[i]);
    }
    return 0;
}