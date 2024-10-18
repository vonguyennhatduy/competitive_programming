#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int a[maxn],b[maxn],f[maxn],n;

void init () {
    f[0] = f[1] = 1;
    for(int i = 2; i <= 100000;  i++) {
        f[i] = f[i - 1] % mod * i % mod;
        f[i] %= mod;
    }
}

int bin(int a,int b) {
    int ans = 1;
    while(b) {
        if(b % 2 == 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

int inverse(int a) {
    return bin(a,mod - 2);
}

int nCk(int n,int k) {
    init();
    int ans = (f[n] % mod * inverse(f[k] % mod * f[n - k] % mod) % mod) % mod;

    return ans % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        int ans = (nCk(a[i],b[i]) % mod - (nCk(a[i] - 1,b[i]) % mod + mod) % mod + nCk(a[i],b[i] - 1) % mod) % mod;

        cout << ans << endl;
    }

    return 0;
}
/*

*/
