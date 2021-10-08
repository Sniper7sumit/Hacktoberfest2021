#include<bits/stdc++.h>
using namespace std;
#define dnd ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define ll long long int
#define readarr(A,N) ll A[N]; for(ll i=0;i<N;i++) {cin>>A[i];}
#define start ll t;	cin>>t;	while(t--)
 
int main(){
    dnd
    
ll even = 0 , odd = 0 , ans = 0 ;
ll n ; 
cin >> n  ;
int arr[n] ; 
for(int i = 0 ; i < n ; i++){
	cin >> arr[i] ;
 
}
for(int i = 0 ; i < n  ; i ++) {
	if(arr[i]%2==0) {
		even++ ; 
	}else {
		odd++ ; 
	}
}
if(odd > even) {
	for(int i = 0 ; i <  n ; i++ ) {
		if(arr[i]%2==0){
			ans =  i ;
			
		}
	}
}else {
	for(int i = 0 ; i < n ; i++){
		if(arr[i]%2!=0) {
			ans = i  ;
		}
	}
} 
cout << ans+1 << endl;
return 0;
}
