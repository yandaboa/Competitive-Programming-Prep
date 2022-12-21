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

int N, M;

vi begs, endings;
vll crits;
vll prefSum;

int main(){
    cin >> N >> M;
    begs.rsz(M + 1);
    endings.rsz(M + 1);
    crits.rsz(2*M + 2);
    prefSum.resize(sz(crits));
    for (int i = 0; i < N; i++)
    {
        ll beg, end;
        cin >> beg >> end;
        // end++;
        begs[beg]++;
        endings[end]++;
    }
    
    for (int i = 0; i < sz(begs); i++)
    {
        if(begs[i] != 0){
            for (int j = 0; j < sz(begs); j++)
            {
                if(begs[j] != 0){
                    crits[i + j] += begs[i]*begs[j];
                }
            }
        }
    }
    for (int i = 0; i < sz(endings); i++)
    {
        if(endings[i] != 0){
            for (int j = 0; j < sz(endings); j++)
            {
                if(endings[j] != 0){
                    crits[i + j + 1] -= endings[i]*endings[j];
                }
            }
        }
    }

    prefSum[0] = 0;
    for (int i = 1; i < sz(prefSum); i++)
    {
        prefSum[i] = prefSum[i - 1] + crits[i - 1];
    }
    
    // for (int i = 0; i < sz(crits); i++)
    // {
    //     cout << crits[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i < sz(prefSum); i++)
    {
        cout << prefSum[i] << endl;
    }
}