/*  215. Kth Largest Element in an Array

    Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

    For example,
    Given [3,2,1,5,6,4] and k = 2, return 5.

    Note: 
    You may assume k is always valid, 1 ≤ k ≤ array's length
*/

class Solution {
public:
    void maxheapify(vector<int>& nums, int i, int heapsize){
        int l= 2 * i + 1;
        int r= 2* i + 2, largest= i;
        if(l < heapsize && nums[l] > nums[largest])
            largest= l;
        if(r < heapsize && nums[r] > nums[largest])
            largest= r;
        if(largest != i){
            swap(nums[largest], nums[i]);
            maxheapify(nums, largest, heapsize);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int heapsize= nums.size();
        for(int i= (heapsize-1)/2; i >= 0; --i){        //build maxheap
            maxheapify(nums, i, heapsize);
        }
        //extract max element k-1 times.
        for(int i = 1; i < k; i++){
            swap(nums[0], nums[heapsize-1]);
            --heapsize;
            maxheapify(nums, 0, heapsize);
        }
        return nums[0];
    }
};