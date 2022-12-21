#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> hasOutgoing;

int N;
int main(){
    ifstream input("factory.in");
    ofstream output("factory.out");
    input >> N;
    hasOutgoing.resize(N, 0);
    for(int i = 1; i < N; i++){
        int a, b;
        input >> a >> b;
        hasOutgoing[a - 1]++;
    }

    int noOuts = 0;
    string res = ""; 
    for (int i = 0; i < N; i++)
    {
        if(hasOutgoing[i] == 0){
            res = to_string(i + 1);
            noOuts++;
        }
    }
    if(noOuts > 1){
        res = "-1";
    }
    output << res;
    output.close();
    input.close();
    
}