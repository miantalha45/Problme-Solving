class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int i = 0, j = 0;
        int arrEl = 0;
        while(i < n)
        {
            if(nums[i] != 0)
            {
                nums[arrEl] = nums[i];
                arrEl++;
            }
            else{
                zeroCount += 1;
            }
            i++;
        }

        for(int i = 0; i < zeroCount; i++)
        {
            nums[arrEl] = 0;
            arrEl++;
        }
    }
};