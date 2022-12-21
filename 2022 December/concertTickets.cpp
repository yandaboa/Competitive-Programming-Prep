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

int N, M;
map<int, int> tickets;

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        tickets[a]++;
    }
    for (int i = 0; i < M; i++)
    {
        int b;
        cin >> b;
        auto ans = tickets.lower_bound(b);
        if((*ans).first == b){
            cout << (*ans).first << endl;
            tickets[(*ans).first]--;
            if(tickets[(*ans).first] == 0){
                tickets.erase((*ans).first);
            }
        } else {
            if(ans == tickets.begin()){
                cout << -1 << endl;
            } else {
                ans--;
                cout << (*ans).first << endl;
                tickets[(*ans).first]--;
                if(tickets[(*ans).first] == 0){
                    tickets.erase((*ans).first);
                }
            }
        }
    }
}