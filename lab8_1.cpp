#include<iostream>
using namespace std;

int main(){

    string text, pattern;
    cout << "Enter text : ";
    cin >> text;
    cout << "Enter pattern : ";
    cin >> pattern;
  
    int n = text.length();
    int m = pattern.length();

    int pi[m];
    pi[0] = 0;
    int k = 0;
    for(int q = 1; q < m; q++){
        while(k > 0 && pattern[k+1] != pattern[q]){
            k = pi[k];
        }
        if(pattern[k+1] == pattern[q]){
            k++;
        }
        pi[q] = k;
    }
    for(int i = 0; i < m; i++){
        cout << pi[i] << " ";
    }
    cout << endl;

    int q = 0;
    for(int i = 0; i < n; i++){
        while(q > 0 && pattern[q] != text[i]){
            q = pi[q];
        }
        if(pattern[q+1] == text[i]){
            q++;
        }
        if(q == m){
            cout << "Pattern occurs at " << i-m << endl;
            q = pi[q];
        }
        
    }
}