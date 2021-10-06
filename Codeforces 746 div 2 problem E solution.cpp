#include<bits/stdc++.h>
using namespace std;
#define endl "\n" /*for interactive problems remove this line*/
/*
-for ordered set problems policy based data sucture header
//PBDS

*/ 

typedef  long long  ll;
ll mod = pow(10, 9) + 7;
typedef unsigned long long  ull;
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
  int x, y; // used in extended GCD algorithm
  int g = gcdExtended(b, m, &x, &y);
 
  // Return -1 if b and m are not co-prime
  if (g != 1)
    return -1;
 
  // m is added to handle negative x
  return (x % m + m) % m;
}
int gcdExtended(int a, int b, int *x, int *y)
{
  // Base Case
  if (a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }
 
  int x1, y1; // To store results of recursive call
  int gcd = gcdExtended(b % a, a, &x1, &y1);
 
  // Update x and y using results of recursive
  // call
  *x = y1 - (b / a) * x1;
  *y = x1;
 
  return gcd;
}
 
ll sumbincoef( int N, int k ) {
  ll   bincoef = 1, sum = 1;
  int i;
  for ( i = 1 ; i < k ; i++ ) {
    ll val=((N - i + 1)%mod *modInverse( i,mod))%mod;
    bincoef = (bincoef%mod * val)%mod;
    if(i%2==0)
    sum = (sum+bincoef)%mod;
  }
  return sum%mod;
}
 
const int N = 200000 + 10;
ll factorialNumInverse[N + 1];
 
// aay to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// aay to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
  // precompute inverse of natural numbers
  for (int i = 2; i <= N; i++)
    factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
  fact[0] = 1;
 
  // precompute factorials
  for (int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
  // n C r = n!*inverse(r!)*inverse((n-r)!)
  ll ans = ((fact[N] * factorialNumInverse[R])
            % p * factorialNumInverse[N - R])
           % p;
  return ans;
}
 
 
 
typedef unsigned long long  ull;
 
typedef unsigned int ui;
/*IMP snippets
 //PBDS -for ordered set problems policy based data sucture header
//binaryToDecimal
//decimalToBinary
//nCrModp
 
//is_prime
 
//segtree*/
  
int parent[N],ran[N];
void make_set(int v) {
    parent[v] = v;
    ran[v]=0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
      if(ran[a]<ran[b])swap(a,b);
      parent[b] = a;
      if(ran[a]==ran[b])ran[a]++;
    }
  }

  

int main()
{ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  ll p=mod;
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);
 
 ll power[21];
 power[0]=1;
 for(int i=1;i<21;i++)
 {
  power[i]=power[i-1]*2;
 }


 int t=1;
 //cin>>t;
 while(t>0)
 { 
    int n;
    cin>>n;
    vector <int> a(n);
     
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      
    }
    if(n==1)
    {
      cout<<0<<endl;
      return 0;
    }
   
   
    
     
    vector <int> pre=a;
   
    for(int i=1;i<n;i++)
    {
      pre[i]^=pre[i-1];

    }

   
   
    
  
    
  
   
    int ans=0;
    
    

    
     int it=0;
     
     while(it<21)
     {
       
     int cnt=0;
     if(a[0]&power[it])
     {
       cnt++;
     }
     int l=-1;

     unordered_map<int,int> mapa,mapb; // mapa for 0 parity and mapb for 1
      mapb[0]=-1+2;
      mapa[pre[0]]=0+2;
     for(int i=1;i<n;i++)
     {  
       if(a[i]&power[it])
       {
         cnt++;
       }
       else
       {
        cnt=0;
        mapa.clear();
        mapb.clear();
        if(i%2)
        mapb[pre[i]]=i+2;
         else
         {
          mapa[pre[i]]=i+2;
         }
        continue;
       }
       if(i%2==0)
       { 
        if(mapa[pre[i]]==0)
        {
          mapa[pre[i]]=i+2;
        }
        
       }
       else
       {
        if(mapb[pre[i]]==0)
        {
          mapb[pre[i]]=i+2;
        }
       }
      if(cnt%2==0)
         { int no=cnt;
            int l;
            if(i%2==0)
            {
              l=mapa[pre[i]];
            }
            else
            {
              l=mapb[pre[i]];
            }
          ans=max(ans,i-l+2);
           


         }
         else if(cnt%2==1&&cnt>=3)
         {
          int no=cnt-1;
           int l;
            if(i%2==0)
            {
              l=mapa[pre[i]];
            }
            else
            {
              l=mapb[pre[i]];
            }
          ans=max(ans,i-l+2);



         }
       


     }
     for(int i=0;i<n;i++)
    { if(pre[i]&power[it])
      pre[i]^=power[it];

    }
     

     





      
      it++;
     }
    


    
   
   cout<<ans<<endl;
    
    
    

  

  t--;
 }  
   




}