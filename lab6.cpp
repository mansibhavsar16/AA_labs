//Sum of Subset reduces to 0/1 Knapsack

#include<iostream>
using namespace std;

bool knapsack(int p[], int w[], int cap, int profit){
    int n = 4;
    int M[n][cap];
    for(int i = 0; i < cap; i++){
        M[0][i] = 0;
    }
    for(int i = 0; i < n; i++){
        M[i][0] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < cap; j++){
            if(w[i] < j){
                if(p[i] + M[i-1][j-w[i]] > M[i-1][j]){
                    M[i][j] = p[i] + M[i-1][j-w[i]];
                }
                else{
                    M[i][j] =  M[i-1][j];
                }
            }
            else{
                M[i][j] =  M[i-1][j];
            }
        }
    }
    if(M[n][cap] >= profit)
        return true;
    return false;    


}

int main(){
    int S[] = {3, 2, 7, 1};
    int sum = 6;

    if(knapsack(S, S, sum, sum))
        cout << "Solution exists";
    else    
        cout << "Solution does not exists";    
}