/*	189. Rotate Array  
	Rotate an array of n elements to the right by k steps.
	For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
	Note:
	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
/*	Time omplexity - O(n) Space complexity- O(1) 
	if nums=[1 2 3 4 5] , k = 3
	first reverse n-k elements, nums= [2 1 3 4 5]
	Then reverse k elements from the end, nums= [2 1 5 4 3]
	Now reverse the entire array, nums= [3 4 5 1 2]
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n= nums.size();

        k %= n;

        reverse(nums.begin(),nums.begin()+n-k);

        reverse(nums.begin()+n-k,nums.end());

        reverse(nums.begin(),nums.end());
    }

};