#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int cowNum;
vector<int> cows;
// vector<long long> prefSum;
vector<int> lastTimeRemainderWas;

int core(){
    //below solution only passed 9/10 test cases.
    // //build the prefix sum
    // prefSum.resize(cowNum + 1);
    // prefSum[0] = 0;
    // for(int i = 1; i < prefSum.size(); i++){
    //     prefSum[i] = prefSum[i - 1] + cows[i - 1];
    //     cout << prefSum[i] << " ";
    // }

    // //iterate the prefSum in n^2 fashion, but start from ends to make it more efficient
    // int largest = 0;
    // for(int i = 1; i < prefSum.size() - largest; i++){
    //     for(int j = prefSum.size() - 1; j >= i + largest; j--){
    //         if((prefSum[j] - prefSum[i - 1]) %7 == 0){
    //             largest = max(j - i + 1, largest);
    //         }
    //     }
    // }

    // return largest;
    return 0;
}

void readInput(){
    ifstream input("div7.in");
    ofstream output("div7.out");

    input >> cowNum;
    // cows.resize(cowNum);
    // for(int i = 0; i < cowNum; i++){
    //     int temp;
    //     input >> temp;
    //     cows[i] = temp;
    // }
    
    // output << core();

    lastTimeRemainderWas.resize(7, -1);

    int mostCows = 0;
    int remainder = 0;
    for(int i = 0; i < cowNum; i++){
        int cowID;
        
        input >> cowID;
        remainder = (remainder + cowID)%7;
        if(lastTimeRemainderWas[remainder] == -1){
            lastTimeRemainderWas[remainder] = i;
        } else {
            mostCows = max(mostCows, i - lastTimeRemainderWas[remainder]);
        }
    }

    output << mostCows;

    input.close();
    output.close();
}

int main(){
    readInput();
    return 0;
}