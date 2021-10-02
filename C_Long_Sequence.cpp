#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdlib>
#include<sstream>
#include <string.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define ll  long long
#define ld  long double
#define endl "\n"
 
const ll mod=1e9+7;
void solve()
{
ll n;
	cin>>n;
	vector<ll> A(n);
	for(auto &x:A)cin>>x;
	ll y;
	cin>>y;
	
	ll s = accumulate(A.begin(),A.end(),0);
	ll set = y/s;
	ll os = set*s;
	ll ans = set*n;
	for(auto i=0;i<n;i++){
		if(os>=y){
			break;
			}
		else{
			os+=A[i];
			ans++;
			}
		}
	if(os==y)ans++;
	cout<<ans <<"\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin. tie(0);cout. tie(0);
ll t=1;
//cin>>t;
while(t--)
{
solve();
}
return 0;
}