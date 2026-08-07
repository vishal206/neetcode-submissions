class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int end = n - 1;
        int row;
        while(start<=end){
            row=(start+end)/2;
            cout<<"here: "<<row<<endl;
            if(target<matrix[row][0]){
                end = row-1;
            } else if(target>matrix[row][m-1]){
                start=row+1;
            }else{
                break;
            }
        }
        cout<<row;
        if(start>end){
            return false;
        }

        start=0;
        end = m-1;

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
