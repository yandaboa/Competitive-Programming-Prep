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
using vvi = vector<vector<int> >;
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

int N, Q;
vi locs;
set<int> occs;

int main()
{
    ifstream input("haybales.in");
    ofstream output("haybales.out");
    input >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        int a;
        input >> a;
        locs.pb(a);
        occs.insert(a);
        
    }
    sort(all(locs));

    for (int i = 0; i < Q; i++)
    {
        int a, b, ansA, ansB;
        input >> a >> b;
        int lo = 0, hi = N - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (locs[mid] >= a)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        ansA = lo;
        // if(occs.count(a) == 0){
        //     ansA++;
        // }

        lo = 0, hi = N - 1;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (locs[mid] > b)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid;
            }
        }
        ansB = lo;

        if (a > locs[sz(locs) - 1] && b > locs[sz(locs) - 1])
        {
            output << ansB - ansA << endl;
        }
        else
        {
            output << ansB - ansA + 1 << endl;
        }
    }
}