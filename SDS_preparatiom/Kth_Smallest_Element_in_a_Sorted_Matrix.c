

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int row = matrixSize;
    int col = *matrixColSize;
    int newSize = row*col;
    int *newArray = (int*) calloc(newSize, sizeof(int));
    int i,j;
  
    arrayConversion(0, matrix, row, col, newArray, 0, 0);
    
    mergeSort(newArray,0,newSize-1);

    if(k>newSize){
        return 0;
    }
    else{
        return newArray[k-1];
    }
    
}

void arrayConversion(int j, int** matrix, int row, int col, int* newArray, int i, int x){
        
    if(j==col){
        i+=1;
        j=0;
    }
    if(i==row){
        return;
    }
    newArray[x] = matrix[i][j];
    arrayConversion(j+1, matrix, row, col, newArray, i, x+1);
    
}


void mergeSort(int* newArray, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(newArray, l, m);
    mergeSort(newArray, m + 1, r);

    merge(newArray, l, m, r);
  }
}


void merge(int* newArray, int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = newArray[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = newArray[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      newArray[k] = L[i];
      i++;
    } else {
      newArray[k] = M[j];
      j++;
    }
    k++;
  }


  while (i < n1) {
    newArray[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    newArray[k] = M[j];
    j++;
    k++;
  }
}