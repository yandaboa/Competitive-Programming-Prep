#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>

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
// cin.tie(0)->sync_with_stdio(0);

int N, M;
multiset<int> attacking, dAttacking;
priority_queue<pair<int, int> > nonAttack, otNonAttack, otherNonAttack;

ll attackingFirst()
{

    ll total = 0, unused = 0;
    bool allGone = true;
    while (!nonAttack.empty() && sz(attacking) > 0)
    {
        auto val = nonAttack.top(); nonAttack.pop();
        if (val.f * -1 <= *(attacking.rbegin()))
        {
            total += *(attacking.rbegin()) - (val.f * -1);
            auto itr = attacking.end();
            itr--;
            attacking.erase(itr);
        }
    }

    // if(allGone){
    //     for(auto a = attacking.begin(); a != attacking.end(); a++){
    //         unused += *a;
    //     }
    // }
    // total += unused;
    return total;
}

ll defendingFirst()
{
    ll total = 0, unused = 0;
    bool allGone = true;

    while(!otherNonAttack.empty() && sz(dAttacking) > 0){
        auto val = otherNonAttack.top(); otherNonAttack.pop();
        auto itr = dAttacking.upper_bound(val.f * -1);
        if (itr != dAttacking.end())
        {
            dAttacking.erase(itr);
        } else {
            allGone = false;
        }
    }

    while (!otNonAttack.empty() && sz(dAttacking) > 0)
    {
        auto val = otNonAttack.top(); otNonAttack.pop();
        auto itr = dAttacking.lower_bound(val.f * -1);
        if (itr != dAttacking.end())
        {
            total += *(itr)-(val.f*-1);
            dAttacking.erase(itr);
        } else {
            allGone = false;
        }
    }

    if (allGone)
    {
        for (auto a = dAttacking.begin(); a != dAttacking.end(); a++)
        {
            unused += *a;
        }
    }
    total += unused;
    return total;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        int a;
        cin >> a;
        if (str.compare("ATK") == 0)
        {
            nonAttack.push(mp(-1 * a, 0));
            otNonAttack.push(mp(-1 * a, 0));
        }
        else
        {
            otherNonAttack.push(mp(-1 * a, 0));
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        attacking.insert(a);
        dAttacking.insert(a);
    }
    ll attackFirst = attackingFirst();
    ll defenceFirst = defendingFirst();
    // cout << attackFirst << " " << defenceFirst << endl;
    cout << max(attackFirst, defenceFirst);
}

// approach: do it two ways and take the max of the dmg u get from the two ways.
// way 1: take out all attack cards first (smallest -> largest) with highest possible card at that moment. Then take out all defense cards with the smallest attacking larger than it. If it gets to this point, all opposing cards gone, add the rest to total dmg.
// way 2: take out all defense cards first (smallest -> largest) with smallest attacking larger than it. Then take out all attack (smallest -> largest) with largest at that moment. if all cards gone, add rest to dmg.