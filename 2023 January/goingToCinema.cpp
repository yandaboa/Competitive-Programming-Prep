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
        int N; cin >> N; vi arr;
        for (int j = 0; j < N; j++)
        {
            int a; cin >> a; arr.pb(a);
        }
        sort(all(arr));
        int subset = 0;
        if(arr[0] != 0){
            subset++;
        }
        for (int j = 0; j < sz(arr); j++)
        {
            int going = j + 1;
            if(going > arr[j]){
                if(j < sz(arr) - 1){
                    if(arr[j + 1] > going){
                        // cout << going << " ";
                        subset++;
                    }
                } else {
                    // cout << going << " ";
                    subset++;
                }
            }
        }
        cout << subset << endl;
    }
    
}