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
    int n;
    cin >> n;
    vector<int> arr(n), arr1(n + 1, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n && arr1[arr[i]] == -1)
        {
            arr1[arr[i]] = i;
        }
    }
    set<int> m_set;
    for (int i = 1; i <= n; i++)
    {
        if (arr1[i] == -1)
        {
            m_set.insert(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > n || arr1[arr[i]] != i)
        {
            cout << (*m_set.begin()) << ' ';
            m_set.erase(m_set.begin());
        }
        else
        {
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';
    //system("pause");
    return 0;
}
