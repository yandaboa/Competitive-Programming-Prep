#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int numNums;
vector<long long> prefSum;


// long long KadaneAlg(){ greedy approach
//     cin >> numNums;
//     long long temp;
//     cin >> temp;
//     long long currSum = temp;
//     long long maxSum = temp;
//     for(int i = 1; i < numNums; i++){
//         cin >> temp;
//         currSum = max(currSum + temp, temp);
//         maxSum = max(currSum,maxSum);
//     }
//     return maxSum;
// }

int main(){
    //prefix sum approach
    cin >> numNums;

    prefSum.resize(numNums + 1);
    prefSum[0] = 0;
    long long minSoFar = prefSum[0];
    long long largestDiff = INT_MIN;
    for(int i = 1; i <= numNums; i++ ){
        long long temp;
        cin >> temp;
        prefSum[i] = prefSum[i - 1] + temp;
        largestDiff = max(largestDiff, prefSum[i] - minSoFar);
        minSoFar = min(minSoFar, prefSum[i]);
    }

    cout << largestDiff;

    // cout << KadaneAlg(); greedy approach
    
    return 0;

}