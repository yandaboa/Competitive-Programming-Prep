#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N, Q;
vpi critPoints;
vll prefSum, currValueArr;
map<int, int> process;

ll findPrefSum(int a){
    int lo = 1, hi = sz(critPoints) - 1;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(critPoints[mid].f > a){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    lo--;
    if(a >= critPoints[sz(critPoints) - 1].f){
        return prefSum[sz(prefSum) - 1];
    }
    return prefSum[lo] + (a - critPoints[lo].f)*currValueArr[lo];
}

int main(){
    cin >> N >> Q;
    critPoints.pb(mp(0, 0));
    for (int i = 0; i < N; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        process[l] += v;
        process[r] -= v;
    }

    for(map<int, int>::iterator itr = process.begin(); itr != process.end(); ++itr){
        critPoints.pb(mp(itr->first, itr->second));
    }

    sort(all(critPoints));

    prefSum.rsz(sz(critPoints));
    prefSum[0] = 0;
    ll currValue = 0;
    currValueArr.rsz(sz(critPoints));
    currValueArr[0] = 0;
    for (int i = 1; i < sz(prefSum); i++)
    {
        prefSum[i] = (critPoints[i].f - critPoints[i - 1].f)*currValue + critPoints[i].s + prefSum[i - 1];
        currValue += critPoints[i].s;
        currValueArr[i] = currValue;
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << findPrefSum(r - 1) - findPrefSum(l - 1) << endl;
    }
}