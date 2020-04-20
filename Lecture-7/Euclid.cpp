// Euclid
#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int eea(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1,y=0;
		cout<<x<<" "<<y<<endl;
		return a;
	}

	int x1,y1;
	int ans = eea(b,a%b,x1,y1);

	x = y1;
	y = x1-(a/b)*y1;
	cout<<x<<" "<<y<<endl;
	return ans;
}

int main(){
	int a,b;
	cin>>a>>b;
	// cout<<gcd(a,b)<<endl;
	int x,y;
	cout<<eea(a,b,x,y)<<endl;


	return 0;
}