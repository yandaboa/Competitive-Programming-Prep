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

double N, l;

int main(){
    cin >> N >> l;
    multiset<double> lanterns;
    for (int i = 0; i < N; i++)
    {
        double a; cin >> a;
        lanterns.insert(a);
    }
    lanterns.insert(l);
    double maxInterval = 0, last = 0;
    for(auto a = lanterns.begin(); a != lanterns.end(); a++){
        maxInterval = max(maxInterval, *a - last);
        last = *a;
    }
    maxInterval /= 2.;
    cout.precision(17);
    lanterns.erase(lanterns.find(*lanterns.rbegin()));
    cout << max(max(*lanterns.begin(), maxInterval), l - *lanterns.rbegin());
}