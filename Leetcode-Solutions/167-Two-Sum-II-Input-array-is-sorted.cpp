class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> v{1, static_cast<int>(numbers.size())};
        while(v[0] <= v[1]){
            int sum = numbers[v[0]-1] + numbers[v[1]-1];
            if(sum < target){
                v[0]++;
            }
            else if(sum > target){
                v[1]--;
            }
            else{
                break;
            }
        }
        return v;
    }
};