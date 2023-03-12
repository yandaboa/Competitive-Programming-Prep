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

int T, N;

void solve(){
    cin >> N;
    int unknownPigs = 0, knownPigs = 0, maxCages = 0;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        if(a == 1){
            unknownPigs++;
            maxCages = max(maxCages, unknownPigs + (knownPigs > 0 ? 1 : 0) + knownPigs/2);
            // cout << unknownPigs << " ";
        } else {
            knownPigs += unknownPigs;
            unknownPigs = 0;
            int cages = (knownPigs > 0 ? 1 : 0) + knownPigs/2;
            maxCages = max(maxCages, cages);
        }
    }
    // cout << endl;
    cout << maxCages << endl;

}

int main(){
    cin >> T;
    while(T){
        solve();
        T--;
    }
}