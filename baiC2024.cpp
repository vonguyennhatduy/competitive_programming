#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int n,k,a[maxn],b[maxn],w[maxn],trace[maxn];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        cin >> b[i];

    for(int i = 1; i <= n; i++)
        trace[a[i]] = b[i];

    vector <vector <int> > components;
    map <int,int> mp;
    for(int i = 1; i <= n; i++) {
        vector <int> component;
        if(a[i] != b[i] && mp[a[i]] == 0 && mp[b[i]] == 0) {
            int tmp = a[i];
            while(!mp[tmp]) {
                component.push_back(tmp);
                if(!mp[trace[tmp]])
                    component.push_back(trace[tmp]);
                mp[tmp]++;
                mp[trace[tmp]]++;
                tmp = trace[trace[tmp]];
            }
            components.push_back(component);
        }
    }
    int ans = 0;
    for(auto x : components) {
        int mi = 1e18;
        for(auto y : x){
            mi = min(mi,w[y]);
            ans += w[y];
        }
        ans += (int)(x.size() - 2) * mi;

    }
    cout << ans;
    return 0;
}

/*
6
8 6 3 8 4 9
1 4 5 3 6 2
5 3 2 2 4 1

tmp
tracetrace[trace[tmp]]


17 + 27 = 44
*/
