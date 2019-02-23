#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    //freopen("computers.in", "r", stdin);
    //freopen("computers.out", "w", stdout);
    int n, m, i = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    while (m > 0 && i < n)
    {
        int ra = s[i] - 'a';
        int rz = 'z' - s[i];
        if (rz > ra)
        {
            if (rz > m)
                rz = m;
            m -= rz;
            s[i] = s[i] + rz;
        }
        else
        {
            if (ra > m)
                ra = m;
            m -= ra;
            s[i] = s[i] - ra;
        }
        i++;
    }
    if (i == n && m > 0)
        cout << -1;
    else
        cout << s;
    cout << '\n';
    //system("pause");
    return 0;
}
