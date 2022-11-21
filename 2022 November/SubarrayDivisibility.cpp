#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long magic;
// vector<int> prefixSum;
map<long long, int> preRems;

int main(){
    cin >> magic;
    // prefixSum.resize(magic + 1);
    // prefixSum[0] = 0;
    long long currRemainder = 0;
    long long subArrays = 0;
    preRems[0] = 1;
    // cout << -2%2 << endl;
    for(int i = 1; i <= magic; i++){
        int temp;
        cin >> temp;
        currRemainder = ((currRemainder + temp)%magic + magic)%magic;
        if(preRems.count(currRemainder) == 0) {
            preRems[currRemainder] = 1;
        } else {
            subArrays += preRems[currRemainder];
            preRems[currRemainder]++;
        }
    }

    cout << subArrays;

}