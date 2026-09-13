class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i,j = 0; i<nums1.size(), j<nums2.size(); i++){

            if(nums2[j]<=nums1[i]){

                nums1.insert(nums1.begin()+i, nums2[j]);
                j++;
                m++;
                nums1.pop_back();
                continue;
            }

            else if(i>m-1){

                while(j<n){
                    nums1[i]=nums2[j];
                    i++;
                    j++;
                }

                break;
            }


        }
    }
};