void FindIsland(char** grid, int gridRow, int *gridCol, int row, int col){
    if(row<0 || row>=gridRow || col<0 || col >= gridCol[row] || grid[row][col]=='0'){
        return;
    }
    grid[row][col] = '0';
    FindIsland(grid, gridRow, gridCol, row+1, col);
    FindIsland(grid, gridRow, gridCol, row-1, col);
    FindIsland(grid, gridRow, gridCol, row, col+1);
    FindIsland(grid, gridRow, gridCol, row, col-1);
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    
    int count = 0;
    //int gridRow = gridSize;
    //int gridCol = gridColSize[gridRow];
    int i,j;
    for(i=0; i<gridSize; i++){
        for(j=0; j<gridColSize[i]; j++){
            if(grid[i][j]=='1'){
                count++;
                FindIsland(grid, gridSize, gridColSize, i, j);
            }
            
        }
    }
    return count;
}

