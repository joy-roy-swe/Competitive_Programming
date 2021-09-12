

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void BFS(int** matrix,int i, int j, int rows, int *cols){
    int value = matrix[i][j] + 1; 
    //printf("%d", value);
    
    //left
    if (j - 1 >= 0 && value < matrix[i][j - 1]){
        matrix[i][j - 1] = value;
        BFS(matrix,i, j - 1, rows,cols );
    }
    //right
    if (j + 1 < cols && value < matrix[i][j + 1]){
        matrix[i][j + 1] = value;
        BFS(matrix,i, j + 1, rows, cols);
    }
    //bottom
    if (i - 1 >= 0 && value < matrix[i - 1][j]){
        matrix[i - 1][j] = value;
        BFS(matrix,i - 1, j, rows, cols);
    }
    //right
    if (i + 1 < rows && value < matrix[i + 1][j]){
        matrix[i + 1][j] = value;
        BFS(matrix,i + 1, j, rows, cols);
    }
}
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    if (matSize == 0) return mat;
    *returnSize=matSize;
    returnColumnSizes[0]=matColSize;
    int i,j;

    for (i = 0; i < matSize; i++){
        for (j = 0; j < *matColSize; j++){
            if (mat[i][j] != 0)
                mat[i][j] = 214748364;
        }
    }

    for(i=0; i<matSize; i++){
        for(j=0; j<*matColSize; j++){
            BFS(mat,i,j,matSize,*matColSize);
        }
    }

    return mat ;
}