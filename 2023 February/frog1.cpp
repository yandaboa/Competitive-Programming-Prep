#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
#include <string.h>
#include <fstream>
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
//cin.tie(0)->sync_with_stdio(0);

int N;
vi arr;

int main(){
    cin >> N;
    arr.rsz(N);
    for (int i = 0; i < sz(arr); i++)
    {
        cin >> arr[i];
    }
    vi dp; dp.rsz(N);
    dp[0] = 0; dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < sz(dp); i++)
    {
        dp[i] = min(dp[i - 2] + abs(arr[i] - arr[i - 2]), dp[i - 1] + abs(arr[i] - arr[i - 1]));
    }
    cout << dp[sz(dp) - 1];
    
}