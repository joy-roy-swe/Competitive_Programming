void permutation(int n, int *k, char *s, int i){
    if (i == n){
        *k -= 1;
        return;
    }
    
    for (int j = 1; j < n + 1; j++){
        
        if (*k == 0) 
            return;

        int check = 0;
        for (check = 0; check < i; check++){
            if (s[check] == j + '0') break;  
        } 
       
        if (check != i) continue;
        s[i] = j + '0';
        permutation(n, k, s, i+1);
    }
}

char * getPermutation(int n, int k){
    char * s = malloc(sizeof(char) * (n + 1));
    s[n] = '\0';
    
    permutation(n, &k, s, 0);
    
    return s;
}