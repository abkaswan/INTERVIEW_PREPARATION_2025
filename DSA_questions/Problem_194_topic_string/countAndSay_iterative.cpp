#include<iostream>
#include <utility> // for std::move
using namespace std;
// time complexity : outer loop run from 2 to n => O(n) , for each iteration we process the current string s to generate the next string in the sequence , so if we let L(i) be the length of the string at step i , then the inner loop runs in O(L(i-1)) time . The length of the string can grow exponentially in the worst case , but on average it grows by a factor of about 1.3 to 1.5 per step . So we can approximate L(i) as O(1.4^i) . Therefore , the overall time complexity can be approximated as O(n * 1.4^n) in the average case .
// so at last time complexity is O(n * 1.4^n)

// space complexity : O(1.4^n) for storing the string at each step , which can grow exponentially in the worst case . So the space complexity is O(1.4^n) in the average case .
class Solution {
public:
    string countAndSay(int n) {
        // method : use the iterative method where we start from i = 2 to i = n
        // convert 1 into string and pass that maybe 
        string s = "1";
        for(int i = 2;i<=n;i++){
            // pre-allocate space for temp string to avoid multiple allocations
            string temp = "";
            temp.reserve(s.size() * 2); // worst case scenario every digit is different
            // for each i take it's RLE ?
            // countAndSay(i) = RLE of countAndSay(n-1)
            // so take count of repeating numbers and replace them
            for(int j=0;j<s.size();){
                int count = 1;
                while(j+count<s.size() && s[j]==s[j+count])
                {    
                    count++;
                }
                temp+=to_string(count)+s[j];
                j = j+count;
            }
            // s = temp;
            s = std::move(temp); // using move semantics to avoid deep copy
        }
        return s;
    }
};
int main(){
    Solution sol;
    int n = 5;
    cout<<sol.countAndSay(n);
    return 0;
}