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
#include <queue>
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

int N, M, R;
ll totalMilkProd;
priority_queue<int> cows, farms;
vpi stores;
vll prefAmount, prefEarning;

ll storeRev(ll milkProduced){
    ll earned = 0;
    int index = upper_bound(all(prefAmount), milkProduced) - prefAmount.begin(); index--;
    earned += prefEarning[index];
    if(index < sz(stores)){
        earned += stores[index].f*(milkProduced - prefAmount[index])*-1;
    }
    return earned;
}

void solve(){
    ofstream output("rental.out");
    ll fromStores = 0, fromFarms = 0;
    fromStores = storeRev(totalMilkProd);
    while(!cows.empty() && !farms.empty()){
        int cow = -1*cows.top(), farm = farms.top(); cows.pop(); farms.pop();
        totalMilkProd -= cow;
        ll reducedRev = storeRev(totalMilkProd);
        if(fromStores - reducedRev > farm){
            break;
        } else {
            fromStores = reducedRev;
            fromFarms += farm;
        }
    }
    output << fromStores + fromFarms;
}

int main(){
    ifstream input("rental.in");
    // ofstream output("rental.out");
    input >> N >> M >> R;
    totalMilkProd = 0;
    for (int i = 0; i < N; i++)
    {
        int a; input >> a;
        cows.push(-1*a); totalMilkProd += a;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b; input >> a >> b;
        stores.pb(mp(-1*b,a));
    }
    sort(all(stores));
    prefAmount.rsz(M + 1); prefAmount[0] = 0;
    for (int i = 1; i < sz(prefAmount); i++)
    {
        prefAmount[i] = prefAmount[i - 1] + stores[i - 1].s;
    }
    prefEarning.rsz(M + 1); prefEarning[0] = 0;
    for (int i = 1; i < sz(prefEarning); i++)
    {
        prefEarning[i] = prefEarning[i - 1] + (stores[i - 1].s*stores[i - 1].f*-1);
        // cout << prefEarning[i] << " ";
    }
    
    // cout << endl;
    for (int i = 0; i < R; i++)
    {
        int a; input >> a;
        farms.push(a);
    }
    // cout << storeRev(26);
    solve();
}