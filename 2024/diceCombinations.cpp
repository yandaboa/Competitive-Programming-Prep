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
#include <stack>
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

vll ways;

int main(){
    int n; cin >> n;
    ways.rsz(n + 1);
    for (int i = 1; i <= 6 && i < sz(ways); i++)
    {
        ways[i] = 1;
    }

    for(int i = 1; i < sz(ways); i++){
        for(int j = i + 1; j <= i + 6 && j < sz(ways); j++){
            ll sum = ways[j] + ways[i];
            sum %= 1000000007;
            ways[j] = sum;
        }
    }
    cout << ways[n];
}