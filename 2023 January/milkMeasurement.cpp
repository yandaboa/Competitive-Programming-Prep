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
int trash;
//cin.tie(0)->sync_with_stdio(0);

int N, highestProd, start;
vector<int> cowIDs;
set<int> idsort;
set<pair<int, pair<int, int> > > days;

int main(){
    cin >> N >> start;
    for (int i = 0; i < N; i++)
    {
        int date, id, change; cin >> date >> id >> change;
        idsort.insert(id);
        days.insert(mp(date, mp(id, change)));
        // cout << date << " " << id << " " << change;
    }
    // cout << endl;
    
}