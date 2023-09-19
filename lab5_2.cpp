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


   int shift[25];
   for(int i = 0; i < 25; i++){
       shift[i] = m;
   }


   for(int i = 0; i < m-1; i++){
       shift[pattern[i] - 'a'] = m-1-i;
   }
   // for(int i = 0; i < 25; i++){
   //     cout << shift[i] << " " ;
   // }


   int j = 0;
   while(j + m <= n){
       if(text[j+m-1] == pattern[m-1]){
           int i = m-2;
           while(i >= 0 && pattern[i] == text[j+i]){
               i--;
           }
           if(i == -1)
               cout << "Pattern found at " << j << " ";
       }
       if(text[j+m-1] == '_' || text[j+m-1] == ' ' || text[j+m-1] == '.'){
           j += m;
       }
       else
           j += shift[text[j+m-1] - 'a'];
   }
   //cout << "Pattern not found";
}