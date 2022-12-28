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

int T;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N; ll product = 1;
        for (int j = 0; j < N; j++)
        {
            ll a; cin >> a; product *= a;
        }
        product += N - 1;
        cout << 2022*product << endl;
    }
    
}