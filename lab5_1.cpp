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
   int s;
  
   for(s = 0; s <= (n-m); s++){
       int i = 1, j = 1;
       while(j <= m && text[s+i] == pattern[j]){
           i++;
           j++;
       }
       if(j == m){
           cout << "Pattern occurs at shift ";
           cout << s;
           return 0;
       }
   }
   cout << "Pattern not found";
   return 0;
}
