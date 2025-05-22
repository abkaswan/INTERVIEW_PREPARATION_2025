#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // optimised approach : using O(n) tc and O(1) sc , two pointer approach
    bool checkValidString(string s) {
        // ok so we will take cmin and cmax for this problem 
        // cmax : what if we treat * as (. now if ) exceeds this also that means it is invalid and we need to return false. essentially cmax is how many ( could be paired.
        // cmin : what if we treat * as ) or '' . cmin is essetially how many ( are there that we must pair. So we go to l->r we check if ( do cmin++ , check ) do cmin-- , * do cmin-- , let's take examples : (*) now here * if we take as ) or '' , we take it as '' , so for cmin = 1->0->-1 but if it is negative then we need to make it 0 again. why let's take an extension of same ex : (*)() here now cmin = 1->0->-1->0>-1 this also we can say if we check if cmin>0 we will return false. because we needed to close those right ? but what if (*)( = 1->0->-1->0 then we are returning it as true but this is false , why because after treating * as ) and encoutering ) again at the third index we did not ignore that part , we should have made the choice that if there is excess of ) we are considering then maybe we might have taken * as ) but should have taken as '', now next question is what if we make -ve as 0 but the -ve is coming because of excess ) but again that case we are already handling using cmax , so if there are anything like this : ()) it will return false only which is correct without setting it 0 again. This case will be taken care only when using * we are considering -ve that is not being taken care. so without worry do cmin = max(cmin,0) , the second argument you can give is that cmin is the ( parenthesis that must be paired so those that must be paired that value can't be negative so needs to be positive only. 
        int cmin = 0,cmax = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                cmin++;
                cmax++;
            }
            else if(s[i]==')') {
                cmin--;
                cmax--;
            }
            else if(s[i]=='*'){
                cmin--;
                cmax++;
            }
            
            if(cmax<0) return false;
            cmin=max(0,cmin);
        }
        return cmin==0;
    }
};
int main() {
    Solution sol;
    string s;
    cin >> s;
    bool result = sol.checkValidString(s);
    cout << result << endl;
    return 0;
}
