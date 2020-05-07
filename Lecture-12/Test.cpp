// MagicNumber
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[ 2005 ][ 2005 ][ 2 ][ 2 ][ 2 ];
string s;
string a,b;
ll d,m;
ll solve(ll pos, ll mo,bool tight, bool st, bool even){
	if(pos == s.size())
		return mo == 0;

	if(dp[pos][mo][tight][st][even] != -1) 
		return dp[pos][mo][tight][st][even];

	ll ans = 0;
	ll end = (tight?(s[pos]-'0'):9);
	if(st == 0){
		ans = (ans + solve(pos+1,mo,tight&(s[pos]=='0'),st,0))%mod;

		for(ll i = 1; i<=end ; i++){
			if(i != d)
				ans = (ans + solve(pos+1,(mo*10 + i)%m,tight&(i==end),1,1))%mod;
		}
	}
	else{
		for(ll i = 0 ; i<=end ; i++){
			if(even and (i==d))	
				ans = (ans + solve(pos+1,(mo*10 + i)%m,tight&(i==end),1,!even))%mod;
			else if( (!even) and (i!=d))
				ans = (ans + solve(pos+1,(mo*10 + i)%m,tight&(i==end),1,!even))%mod;
		}
	}
	return dp[pos][mo][tight][st][even] = ans;
}

int main(){
	cin>>m>>d;
	cin>>a>>b;
	s = b;
	memset(dp,-1,sizeof dp);
	ll ans = (solve(0,0,1,0,0))%mod;

	s = a;
	memset(dp,-1,sizeof dp);
	ans =  (ans - solve(0,0,1,0,0) + mod)%mod;

	ll mo = 0;
	bool flag = true;	

	for(ll i =0; i < a.size() ; i++){
		if(i%2 and ((a[i]-'0')!=d )){
			flag = false;
			break;
		}
		if(i%2 == 0 and ((a[i] -'0') == d)){
			flag = false;
			break;
		}
		mo = (mo*10+(a[i]-'0'))%m;
	}
	if( mo== 0 and flag) 
		ans = (ans + 1)%mod;

	cout<<ans<<endl;
	return 0;
}