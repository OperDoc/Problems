#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
#define mp make_pair
#define pb push_back
#define al(a) a.begin(),a.end() 
#define pr pair
#define ve vector
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int mr(){return (rand() << 15) + rand();}
struct nd{
    int x, y, sz = 0, mmi;
    nd *l, *r;
    nd():l(nullptr),r(nullptr){}
    nd(int x):x(x),y(mr()),l(nullptr),r(nullptr),sz(1){}
};
typedef nd* pn;

void mer(pn& rt, pn l, pn r){
    if(!l || !r) return void(rt = l ? l : r);
    if(l->y < r->y) {mer(l->r, l->r, r); rt = l;}
    else            {mer(r->l, l, r->l); rt = r;}
}
void spl(pn rt, pn& l, pn& r, int x){
    if(!rt) return void(l = r = nullptr);
    if(rt->x < x) {spl(rt->r, rt->r, r, x); l = rt;}
    else          {spl(rt->l, l, rt->l, x); r = rt;}
}
void inter (pn& rt, pn l, pn r) {
	if (!l || !r)  return void(rt = nullptr);
	if (l->y < r->y)  swap (l, r);
	pn Lt, Rt;
	spl (r, Lt, Rt, l->x);
    inter (l->l, l->l, Lt);
	inter (l->r, l->r, Rt);
    rt = l;
}
pn x1, x2 ,x3, rt1, rt2, rt3;
void ins(pn& rt, int x){
    spl(rt, x1, x2, x);
    mer(rt, x1, new nd(x)); mer(rt, rt, x2);
}

void prt(pn rt){
    if(!rt) return;
    prt(rt->l);
    out << rt->x << ' ';
    prt(rt->r);
}
int main() {
    z n, a;
    in >> n;
    ve<z> ns1(n), ns2(n);
    fo(i, n) {in >> a; ins(rt1, a);}
    fo(i, n) {in >> a; ins(rt2, a);}
    inter(rt3, rt1, rt2);
    prt(rt3);
}