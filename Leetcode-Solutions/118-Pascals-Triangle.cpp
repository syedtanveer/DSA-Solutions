class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(numRows <= 0) return triangle;
        vector<int> first_row{1};
        triangle.push_back(first_row);
        for(int i = 1; i < numRows; i++){
            vector<int> row{1};
            for(int  j = 1; j < i; j++){
                row.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};