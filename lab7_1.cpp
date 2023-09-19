//Rabin-Karp ALgorithm
#include<iostream>
using namespace std;


void rabin_karp(string t,string p,int d,int q){
	int n = t.length();
	int m = p.length();
	int p0=0,t0=0;
	
	for(int i=0;i<m;i++){
		t0 = (d*t0 + (t[i] -'0'))%q;
		p0 = (d*p0 + (p[i]-'0'))%q;
	}
	
	int h = pow(d,m-1);
	int flag1=0;
	for(int i=0;i<=n-m;i++){
		if(p0 == t0){
			int flag=0;
			for(int j=0; j < m; j++){
				if(p[j] != t[i+j]){
				    flag=1;
				}
			}
				if(!flag){
					cout<<"Pattern found at shift :" << i << endl;
					flag1 = 1;
				}
		}
		if(i < n-m){
		  t0 = (d*(t0 - ((t[i]-'0')*h) )+ t[i+m]-'0') % q;
		}
		if(t0 < 0 ){
			t0 += q;
		}
	}
	if(!flag1)
	cout<<"string match not found\n";
}

int main() {
	
	string text;
    string pattern;
    int q, d = 10;
    cout << "Enter text : ";
    cin >> text;
    cout << endl;
    cout << "Enter pattern : ";
    cin >> pattern;
    cout << endl;
    cout << "Enter prime number : ";
    cin >> q;
    cout << endl;

    rabin_karp(text,pattern,d,q);
	return 0;
}
   
 

