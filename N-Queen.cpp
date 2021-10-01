//Solution of the famous N-queen problem

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int,int>pi;
typedef vector<vector<int>>vii;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

bool safe(int row,int col,vii &board){
    rep(i,0,col){
        if(board[row][i]==1){
            return false;
        }
    }

    for(int i=row,j=col;i>=0 and j>=0;i--,j--){
        if(board[i][j]==1)return false;
    }

    for(int i=row,j=col;i<=board.size() and j>=0;i++,j--){
        if(board[i][j]==1)return false;
    }
    return true;
}
bool solve(int col,int n,vii &board,vii &res){
   if(col==n){
       vi v;
       rep(i,0,n)
       rep(j,0,n){
           if(board[i][j]){
               v.push_back(j+1);
           }
       }
       res.push_back(v);
       return true;
   }

   rep(row,0,n)
     if(safe(row,col,board)){
         board[row][col]=1;
         solve(col+1,n,board,res);
         board[row][col]=0;
     }
     return false;
}

vii nqueen(int n){
    vii board(n,vi(n,0));
    vii res;
    solve(0,n,board,res);
    sort(res.begin(),res.end());
    return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>>n;

    vector<vector<int>>ans;
    ans=nqueen(n);
    if(ans.size()==0){
        cout<<-1<<endl;
    }

    else{
        rep(i,0,ans.size()){
            cout<<"[";
            for(auto it: ans[i]){
                cout<<it<<" ";
            }
            cout<<"]";
        }
        cout<<endl;
    }
    return 0;
}
