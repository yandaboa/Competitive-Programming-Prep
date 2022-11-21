#include <fstream>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> lights;
vector<int> prefixSum;
map<long long, int> sumAppearsAt;
int desired, arrSize, numBroken;

int main(){
    ifstream input("maxcross.in");
    ofstream output("maxcross.out");

    input >> arrSize >> desired >> numBroken;
    lights.resize(arrSize, true);

    for(int i = 0; i < numBroken; i++){
        int temp;
        input >> temp;
        lights[temp - 1] = false;
    }
    
    prefixSum.resize(arrSize + 1);
    prefixSum[0] = 0;
    int shortest = arrSize + 1;
    for(int i = 1; i <= arrSize; i++){
        prefixSum[i] = lights[i - 1] ? prefixSum[i - 1] + 1 : prefixSum[i - 1];
        // sumAppearsAt[prefixSum[i]] = i;
        // cout << "l" << lights[i - 1] << " " <<  prefixSum[i] << " ";
        // if(sumAppearsAt.count(prefixSum[i] - desired) > 0){
        //     shortest = min(shortest, i - sumAppearsAt[prefixSum[i] - desired]);
        // }
    }

    for(int i = 1; i < prefixSum.size() - desired + 1; i++){
        cout << desired - (prefixSum[i + desired - 1] - prefixSum[i - 1]) << endl;
        shortest = min(shortest, desired - (prefixSum[i + desired - 1] - prefixSum[i - 1]));
    }

    output << shortest;
    input.close();
    output.close();
}