#include <iostream>
#include <vector>
#include <limits>
#include <climits>
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

ll N, K;
vector<pair<ll, int> > nums;

int main(){
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        nums.pb(mp(a, i));
    }    
    
    sort(all(nums));
    
    int left = 0, right = nums.size() - 1;
    while(left < right){
        if(nums[left].f + nums[right].f == K){
            cout << nums[left].s + 1 << " " << nums[right].s + 1;
            return 0;
        } else if (nums[left].f + nums[right].f > K){
            right--;
        } else {
            left++;
        }
    }
    cout << "IMPOSSIBLE";
}