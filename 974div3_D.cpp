#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,d,k,a[maxn],tmp[maxn],f[maxn];

void reset () {
    for(int i = 1; i <= maxn; i++){
        tmp[i] = 0;
        f[i] = 0;
    }
}


int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
        cin >> n >> d >> k;
        while(k--){
            int l,r;
            cin >> l >> r;
            tmp[l]++;
            tmp[r + 1]--;
        }
        
        for(int i = 1; i <= n; i++)
            tmp[i] += tmp[i - 1];
        
        f[1] = tmp[1];
        for(int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + (tmp[i - 1] - tmp[i]);
        }


        int ans = -1e18,idx1 = -1;
        for(int i = 1; i <= n - d + 1; i++) {
            if(ans < tmp[i] + abs(f[i + d - 1] - f[i])){
                ans = tmp[i] + abs(f[i + d - 1] - f[i]);
                idx1 = i;
            }
        }

        int res = 1e18,idx2 = -1;
        for(int i = 1; i <= n - d + 1; i++) {
            if(res > tmp[i] + abs(f[i + d - 1] - f[i])) {
                res =  tmp[i] + abs(f[i + d - 1] - f[i]);
                idx2 = i;
            }
        }

        cout << idx1 << " " << idx2 << endl;

        reset();
        
    }
}
/*

*/
