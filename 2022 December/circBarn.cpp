#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>
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

int N;
vector<priority_queue<int> > barn;

int main(){
    ifstream input("cbarn.in");
    ofstream output("cbarn.out");
    input >> N;
    barn.rsz(N);
    for (int i = 0; i < N; i++)
    {
        int a; input >> a;
        for (int j = 0; j < a; j++)
        {
            barn[i].push(0);
        }
    }
    
    bool notSettled = true;
    while(notSettled){
        for (int i = 0; i < sz(barn) - 1; i++)
        {
            while(barn[i].size() > 1){
                int a = barn[i].top();
                barn[i + 1].push(a - 1);
                barn[i].pop();
            }
            // cout << sz(barn[i]) << " ";
        }
        // cout << sz(barn[sz(barn) -1]) << endl;
        while(barn[sz(barn) - 1].size() > 1){
            int a = barn[sz(barn) - 1].top();
            barn[0].push(a - 1);
            barn[sz(barn) - 1].pop();
        }
        bool settled = true;
        for (int i = 0; i < sz(barn); i++)
        {
            if(barn[i].size() > 1){
                settled = false;
            }
        }
        if(settled){
            notSettled = false;
        }
    }
    int sum = 0;
    for (int i = 0; i < sz(barn); i++)
    {
        int a = barn[i].top();
        // cout << a << " ";
        sum += pow(barn[i].top()*-1, 2);
    }
    // cout << endl;
    output << sum;
    
}