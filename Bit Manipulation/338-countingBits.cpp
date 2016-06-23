/*	LeetCode Question- 338
	Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary 
	representation and return them as an array.

	Example:
	For num = 5 you should return [0,1,1,2,1,2].
*/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        for (int i=0; i<= num; i++){
            result[i]=countOnes(i);
        }
        return result;
    }
    int countOnes(int num){
        int count=0;
        while(num){
            count++;
            num= num & (num-1);
        }
        return count;
    }
};