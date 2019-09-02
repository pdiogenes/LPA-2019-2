#include <iostream>
#include <cmath>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int matrix[100][100], N;

int findMaximumSum(){
    int m = INT_MIN, cur_sum = 0;

    for(int i = 0; i < N; i++){ //linha inicial
        for(int j = 0; j < N; j++){ //coluna inicial
            for(int k = 1; k <= N; k++){ //linha final
                for(int q = 1; q <= N; q++){ //coluna final
                    for(int r = i; r < k; r++){
                        for(int s = j; s < q; s++){
                            //cout << "linha inicial " << i << " linha final " << k << " coluna inicial " << j << " coluna final " << q << endl;
                            //cout << "r: " << r << " s: " << s << endl;
                            cur_sum += matrix[r][s];
                            if(cur_sum > m) m = cur_sum;
                        }
                    }
                    //cout << "soma atual: " << cur_sum << endl;
                    cur_sum = 0;
                }
            }
        }
    }

    //cout << "maior soma: " << m << endl;
    return m;

}

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    /*
    cout << endl << "Testando entradas:" << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    */
    
    int r = findMaximumSum();
    cout << r;

    return 0;
}