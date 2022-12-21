#include <iostream>
#include <vector>
#include <limits>
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

int N, K;
vi diamonds;
vpi intervals;

int main(){
    ifstream input("diamond.in");
    ofstream output("diamond.out");
    input >> N >> K;
    diamonds.rsz(N);
    for (int i = 0; i < N; i++)
    {
        input >> diamonds[i];
    }
    
    sort(all(diamonds));

    int left = 0, right = 0;

    while(left < sz(diamonds)){
        while(right< sz(diamonds) && diamonds[right] - diamonds[left] <= K){
            right++;
        }
        intervals.pb(mp(left, right - left));
        left++;
    }

    // for (int i = 0; i < sz(intervals); i++)
    // {
    //     cout << intervals[i].f << " " << intervals[i].s << endl;
    // }
    vi largestAfter;
    largestAfter.rsz(N);
    int largestSoFar = 0;
    for (int i = sz(intervals) - 1; i >= 0; i--)
    {  
        largestSoFar = max(largestSoFar, intervals[i].s);
        largestAfter[i] = largestSoFar;
    }
    largestAfter.pb(0);

    int maxSum = 0;
    for (int i = 0; i < sz(intervals); i++)
    {
        maxSum = max(maxSum, intervals[i].s + largestAfter[min(sz(largestAfter) - 1, intervals[i].f + intervals[i].s)]);
    }
    output << maxSum;
}