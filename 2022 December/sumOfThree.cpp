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

ll N, K;
vector<pair<long, int> > arr;

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        arr.pb(mp(a, i));
    }
    sort(all(arr));

    for(int i = 0;i < sz(arr); i++){
        ll target = K - arr[i].f;
        int lo = 0, hi = sz(arr) - 1;
        while(lo<hi){
            if (arr[lo].f + arr[hi].f == target && lo != i && hi != i){
                cout << arr[lo].s + 1 << " " << arr[hi].s + 1 << " "<< arr[i].s + 1 << endl;
                return 0;
            }
            if(arr[lo].f + arr[hi].f > target){
                hi--;
            } else {
                lo++;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
    
}