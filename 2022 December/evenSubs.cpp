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
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll N; cin >> N;
        vi arr; vll prefXOR; prefXOR.rsz(N*2 + 1);
        for (int j = 0; j < N; j++)
        {
            int a; cin >> a;
            arr.pb(a);
        }
        prefXOR[0] = 1;
        ll curr = 0, count = 0;
        for (int j = 0; j < sz(arr); j++)
        {
            curr ^= arr[j];
            for (ll a = 0; a*a < 2*N; a++)
            {
                if(((a*a) ^ curr) < 2*N){
                    count += prefXOR[(a*a)^curr];
                }
            }
            prefXOR[curr]++;
        }
        // cout << count << endl;
        cout << N*(N+1)/2 - count << endl;
    }
    
}