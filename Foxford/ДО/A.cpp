#include <iostream>
#include <vector>
using namespace std;
#define p_l 2 * i + 1
#define p_r 2 * i + 2
const int n = 1000000, none = 0;
int t[4 * n], c[4 * n], a[n];
void push(int i){c[p_l] += c[i]; c[p_r] += c[i]; c[i] = 0;}
int st(int i = 0, int l = 0, int r = n){
    if(r - l == 1){t[i] = a[l]; return t[i];}
    t[i] = st(p_l, l, (l + r)/2) + st(p_r, (l + r)/2, r);
    return t[i];
}
void ch(int v, int a_l, int a_r, int i = 0, int l = 0, int r = n){
    if(a_r <= l || r <= a_l) return;
    if(a_l <= l && r <= a_r) {c[i] += v; return;}
    push(i); int m = (l + r) / 2;
    ch(v, a_l, a_r, p_l, l, m); ch(v, a_l, a_r, p_r, m, r);
    t[i] = t[p_l] + t[p_r] + (m - l) * c[p_l] + (r - m) * c[p_r];
}
long long q(int a_l, int a_r, int i = 0, int l = 0, int r = n){
    if(a_r <= l || r <= a_l) return none;
    if(a_l <= l && r <= a_r) return t[i] + c[i] * (r - l);
    push(i); int m = (l + r) / 2;
    t[i] = t[p_l] + t[p_r] + (m - l) * c[p_l] + (r - m) * c[p_r];
    return q(a_l, a_r, p_l, l, m) + q(a_l, a_r, p_r, m, r);
}
int main(){
    int k, m;
    cin >> k >> m;
    for(int i = 0; i < m; i++){
        cout << '\n';
        int s, d, g, p;
        cin >> s >> d >> g;
        if(s == 1){
            cin >> p;
            ch(p, d, g);
        }
        else
            cout << q(d, g) << '\n';
    }
    return 0;
}
