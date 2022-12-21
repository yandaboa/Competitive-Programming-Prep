#include <iostream>
#include <vector>
#include <limits>
#include <climits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

//TODO: implement this approach:
//for every cow, compute its distance from every neighbor, make sure to square, round to next highest int n^2 complex, n=1000
//while computing distances, add each pair with that int distance to a map for later use
//iterate through all computed distances, update a map that keeps track of which connections between cows are now possible, now "light up"
//do a DFS for each distance, stop once you can reach all other cows.



int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        
    }
}