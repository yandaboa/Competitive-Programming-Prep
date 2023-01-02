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
//cin.tie(0)->sync_with_stdio(0);

int T;
set<int> winners;


int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N;
        winners.clear();
        string env; cin >> env;
        // vll numWinners;
        if(env[0] == '0'){
            winners.insert(1);
        } else {
            winners.insert(2);
        }
        cout << sz(winners) << " ";
        for (int j = 1; j < N - 1; j++)
        {
            if(env[j] == '1'){
                // cout << "hot bruh ";
                for (int b = *(winners.rbegin()) + 1; b <= j + 2; b++)
                {
                    winners.insert(b);
                }
                winners.erase(*(winners.begin()));
            } else {
                while(*winners.begin() > 1){
                    winners.insert(*winners.begin() - 1);
                }
            }
            cout << sz(winners) << " ";
        }
        cout << endl;
    }
    
}