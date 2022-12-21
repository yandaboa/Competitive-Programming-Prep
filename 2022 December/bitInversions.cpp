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

set<int> ones, zeros;
multiset<int> oneIntervals, zeroIntervals;

int main(){
    string bits; 
    cin >> bits;
    zeros.insert(-1); zeros.insert(sz(bits));
    ones.insert(-1); ones.insert(sz(bits));
    for(int i = 0; i < sz(bits); i++){
        if(bits[i] =='0'){
            zeros.insert(i);
        } else {
            ones.insert(i);
        }
    }

// cout<< endl;
//     for(auto a : ones){
//         cout << a << " ";
//     }

    auto start = ones.begin(); start++;
    for (auto i = start; i != ones.end(); i++)
    {
        auto ptr = i; ptr--;
        if(*i - *(ptr) > 1){
            oneIntervals.insert(*i - *(ptr) - 1);
        }
    }
    start = zeros.begin(); start++;
    for (auto i = start; i != zeros.end(); i++)
    {
        auto ptr = i; ptr--;
        if(*i - *(ptr) > 1){
            zeroIntervals.insert(*i - *(ptr) - 1);
        }
    }

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int move; cin >> move; move--;
        if(ones.find(move) != ones.end()){
            auto temp = ones.upper_bound(move);
            auto below = temp; below--; below--;
            int prev1 = *temp - *below - 1;
            int new1 = *temp - move - 1, new2 = move - *below - 1;
            oneIntervals.insert(prev1);
            oneIntervals.erase(new1);
            oneIntervals.erase(new2);
            zeros.insert(move);
            ones.erase(move);
        } else {
            auto temp = zeros.upper_bound(move);
            auto below = temp; below--; below--;
            int prev1 = *temp - *below - 1;
            int new1 = *temp - move - 1, new2 = move - *below - 1;
            zeroIntervals.insert(prev1);
            zeroIntervals.erase(new1);
            zeroIntervals.erase(new2);
            ones.insert(move);
            zeros.erase(move);
        }
        auto oneEnd = oneIntervals.end(), zeroEnd = zeroIntervals.end(); oneEnd--; zeroEnd--;
        cout << max(*oneEnd, *zeroEnd) << " ";
    }
    
}