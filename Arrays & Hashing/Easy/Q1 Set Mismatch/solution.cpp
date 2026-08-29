class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        std::sort(nums.begin(),nums.end());
        vector<int> answer{0,0};



        for(int i = 0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                answer[0]= nums[i];
            }
            else if(nums[i+1]-nums[i]!=1)
                answer[1]=nums[i]+1;
            

        }

        if(nums[0]!=1)
            answer[1]=1;
        else if(nums[n-1]!=n)
            answer[1]=n;



        return answer;
    }
};