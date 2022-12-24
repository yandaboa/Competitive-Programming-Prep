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

int N;
vector<pair<ll, ll>> tasks;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        tasks.pb(mp(a, b));
    }
    sort(all(tasks));
    ll sum = 0;
    ll time = 0;
    for (int i = 0; i < sz(tasks); i++)
    {
        time += tasks[i].f;
        sum += tasks[i].s - time;
    }
    cout << sum;
    
}