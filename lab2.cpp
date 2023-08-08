#include <bits/stdc++.h>


using namespace std;


unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
   unsigned long long int r = 0;
   while(b != 0){
       r = a % b;
       a = b;
       b = r;
   }
   return a;
}


unsigned long long int power(unsigned long long int a, unsigned long long int x, unsigned long long int n){
   unsigned long long int res = 1;
   a = a % n;
   while(x > 0){
       if(x % 2 != 0)
           res = (res * a) % n;
       x = x / 2;
       a = (a * a) % n;   
   }
   return res;
}


bool isPrime(unsigned long long int n){
   unsigned long long int i = 1, k = 100, a = 0;
   if(n <= 1 || n == 4)
       return false;
   if(n <= 3)
       return true;


   while(i <= k){
       srand(time(0));
       a = 2 + (rand() % (n-3));
       if(gcd(a,n) != 1)
           return false;
       if(power(a, n-1, n) != 1)
           return false;
       i++;   
   }
   return true;
}


int main()
{
   unsigned long long int n;
   cin >> n;
   if(isPrime(n))
       cout << "Prime";
   else
       cout << "Not Prime";   


	unsigned long long int count = 0;
   for(unsigned long long int a = 2; a <= n-2; a++){
       if(power(a, n-1, n) == 1)
           count++;
   }
   cout << count << "\n";
   float p = (float)count/n-3;
   cout << p;




   return 0;
}





