#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,m,k,a[maxn],l[maxn],r[maxn],d[maxn],tmp[maxn],ans[maxn];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    test = 1;
    while(test--) {
 
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= m; i++){
            cin >> l[i] >> r[i] >> d[i];
        }

        while(k--) {
            int left,right;
            cin >> left >> right;
            tmp[left]++;
            tmp[right + 1]--;
        }

        for(int i = 1; i <= m; i++) {
            tmp[i] += tmp[i - 1];
        }

        for(int i = 1; i <= m; i++) {
            ans[l[i]] += (d[i] * tmp[i]);
            ans[r[i] + 1] -= (d[i] * tmp[i]);
        }

        for(int i = 1; i <= n; i++) 
            ans[i] += ans[i - 1];

        for(int i = 1; i <= n; i++)
            cout << a[i] + ans[i] << " ";

    }
}

/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

1 2 3

3 4 3
9 10 9 
9 18 17


3 3 0 
4 3 0
7 6 0 
8 7 0 

*/

