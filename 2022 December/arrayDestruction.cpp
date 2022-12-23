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

int T;
vector<int> arr;
vector<pair<int, int> > toBeRemoved;

bool works(int a){
    toBeRemoved.clear();
    multiset<int> remaining;
    for (int i = 0; i < sz(arr); i++)
    {
        remaining.insert(arr[i]);
    }
    while(sz(remaining)){
        int largest = *remaining.rbegin();
        remaining.erase(remaining.find(largest));
        if(remaining.find(a - largest) == remaining.end()){
            return false;
        }
        remaining.erase(remaining.find(a - largest));
        toBeRemoved.pb(mp(a - largest, largest));
        a = largest;
    }
    return true;
}

void solve(){
    int N;
    cin >> N;
    arr.clear();
    for (int i = 0; i < 2*N; i++)
    {
        int a; cin >> a;
        arr.pb(a);
    }
    sort(all(arr));
    int largest = *arr.rbegin();
    for (auto i = arr.begin(); i != prev(arr.end()); i++)
    {
        if(works(largest + *i)){
            cout << "YES" << endl;
            cout << largest + *i << endl;
            for (int i = 0; i < sz(toBeRemoved); i++)
            {
                cout << toBeRemoved[i].f << " " << toBeRemoved[i].s << endl;
            }
            return;
        }
    }
    cout << "NO" << endl; 
}

int main(){
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}