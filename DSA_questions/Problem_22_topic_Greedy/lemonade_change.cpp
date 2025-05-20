#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0,count10 = 0,n = bills.size();
        for(int i = 0;i<n;i++)
        {
            if(bills[i]==5){
                count5++;  
            }
            if(bills[i]==10){
                if(count5<=0) return false;
                count5--;
                count10++;  
            }
            if(bills[i]==20)
            {
                // either can give three 5 dollar bills or one 10 dollar , one five dollar bill
                if(count5>0 && count10>0){
                    count5--;
                    count10--;
                }
                else if(count5>=3){
                    count5-=3;
                }
                else 
                    return false;

            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> bills = {5,5,5,10,20};
    cout << sol.lemonadeChange(bills) << endl;
    return 0;
}
