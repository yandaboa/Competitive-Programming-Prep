#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>

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

int X, N;
priority_queue<int> sticks;

int main(){
    cin >> X >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; sticks.push(-1 * a);
    }
    ll total = 0, runningTot = 0;
    while(sz(sticks) > 1){
        int first = sticks.top() * -1; sticks.pop();
        int temp = sticks.top() * -1; sticks.pop();
        int sum = first + temp;
        sticks.push(sum * - 1);
        total += sum;
    }
    cout << total;
}