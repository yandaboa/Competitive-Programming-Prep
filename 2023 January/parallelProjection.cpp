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

int T;
int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int w, d, h; cin >> w >> d >> h;
        int a, b, fr, g; cin >> a >> b >> fr >> g;
        int firstMin = min(h+a+fr + abs(b - g), h + b + g + abs(a - fr));
        int secondMin = min(h + (w - a) + (w - fr) + abs(b - g), h + (d - b) + (d - g) + abs(a - fr));
        cout << min(firstMin, secondMin) << endl;
    }
    
}