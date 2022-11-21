#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

vector<long long> arrOffsets, prefixSum;
// vector<int> prevOccs;
int testCases, arrSize;
map<long long, int> prev1;

int main(){
    // prevOccs.resize(900000);
    cin >> testCases;
    for(int i = 0 ; i < testCases; i++){
        long long res =0;
        cin >> arrSize;
        prefixSum.resize(arrSize + 1);
        prefixSum[0] = 0;
        string temp;
        cin >> temp;
        // prevOccs[0] = 0;
        for(int j = 1; j <= arrSize; j++){
            string t = temp.substr(j-1, 1);
            int intTemp = stoi(t);
            prefixSum[j] = prefixSum[j - 1] + intTemp;
        }

        // cout << endl;
        arrOffsets.resize(arrSize);
        prev1[0] = 1;
        for(int j = 0; j < arrSize; j++){
            arrOffsets[j] = prefixSum[j + 1] - j - 1;
            if(prev1.count(arrOffsets[j]) > 0){
                // cout << "w" << arrOffsets[j] << " ";
                res += prev1[arrOffsets[j]];
                prev1[arrOffsets[j]]++;
            } else {
                prev1[arrOffsets[j]] = 1;
            }
            // cout << arrOffsets[j] << " ";
        }
        // map<int, int>::iterator itr;
        // cout << "\nThe map gquiz1 is : \n";
        // cout << "\tKEY\tELEMENT\n";
        // for (itr = prev1.begin(); itr != prev1.end(); ++itr) {
        //     cout << '\t' << itr->first << '\t' << itr->second
        //          << '\n';
        // }

        cout << res << endl;
        prev1.clear();
        arrOffsets.clear();
        prefixSum.clear();
    }

    return 0;
}