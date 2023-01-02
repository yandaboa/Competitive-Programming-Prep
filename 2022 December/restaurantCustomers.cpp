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
//cin.tie(0)->sync_with_stdio(0);

int N;
vpi arr;
vll prefSums;
int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b; arr.pb(mp(a, 1)); arr.pb(mp(b, -1));
    }
    sort(all(arr));
    prefSums.rsz(sz(arr) + 1); prefSums[0] = 0; ll maxV = 0;
    for (int i = 1; i < sz(prefSums); i++)
    {
        prefSums[i] = arr[i - 1].s + prefSums[i - 1];
        maxV = max(maxV, prefSums[i]);
    }
    cout << maxV;

}