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

//finally works istg bruh

vector<pair<pair<int, int>, int>> northCows, eastCows;

int N;
int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char north; cin >> north;
        int x, y; cin >> x >> y;
        if(north == 'N'){
            northCows.pb(mp(mp(x,y), i));
        } else {
            eastCows.pb(mp(mp(y,x), i));
        }
    }
    sort(all(northCows)); sort(all(eastCows));
    for (int i = 0; i < sz(eastCows); i++)
    {
        int temp = eastCows[i].f.f;
        eastCows[i].f.f = eastCows[i].f.s;
        eastCows[i].f.s = temp;
    }

    vi numStopped; numStopped.rsz(N); vb stopped; stopped.rsz(N);
    for (int i = 0; i < sz(northCows); i++)
    {

        pi northCow = northCows[i].f;
        int nCowNum = northCows[i].s;
        if(stopped[nCowNum]){
            continue;
        }
        for (int j = 0; j < sz(eastCows); j++)
        {
            pi eastCow = eastCows[j].f;
            int eCowNum = eastCows[j].s;
            if(stopped[eCowNum]){
                continue;
            }
            if(eastCow.f > northCow.f || northCow.s > eastCow.s || (eastCow.f == northCow.f && northCow.s == eastCow.s)){
                continue;
            }
            if(northCow.f - eastCow.f < eastCow.s - northCow.s){
                numStopped[eCowNum] += numStopped[nCowNum] + 1;
                stopped[nCowNum] = true;
                break;
            } else if (northCow.f - eastCow.f > eastCow.s - northCow.s){
                numStopped[nCowNum] += numStopped[eCowNum] + 1;
                stopped[eCowNum] = true;
            }
        }
    }

    for (int i = 0; i < sz(numStopped); i++)
    {
        cout << numStopped[i] << endl;
    }
    
}