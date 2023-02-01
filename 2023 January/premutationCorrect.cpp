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
        int N; cin >> N;
        vi arr; arr.rsz(N + 1);
        for (int b = 0; b < N; b++)
        {
            for (int c = 0; c < N - 1; c++)
            {
                int x; cin >> x;
                arr[x] += c;
            }
        }
        set<pi> nums;
        for (int j = 1; j < sz(arr); j++)
        {
            nums.insert(mp(arr[j], j));
        }
        for(auto a = nums.begin(); a != nums.end(); a++){
            cout << (*a).s << " ";
        }
        cout << endl;
    }
    
}