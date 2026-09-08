class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        vector<int> result;
        int top = 0;
        int bottom = (int)matrix.size() - 1;
        int left = 0;
        int right = (int)matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) result.push_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};