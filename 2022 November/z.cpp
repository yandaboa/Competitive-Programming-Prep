#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(){
    vector<int> queen;
    queen.push_back(2);
    cout << queen[0];
    queen.fill(0);
    cout << queen[0];
}