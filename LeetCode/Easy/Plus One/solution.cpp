class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        for(int i = digits.size()-1; i>=0; i--){
            if(digits[i]>9&&i>0){
                digits[i] = 0;
                digits[i-1]++;
            }
            else if(digits[i]>9){
                digits[i] = 0;
                digits.insert(digits.begin(),1);
            }
            else{
                break;
            }
        }

        return digits;
    }
};