#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b;
    long long ans = 0;
    cin >> a >> b;
    while(a >= b) {
        ans += a - a % b;
        a = a % b + a / b;
    }
    cout << ans + a;
    return 0;
}