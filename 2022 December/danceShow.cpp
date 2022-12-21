#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
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

int N, Tmax;
vi cows;

bool checkTime(int a){
    vi stage;
    for(int i = 0; i < a; i++){
        stage.pb(cows[i]);
    }
    sort(all(stage));
    int right = a;
    while(right < N){
        int temp = cows[right] + stage[0];
        stage.erase(stage.begin());
        vi::iterator at = lower_bound(all(stage), temp);
        stage.insert(at, temp);
        right++;
    }
    return stage[sz(stage) - 1] <= Tmax;
}

int main(){
    ifstream input("cowdance.in");
    ofstream output("cowdance.out");
    input >> N >> Tmax;
    for (int i = 0, a; i < N; i++)
    {
        input >> a;
        cows.pb(a);
    }

    int lo = 0, hi = N - 1;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(checkTime(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    output << lo;
}