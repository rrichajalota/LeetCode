/*  QUESTION-1 TWO SUM
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution.

    Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

    UPDATE (2016/2/13):
    The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> A;

        for(int i=0; i< nums.size(); i++){
                A.push_back(nums[i]);
        }
        
        sort(A.begin(), A.end());
        
        int first=0, second=0;
        int l= 0, r= A.size()-1;
        
        while(l < r){
            int sum= A[l]+ A[r];
            if(sum==target){
                first= A[l];
                second= A[r];
                break;
            }
            if(sum < target)
                l++;
            else --r;
        }
        //cout<<first<<endl;
        //cout<<second<<endl;
        for(int i=0; i < nums.size(); i++){
            if(nums[i]==first || nums[i]==second)
                ans.push_back(i);
        }
        
        if(ans[0] > ans[1])
            swap(ans[0], ans[1]);
            
        return ans;
    }
};