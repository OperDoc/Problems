#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define int long long

int none = 0;
inline int mr(){return (rand() << 15) + rand();}
struct nd{
    long long x, y, sz = 0, v = none;
    nd *l, *r;
    nd():l(nullptr),r(nullptr){}
    nd(int x):x(x),y(mr()),l(nullptr),r(nullptr),sz(1), v(x){}
};
typedef nd* pn;
pn x1, x2 ,x3, x4, x5, x6, M_rt1, M_rt2;
inline int  g_s(pn rt){return rt ? rt->sz : 0;}
inline int g_v(pn rt){return rt ? rt->v : none;}
inline void upd(pn rt){if(rt){rt->sz = g_s(rt->l) + g_s(rt->r) + 1; rt->v = rt->x + g_v(rt->l) + g_v(rt->r);}}
void spl(pn rt, pn& l, pn& r, int x){
    if(!rt) return void(l = r = nullptr);
    if(g_s(rt->l) >= x)  {spl(rt->l, l, rt->l, x); r = rt; upd(r);}
    else{spl(rt->r, rt->r, r, x - g_s(rt->l) - 1); l = rt; upd(l);}
}
void mer(pn& rt, pn l, pn r){
    if(!l || !r) return void(rt = l ? l : r);
    if(l->y < r->y) {mer(l->r, l->r, r); rt = l;}
    else            {mer(r->l, l, r->l); rt = r;}
    upd(rt);
}
void era(pn& rt, int x){
    spl(rt, x1, x3, x + 1); spl(x1, x1, x2, x);
    mer(rt, x1, x3);
}
void ins(pn& rt, int x, int i){
    spl(rt, x1, x2, i);
    mer(rt, x1, new nd(x)); mer(rt, rt, x2);
}
inline void p_b(pn& rt, int x){mer(rt, rt, new nd(x));}
long long q(pn rt, int a_l, int a_r, int l = 0){
    if(!rt)return none;
    int r = l + rt->sz;
    if(l >= a_r || r <= a_l) return none;
    if(l >= a_l && r <= a_r) return rt->v;
    long long x = q(rt->l, a_l, a_r, l) + q(rt->r, a_l, a_r, l + g_s(rt->l) + 1);
    int pos = l + g_s(rt->l);
    long long rt_v = (pos >= a_l && pos < a_r) ? rt->x : none;
    return rt_v + x;
}
void help(int a, int b, int c, int d)
{
    spl(M_rt1, M_rt1, x3, b + 1);
    spl(M_rt1, x1, x2, a);
    spl(M_rt2, M_rt2, x6, d + 1);
    spl(M_rt2, x4, x5, c);
    mer(x1, x1, x5);
    mer(M_rt1, x1, x3);
    mer(x4, x4, x2);
    mer(M_rt2, x4, x6);
}
void pnt(pn& rt, int i = 0)
{if(!rt) return; pnt(rt->l, i); cout << rt->x << ':' << g_v(rt) << ':' << i + g_s(rt->l) << ' '; pnt(rt->r, i + g_s(rt->l) + 1);}
long long* g_i(pn rt, int i)
{return !rt?0:(g_s(rt->l)>i?g_i(rt->l,i):(g_s(rt->l)==i?&(rt->x):g_i(rt->r,i-g_s(rt->l)-1)));}

signed main(){
    int n, m, a, c = 1, k, L, R;
    string s = "Swapper ";
    cin >> n >> m;
    while(n != 0 && m != 0)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a;
            if(i%2 == 1)
                p_b(M_rt1, a);
            else
                p_b(M_rt2, a);
        }
        cout << s << c << ':' << '\n';
        //pnt(M_rt1);
        //cout << '\n';
        //pnt(M_rt2);
        //cout << '\n';
        for(int i = 0; i < m; i++)
        {
            cin >> k >> L >> R;
            if (k == 1)
            {
                L--; R--;
                int L1 = (L + 1) / 2, R1 = R / 2;
                int L2 = L / 2, R2 = (R + 1) / 2 - 1;
                help(L1, R1, L2, R2);
            }
            else
            {
                L--; R++;
                int L1 = (L + 1) / 2, R1 = R / 2;
                int L2 = L / 2, R2 = (R + 1) / 2 - 1;
                cout << q(M_rt1, L1, R1) + q(M_rt2, L2, R2)<< '\n';
            }
            //pnt(M_rt1);
            //cout << '\n';
            //pnt(M_rt2);
            //cout << '\n';
        }
        cout << '\n';
        c++;
        M_rt1 = M_rt2 = nullptr;
        cin >> n >> m;
    }
    return 0;
}
