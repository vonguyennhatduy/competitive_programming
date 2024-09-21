#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 2e5 + 5;

int n,a[maxn];
double sum;

bool check(int mid) {
    double tmp = (double)(sum + mid) / (double)(2 * n);

    int idx = lower_bound(a + 1,a + n + 1,tmp) - a - 1;
    if(a[idx] == tmp) idx--;

    if(idx > n / 2){
        return true; 
    }else return false;
}

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
        cin >> n;
        sum = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i] , sum += a[i];

        if(n == 1 || n == 2){
            cout << "-1\n";
            continue;
        }

        sort(a + 1,a + n + 1);
        int l = 0,r = 1e18,ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }

        cout << ans << endl;
        
        
    }
}
/*
6
1
2
2
2 19
3
1 3 20
4
1 2 3 4
5
1 2 3 4 5
6
1 2 1 1 1 25



1 2 3 19 
*/
