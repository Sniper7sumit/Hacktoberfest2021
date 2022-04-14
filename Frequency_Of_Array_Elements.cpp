#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array : "<<endl;
    cin>>n;
  
    //Array input 
  
    cout << "\nEnter the array elements : " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin >> arr[i]; 
    }

    //printing given array
  
    cout << "\nYour Array : " << endl;
    for (int i = 0; i < n; i++)
    {
       cout << arr[i]<<"  "; 
    }
   
    int f[n];
    int visited = -11;    
    
    //counting the array elements and marking the visited elements
  
    for(int i = 0; i < n; i++){    
        int count = 1;    
        for(int j = i+1; j < n ; j++){    
             if(arr[i] == arr[j]){    
                count++;    
                f[j] = visited;    
              }    
              }    

        if(f[i] != visited)    
           f[i] = count;    

    }    
  
  
    // Printing the frequency table
  
    printf("\n\n\nFrequency Table :\n\n--------------------------\n");    
    printf(" Element    |    Frequency\n");    
    printf("--------------------------\n");    
    for(int i = 0; i < n ; i++){    
        if(f[i] != visited){    
            printf("     %d", arr[i]);    
            printf("      |    ");    
            printf("  %d\n", f[i]);    
        }    
    }    
    printf("--------------------------\n");
    return 0;
}
