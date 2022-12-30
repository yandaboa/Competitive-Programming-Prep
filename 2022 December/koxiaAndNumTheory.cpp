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

ll GCD(ll a, ll b){
    // cout << a<< " " << b << endl;
    if(b == 0){
        return a;
    } else {
        return GCD(b, a%b);
    }
}

void sol(vll& arr){
    for (int j = 0; j < sz(arr); j++)
        {
            for (int a = j + 1; a < sz(arr); a++)
            {
                if(arr[a] == arr[j]){
                    cout << "no" << endl;
                    return;
                }
            }
            
        }
        cout << "yes" << endl;
}

int T;
int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; vll arr; cin >> N;
        for (int j = 0; j < N; j++)
        {
            ll a; cin >> a; arr.pb(a);
        }
        sol(arr);
        // bool valid = true, dup = false;
        // ll bound = pow(10, 18), lowBound = bound - pow(10, 4);
        // cout << bound;
        // for (ll j = bound; j > lowBound; j--)
        // {
        //     ll addOn = j;
        //     // cout << addOn;
        //     bool works = true;
        //     for (int b = 0; b < sz(arr); b++)
        //     {
        //         for (int c = b + 1; c < sz(arr); c++)
        //         {
        //             if(GCD(arr[b] + addOn, arr[c] + addOn) != 1){
        //                 works = false;
        //             }
        //             if(arr[b] == arr[c]){
        //                 dup = true;
        //                 break;
        //             }
        //         }
        //         if(!works){
        //             valid = false;
        //             break;
        //         }
        //         if(dup){
        //             break;
        //         }
        //     }
        //     if(works){
        //         cout << "yes" << endl;
        //         valid = true;
        //         break;
        //     }
        //     if(dup){
        //         cout << "no" << endl;
        //         break;
        //     }
        // }
        // if(!valid && !dup){
        //     cout << "no" << endl;
        // }
    }
    // GCD(64, 81);
}