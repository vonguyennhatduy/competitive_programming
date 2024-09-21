#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,k;

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
        
        cin >> n >> k;
        int l = n - k + 1;

        if(abs(l - n) == 1){
            cout << "NO\n";
            continue;
        }

        if(l == n) {
            if(n & 1){
                cout << "NO\n";
            }else cout << "YES\n";
            continue;
        }

        if(l % 2 == 0) l++;
        if(n % 2 == 0) n--;

        if(l == n){
            cout << "NO\n";
            continue;
        }

        int ans = (n - l + 1) / 2 + ((n - l + 1) % 2);

        if(ans % 2 == 0){
            cout << "YES\n";
        }else cout << "NO\n";
    }
}
/*
5
1 1
2 1
2 2
3 2
4 4


6 9 

8 20 
9 19 


1 7


*/
