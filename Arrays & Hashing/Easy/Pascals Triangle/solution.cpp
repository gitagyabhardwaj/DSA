class Solution {
public:

    vector<int> rowgen(int numrows, vector<vector<int>>& num){
                if(numrows==1){
                    return vector<int>{1};
                }

                num.emplace_back(rowgen(numrows-1, num));


                vector<int> temp;
                temp.emplace_back(1);
                for(int i= 0; i<numrows-2; i++){
                   temp.emplace_back(num.back()[i] + num.back()[i+1]);
                }
                temp.emplace_back(1);

                return temp;
                
            }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        numRows++;
        rowgen(numRows, nums);

        return nums;
    }
};