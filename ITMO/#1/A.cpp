#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    freopen("colors.in", "r", stdin);
    freopen("colors.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    map<int, int> M;
    vector<int> arr(2 * n, 0), un_M(2 * n);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(M[a] == 0){
            M[a] = i + 1;
            un_M[i + 1] = a;
        }

        arr[M[a]]++;
    }
    vector<int> ans;
    for(int i = 0; i < 2 * n && ans.size() < k; i++)
    {
        if(arr[i] > 0){
            ans.push_back(un_M[i]);
            arr[i]--;
        }
    }
    for(int i = 0; i < 2 * n && ans.size() < k; i++)
    {
        while (arr[i] > 0 && ans.size() < k)
        {
            ans.push_back(un_M[i]);
            arr[i]--;
        }
    }
    for(auto i:ans)
        cout << i << ' ';
    return 0;
}
