#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int N;
    vector<int> order;

    fin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        fin >> temp;
        order.push_back(temp);
    }
    int indexOut = 0;
    int out = -1;
    bool forward; // true if the number was moved backwards between larger numbers
    for(int i = 1; i < N; i++){
        if(order[i] < order[i - 1]){
            indexOut = i;
            out = order[i];
            if(i == N - 1){
                forward = true;
                break;
            }
            if(order[i - 1] <= order[i + 1]){
                forward = true;
            } else {
                indexOut--;
                out = order[indexOut];
                forward = false;
            }
            break;
        }
    }
    cout << "checkpoint 1" << endl;
    int counter = 0;
    int last = -1;
    int before = 0;
    if(forward){
        for(int i = 0; i < indexOut; i++){
            if(last != order[i]){
                counter++;
                if(order[i] <= out){
                    before++;
                }
                last = order[i];
            }
        }
    } else {
        for(int i = N - 1; i > indexOut; i--){
            if(last != order[i]){
                counter++;
                cout << order[i] << endl;
                if(order[i] >= out){
                    before++;
                }
                last = order[i];
            }
        }
    }

    fout << counter - before << endl;
}