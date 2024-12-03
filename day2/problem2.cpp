#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool func (vector<int> numarr) {
    vector<int> numarr1(numarr);
    bool toggle = true;
    int n = numarr.size();
    for (int j = 0; j < n; j++) {
        toggle = true;
        numarr = numarr1;
        numarr.erase(numarr.begin()+j);
        if (numarr[0] > numarr[1]) {
            for (int i = 0; i < n -2; i++) {
                if (numarr[i] > numarr[i+1] + 3 || numarr[i] <= numarr[i+1]) {
                    toggle = false;
                    break;
                }
            } 
        } else {
            for (int i = 0; i < n-2; i++) {
                if (numarr[i]+3  < numarr[i+1] || numarr[i] >= numarr[i+1]) {
                    toggle = false;
                    break;
                }
            } 
        }
        if (toggle) {
            break;
        }
    }

    return toggle;
}


int main () {
    ifstream file("input.txt");
    int safe = 0;
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            int toggle = true;
            vector<int> numarr;
            istringstream stream(line);
            int num;
            while (stream >> num) {
                numarr.push_back(num);
            }
            
            if (numarr[0] > numarr[1]) {
                for (int i = 0; i < numarr.size() -1; i++) {
                    if (numarr[i] > numarr[i+1] + 3 || numarr[i] <= numarr[i+1]) {
                        toggle = false;
                        break;
                    }
                } 
            } else {
                for (int i = 0; i < numarr.size() -1; i++) {
                    if (numarr[i]+3  < numarr[i+1] || numarr[i] >= numarr[i+1]) {
                        toggle = false;
                        break;
                    }
                } 
            }

            if (toggle) {
                safe++;
            } else {
                if (func(numarr)) {
                    safe++;
                }
            }
        }

        cout << safe;
        file.close();
    }
}
