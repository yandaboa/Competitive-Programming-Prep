#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <climits>
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
// cin.tie(0)->sync_with_stdio(0);

string str;
set<int> uniqueS;
int N;

bool works(int a){
    map<int, int> col; int left = 0, right = 0;
    while(right < N && right - left + 1 <= a){
        col[(int)str[right]]++;
        if(sz(col) == sz(uniqueS)){
            return true;
        }
        if(right - left + 1 == a){
            // cout << sz(col) << " ";
            col[(int)str[left]]--;
            if(col[(int)str[left]] == 0){
                col.erase((int)str[left]);
            }
            right++;
            left++;
        } else {
            right++;
        }
    }
    return false;
}

int main(){
    cin >> N; cin >> str;
    for (int i = 0; i < N; i++)
    {
        uniqueS.insert((int)str[i]);
    }
    // for(auto a : uniqueS){
    //     cout << a << " ";
    // }
    // cout << sz(uniqueS) << " ";
    
    int lo = 0, hi = N;
    while(lo < hi){
        int mid = (lo + hi)/2;
        // cout << endl << mid << " ";
        if(works(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
        
    }
    cout << lo;
}
