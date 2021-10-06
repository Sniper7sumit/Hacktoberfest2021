#include<iostream>
#include<algorithm>
using namespace std;

struct Job 
	{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
	}; 

	bool comp ( struct Job a , Job b){
    if(a.profit > b.profit) return true; 
    else return false; 
  		}

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n , comp);
        
        int maxD = arr[0].dead; 
        for(int i = 1 ; i < n ; i++){
            maxD = max( maxD , arr[i].dead); 
        }
        int count = 0 ; 
        int ans = 0 ; 
        int tmp[maxD+1]; 
        for(int i = 1; i <= maxD ; i++){
            tmp[i]=-1;
        }
        for( int i = 0 ; i < n ; i++){
            for( int j = arr[i].dead ; j > 0 ; j--){
                if(tmp[j]==-1){
                    tmp[j]=i; 
                    ans++; 
                    count+= arr[i].profit; 
                    break;
                }
            }
        }
        
        vector<int> res; 
        res.push_back(ans); 
        res.push_back(count); 
        
        return res;
        
    } 

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
    
    JobScheduling(arr, n);
    return 0;
}