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

int T, n, m, a, b;

void solve(){
    cin >> n >> m >> a >> b;
    int roomToRun = a > b ? n - a : a - 1;
    int freeTime = a > b ? a - b : b - a; freeTime--;
    int totalTimeAlive = a > b ? n - b : b - 1;
    // cout << roomToRun << " " << freeTime << " " << totalTimeAlive << " ";
    vector<int> firecrackers;
    for (int i = 0; i < m; i++)
    {
        int curr; cin >> curr;
        firecrackers.pb(curr);
    }
    sort(all(firecrackers));
    // for(int i = 0; i < sz(firecrackers); i++){
    //     cout << firecrackers[i] << " ";
    // }
    // cout << endl;

    int lo = 0, hi = min(sz(firecrackers) - 1, freeTime);
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(firecrackers[mid] > totalTimeAlive){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    // cout << lo << endl;

    int total = 0;
    for (int i = lo; i > -1; i--)
    {
        if(total == freeTime){
            break;
        }
        if(firecrackers[i] > totalTimeAlive - 1){
            continue;
        } else {
            totalTimeAlive--;
            total++;
        }
    }
    cout << total << endl;
        
}

int main(){
    cin >>T;
    while(T){
        solve();
        T--;
    }
}
