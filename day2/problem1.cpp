#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

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
            }
        }

        cout << safe;
        file.close();
    }
}

//236