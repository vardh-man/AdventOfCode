#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
using namespace std;

int main () {
  vector<int> arr1;
  unordered_map<int,int> map(0);
  int num1; 
  int num2;
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    cin >> num1 >> num2;
    arr1.push_back(num1);
    if (map[num2] > 0 ) {
      map[num2]++;
    } else {
      map[num2] = 1;
    }
  }
    sort(arr1.begin(), arr1.end());
    for (int i = 0; i < 1000; i++) {
      if (map[arr1[i]]) {
        sum += arr1[i]*map[arr1[i]];
      }
    }
    cout << sum;
  
  return 0;
}

