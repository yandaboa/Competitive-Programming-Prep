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
vi arr;
vll ps;
map<ll, vi> prefOccs;

int main() {
    cin >> N;
    arr.rsz(N); ps.rsz(N + 1); ps[0] = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < sz(ps); i++)
    {
        ps[i] = ps[i - 1] + arr[i - 1];
        prefOccs[ps[i]].pb(i);
    }
    // for(auto a = prefOccs.begin(); a != prefOccs.end(); a++){
    //     cout << (*a).f << ": ";
    //     vi vec = (*a).s;
    //     for (int i = 0; i < sz(vec); i++)
    //     {
    //         cout << vec[i] << " ";
    //     }
    //     cout << endl;
    // }
    ll last = ps[sz(ps) - 1]; ll count = 0;
    for(int i = 1; i < sz(ps) - 2; i++){
        if(ps[i]*3 == last && prefOccs.find(ps[i]*2) != prefOccs.end()){
            vi& vec = prefOccs[ps[i]*2];
            int add;
            auto itr = upper_bound(all(vec), i);
            add = sz(vec) - (itr - vec.begin());
            if(vec[sz(vec) - 1] == sz(ps) - 1){add--;}
            count += add;
        }
    }
    
    cout << count;
}
