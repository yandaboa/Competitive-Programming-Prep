//make a dp array of size 10^5, build it similarly to the bricks example. Prefix sum it and then process all queries.
#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi= vector<vector<int> >;
using vll = vector<long long>;
using vpi = vector<pair<int, int> >;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int T, K;
ll dp[500001];
// ll dp[9];
ll prefSum[500002];
// ll prefSum[10];

ll mod(ll a){
    ll modulus = pow(10, 9) + 7;
    if(a < 0){
        return modulus + a;
    }
    return a%modulus;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> K;
    for (int i = 0; i < sizeof(dp)/sizeof(dp[0]); i++)
    {
        if(i < K){
            dp[i] = 1;
        } else {
            dp[i] = mod(dp[i - K] + dp[i - 1]);
        }
        // cout << dp[i] << " ";
    }
    // cout << endl;
    prefSum[0] = 0;
    for (int i = 1; i < sizeof(prefSum)/sizeof(prefSum[0]); i++)
    {
        prefSum[i] = mod(prefSum[i - 1] + dp[i - 1]);
    }
    for (int i = 0; i < T; i++)
    {
        int a, b; cin >> a >> b; a++; b++;
        cout << mod(prefSum[b] - prefSum[a - 1]) << endl;
    }
}