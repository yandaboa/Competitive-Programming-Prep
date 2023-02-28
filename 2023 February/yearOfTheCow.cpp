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

int N, K;
vi ancestors;
set<int> landPoints;
multiset<int> gaps;

int main(){
    cin >> N >> K; K--;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a; ancestors.pb(a);
    }
    sort(all(ancestors));
    for (int i = 0; i < sz(ancestors); i++)
    {
        landPoints.insert(ancestors[i] + (12 - (ancestors[i]%12)));
    }
    landPoints.insert(0);
    int last = *landPoints.begin(); auto itr = landPoints.begin(); itr++;
    for (auto i = itr; i != landPoints.end(); i++){
        int curr = *i;
        if(curr - last > 12){
            gaps.insert(curr - last - 12);
        }
        last = curr;
    }
    // for(auto itr = gaps.begin(); itr != gaps.end(); itr++){
    //     cout << *itr << endl; 
    // }
    int counter = 0, unskip = 0;
    for(auto a = gaps.begin(); a != gaps.end(); a++){
        if(K + counter >= sz(gaps)){
            break;
        }
        counter++;
        unskip += *a;
    }
    cout << (unskip + 12*(sz(landPoints) - 1));
}