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

int X, N;
set<int> lights;
multiset<int> intervals;

int main(){
    cin >> X >> N;
    lights.insert(0);
    lights.insert(X);
    intervals.insert(X);
    for (int i = 0; i < N; i++)
    {
        int pos;
        cin >> pos;
        auto ptr = lights.upper_bound(pos); auto low = ptr; low--;
        int rem = *ptr - *low;
        int add1 = *ptr - pos, add2 = pos - *low;
        lights.insert(pos);
        intervals.erase(intervals.find(rem));
        intervals.insert(add1);
        intervals.insert(add2);
        auto last = intervals.end(); last--;
        cout << *last << " ";
    }
    
}