/*	80. Remove Duplicates from Sorted Array II  

	Follow up for "Remove Duplicates":
	What if duplicates are allowed at most twice?

	For example,
	Given sorted array nums = [1,1,1,2,2,3],

	Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int wt=0;
        
        for(int i=0; i < nums.size(); ++i){
            nums[wt++]= nums[i];
            
            if(i+1 < nums.size() && nums[i] == nums[i+1]){
                nums[wt++]= nums[i];
                ++i;
                while(nums[i]==nums[i+1])
                    i++;
            }
        }
        return wt;
    }
};