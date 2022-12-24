#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
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

priority_queue<pair<int, char> > balls;
multiset<char> ballz;

int main(){
    string str; cin >> str;
    int level = 0;
    for (int i = 0; i < sz(str); i++)
    {
        if(str[i] == '('){
            level--;
        } else if(str[i] == ')'){
            pair<int, char> a;
            if(!balls.empty()){
                a = balls.top();
            }
            while(!balls.empty() && a.f == level){
                ballz.erase(ballz.find(a.s));
                balls.pop();
                if(!balls.empty()){
                    a = balls.top();
                }
                // a = balls.top();
            }
            level++;
        } else {
            if(ballz.find(str[i]) != ballz.end()){
                cout << "No";
                return 0;
            }
            ballz.insert(str[i]);
            balls.push(mp(level, str[i]));
        }
    }
    
    cout << "Yes";
    return 0;
}

