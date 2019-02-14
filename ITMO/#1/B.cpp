#include<iostream>
#include<map>
#include<vector>
#import<algorithm>
using namespace std;

struct eve
{
    int type, c, x;// type - 1 2  0
    eve(int x, int type, int c = 0):x(x),type(type),c(c){}
};

bool cmp(eve a, eve b)
{
    return a.x < b.x || (a.x == b.x && a.type < b.type);
}

int main()
{
    freopen("bestbuy.in", "r", stdin);
    freopen("bestbuy.out", "w", stdout);
    int c1, c2, n, m;
    cin >> c1 >> c2 >> n;
    vector<eve> events;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events.push_back(eve(b, 0, a));
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back(eve(l, 1, i));
        events.push_back(eve(r, 2, i));
    }
    vector<bool> u(m, false);
    sort(events.begin(), events.end(), cmp);
    long long sum = 0, res = 0;
    for(auto e:events)
    {
        if(e.type == 0)
            sum += e.c;
        if(e.type == 1 && sum >= c1){
            sum -= c1;
            res++;
            u[e.c] = true;
            //cout << e.x << ' ' << e.c << ' ';
        }
        if(e.type == 2 && sum >= c2 && !u[e.c]){
            sum -= c2;
            res++;
            //cout << e.x << ' ' << e.c << ' ';
        }
    }
    cout << res;
    return 0;
}
