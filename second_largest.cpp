#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
      //if vector size is less than 2 than there is no second element 
      //to call the second largest
        if(arr.size() < 2) {
          return -1;
        } 
        
        // take smallest integer value possible 
        int currentLargest = INT_MIN;
        int currentSecondLargest = INT_MIN;

        //iterate over vector
        for (int x : arr) {

          //if element value is greater than your current largest value then 
          //element becomes your current largest value and your current largest value 
          //becomes your current second largest value
          if(x > currentLargest) {
            currentSecondLargest = currentLargest;
            currentLargest = x;  
          } 
          //if element is smaller than current largest value but still bigger than 
          //your current second largest value then element becomes your current second largest value
          else if (x < currentLargest && x > currentSecondLargest) {
            currentSecondLargest = x;
          }
        }
        
        //if your current largest value has not changed from smallest integer value
        //this will happen when all the element in the vector are same then return -1
        //other wise return your second largest value
        return currentSecondLargest == INT_MIN ? -1 : currentSecondLargest; 
        
    }
};


int main() {
    Solution s;
    vector<int> arr = {10, 5, 20, 20, 8};
    cout << "Hello" << s.getSecondLargest(arr) << endl; // Output: 10
    return 0;
}