#include<bits/stdc++.h>
using namespace std;

int main()
{
    long num = 0, temp, n = 0;
    cin >> num;
    vector < long > arr(num), arr_sum(num);

    for (int i = 0; i < num; ++i){
        cin >> arr[i];
    }
    arr_sum[0] = arr[0];
    for (int i = 1; i < num; ++i){
        arr_sum[i] = arr[i] + arr_sum[i - 1];
    }
    for (int i = 0; i < num; ++i){
        n = (-1 + sqrt(1 + 8 * (num - i))) / 2;
        n = (n * (n + 1)) / 2;
        temp = 0;
        if (i){
            temp = arr_sum[n - 1 + i] - arr_sum[i - 1];
        } else{
            temp = arr_sum[n - 1];
        }
        arr[i] = temp;
    }
    sort(arr.begin(), arr.end());
    cout << arr[num - 1] << endl;  
}