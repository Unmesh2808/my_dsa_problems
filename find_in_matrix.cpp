 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        // int n = matrix[0].size();
        for (int i=0;i<m;i++){
            if (find(matrix[i].begin(), matrix[i].end(), target)!=matrix[i].end()){
                return true;
            }
        }
        return false;
    }


