/*
int lg[500010], st[30][100010], arr[500010], n;
start() {
    for (int i = 0; i <= n; i++)
        lg[i] = (i > 1 ? lg[i / 2] + 1 : 0);
    for (int p = 0; (1 << p) <= n; p++) {
        for (int i = 0; i + (1 << p) <= n; i++)
            st[p][i] = (p ? min(st[p - 1][i], st[p - 1][i + (1 << p - 1)]) : a[i]);
    }
}
int getMin(int l, int r) {
    int p = lg[r - l + 1];
    return min(st[p][l], st[p][r - (1 << p) + 1]);
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> a, b, ord;

long long spm[30][500010], spu[30][500010], n, sum[500010];
int m_log[500010];

void st(){
    for(int i = 0; i < 30; i++)
        m_log[i] = log2(i);
    for(int i = 0; i < n; i++)
        spm[0][i] = a[ord[i]];
    for(int i = 1; (1<<i) < n; i++)
        for(int j = 0; j + (1<<i) - 1 < n; j++)
            spm[i][j] = min(spm[i - 1][j], spm[i - 1][j + (1<<(i - 1))]);
            
    for(int i = 0; i < n; i++)
        spu[0][i] = a[ord[i]];
    for(int i = 1; (1<<i) < n; i++)
        for(int j = 0; j + (1<<i) - 1 < n; j++)
            spu[i][j] = max(spu[i - 1][j], spu[i - 1][j + (1<<(i - 1))]);

    sum[0] = b[ord[0]];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + b[ord[i]];
    }   
}
long long q1(int l, int r)/*O(1)*/{
    int i = m_log[r - l + 1];
    return min(spm[i][l], spm[i][r - (1<<i) + 1]);
}
long long q2(int l, int r)/*O(1)*/{
    int i = m_log[r - l + 1];
    return max(spu[i][l], spu[i][r - (1<<i) + 1]);
}
long long q3(int l, int r){
    return l == 0 ? sum[r] : sum[r] - sum[l - 1];
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    cin >> n;
    ord.resize(n);
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), cmp);
    st();
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            long long def = q1(i, j) - q2(i, j);
            long long sum = q3(i, j);
            ans = max(ans, sum + def);
        }
    }
    cout << ans;
    return 0;
}