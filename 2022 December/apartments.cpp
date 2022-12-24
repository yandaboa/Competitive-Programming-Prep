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

int N, M, K;
vi people;
multiset<int> apartments;

int main(){
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        people.pb(a);   
    }
    for (int i = 0; i < M; i++)
    {
        int a; cin >> a;
        apartments.insert(a);
    }
    sort(all(people));
    
    int allocated = 0;
    for (int i = 0; i < sz(people); i++)
    {
        int ideal = people[i] - K;
        auto ptr = apartments.lower_bound(ideal);
        if(ptr != apartments.end() && *ptr <= people[i] + K){
            allocated++;
            apartments.erase(apartments.find(*ptr));
        }
    }
    cout << allocated;
    
}