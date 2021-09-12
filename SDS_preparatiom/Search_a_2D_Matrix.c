
int a;
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    int i;
    a=0;
    int col = *matrixColSize;
    for(i=0; i<matrixSize; i++){
        recursion(0,matrix, col, target, i);
    }
    if(a==1){
        return true;
    }
    else return false;
    //return answer;
}
void recursion(int j, int** matrix, int col, int target, int i){
    if(j==col){
        return;
    }
    if(matrix[i][j]==target){
        a = 1;
    }
    else{
        recursion(j+1, matrix, col, target, i);
    }
    
}