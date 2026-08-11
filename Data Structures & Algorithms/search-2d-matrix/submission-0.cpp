class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() - 1;
        int row;
        while(start<=end){
            row=(start+end)/2;

            if(target<matrix[row][0]){
                end = row-1;
            } else if(target>matrix[row][0]){
                start=row+1;
            }else{
                return true;
            }
        }

        start=0;
        end = matrix[row].size()-1;

        while(start<=end){
            int middle = (start+end)/2;

            if(target<matrix[row][middle]){
                end=middle-1;
            }else if(target>matrix[row][middle]){
                start=middle+1;
            }else{
                return true;
            }
        }

        return false;
    }
};
