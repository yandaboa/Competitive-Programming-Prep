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

ll N, greaterThan;

bool works(ll a){
    ll sum = 0;
    for (ll i = 1; i <= N; i++)
    {
        sum += min(a/i, N);
    }
    return sum >= greaterThan;
}

int main(){
    cin >> N;
    greaterThan = pow(N, 2); greaterThan++; greaterThan /= 2;
    // cout << greaterThan << endl;
    ll lo = 0, hi = pow(N, 2);
    while(lo < hi){
        ll mid = (lo + hi)/2;
        // cout << mid << ' ';
        if(works(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    } 
    cout << lo;
}