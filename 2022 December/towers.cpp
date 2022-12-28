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
multiset<int> arr;

int main(){
    cin >> N; int a; cin >> a; arr.insert(a);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a;
        auto itr = arr.upper_bound(a);
        if(itr == arr.end()){
            arr.insert(a);
        } else {
            int val = *itr;
            arr.erase(arr.find(val));
            arr.insert(a);
        }
    }
    cout << sz(arr);
    
}