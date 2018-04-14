#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    while (n) {
        ans += n/=5;//¾¡Á¿¼ò¶Ì
    }
    cout << ans << endl;
    return 0;
}
