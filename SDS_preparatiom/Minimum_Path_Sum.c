#define MIN(a,b) (((a)<(b))?(a):(b))

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = *gridColSize;
    if(row==0)
        return 0;

    //int** dp_table = (int**)malloc(sizeof(int[row][col]));
    
    int dp_table[row][col];
    dp_table[0][0] = grid[0][0];

    //fill the first row.
    for(int i=1; i<col; i++){
        dp_table[0][i] = dp_table[0][i-1]+grid[0][i];
    }
    //fill the first column.
    for(int i=1; i<row; i++){
        dp_table[i][0] = dp_table[i-1][0]+grid[i][0];
    }
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            dp_table[i][j] = grid[i][j] + MIN (dp_table[i-1][j], dp_table[i][j-1]);
        }
    }
    
    return dp_table[row-1][col-1];
}