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
        int n, s1, r; cin >> n >> s1 >> r;
        cout << s1 - r << " ";
        int val;
        for (int i = 1; i <= 6; i++)
        {
            if(r - (n - 1)*i < n){
                val = i;
                break;
            }
        }
        for (int j = 0; j < r - (n - 1)*val; j++)
        {
            cout << val + 1 << " ";
        }
        for (int j = 0; j < n - (r - (n - 1)*val) - 1; j++)
        {
            cout << val << " ";
        }
        
        cout << endl;
    }
}