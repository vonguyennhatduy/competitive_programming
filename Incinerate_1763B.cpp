#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,k,h[maxn],p[maxn];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {

        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> h[i];
        for(int i = 1; i <= n; i++) 
            cin >> p[i];

        
        vector <pair <int,int> > tmp;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += h[i];
            tmp.push_back({h[i],p[i]});
        }

        sort(tmp.begin(),tmp.end());
        
        
        
    }
}

/* 

*/




