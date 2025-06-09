#include <iostream>
#include <string>
using namespace std;
// Time complexity : O(n), space complexity : O(1)
class Solution {
public:
    int romanToInt(string s) {
        static const int arr[256]={
            ['I']=1,
            ['V']=5,
            ['X']=10,
            ['L']=50,
            ['C']=100,
            ['D']=500,
            ['M']=1000,
        };
        int sum = 0, n = s.size();
        // here when we do arr[unsinged char s[i]] the cpu computes the effective address : address = base-val of arr + (unsigned char)s[i]*sizeOf(int)
        // so for 'I' it will be val[73] sent which will be looked up using base-val let's say 0x1000+73*4 and we will get the value 1 etc .
        sum+=arr[(unsigned char)s[n-1]];
        for(int i = n-2;i>=0;i--){
            int curr = arr[(unsigned char)s[i]];
            int next = arr[(unsigned char)s[i+1]];
            if(curr<next) sum-=curr;
            else sum+=curr;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl; //3
    cout << s.romanToInt("LVIII") << endl; //58
    cout << s.romanToInt("MCMXCIV") << endl; //1994
}
