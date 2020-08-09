class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Uses Floyd's cycle detection algorithm
        //finding collision
        int slow_pointer = nums[0];
        int fast_pointer = nums[0];
        do{
            slow_pointer = nums[slow_pointer];
            fast_pointer = nums[nums[fast_pointer]];
        }while(slow_pointer != fast_pointer);
        // now find start of cycle
        fast_pointer = nums[0];
        while(slow_pointer != fast_pointer){
            slow_pointer = nums[slow_pointer];
            fast_pointer = nums[fast_pointer];
        }
        return slow_pointer;
    }
};