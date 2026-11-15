class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(); // rows
        int cols = grid[0].size(); // colums
        // hume oth column ko 1 bnana hhai kyu whi sbse jada value dega
        for(int i = 0; i<rows; i++){
            if(grid[i][0]==0){
                //flipping krdi humne idhr
                for(int j = 0; j<cols; j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        // ab har column ke noz or noo calculate krenge 
        for(int j = 0; j<cols; j++){
            int noz = 0;
            int noo = 0;
            for(int i = 0; i<rows; i++){
                if(grid[i][j]==1) noo++;
                else noz++;
            }
            if(noz>noo){
                for(int i = 0; i<rows; i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i<rows; i++){
            int x = 1;
            for(int j = cols-1; j>=0; j--){
                sum +=grid[i][j]*x;
                x *=2;
            }
        }
        return sum;
    }
};