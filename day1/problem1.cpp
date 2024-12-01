#include <iostream>
#include <limits>
#include <vector>
using namespace std;


int main () {
  vector<int> arr1;
  vector<int> arr2;
  int num1; 
  int num2;
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    scanf("%d %d", &num1, &num2);
    arr1.push_back(num1);
    arr2.push_back(num2);

  }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    int index = 0;
    for (int i = 0; i < 1000; i++) {
      int count = 0;
      while (arr1[i] == arr2[index]) {
        count++;
        index++;
      }
      sum += max(arr2[i] - arr1[i], -1*(arr2[i] - arr1[i]));
    }
    printf("%d", sum);
  
  return 0;
}

