
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array : "<<endl;
    cin>>n;
    cout << "\nEnter the array elements : " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin >> arr[i]; 
    }

    cout << "\nYour Array : " << endl;
    for (int i = 0; i < n; i++)
    {
       cout << arr[i]<<"  "; 
    }
   
    int fr[n];
    int visited = -11;    

    for(int i = 0; i < n; i++){    
        int count = 1;    
        for(int j = i+1; j < n ; j++){    
             if(arr[i] == arr[j]){    
                count++;    
                fr[j] = visited;    
              }    
              }    

        if(fr[i] != visited)    
           fr[i] = count;    

    }    

    printf("\n\n\nFrequency Table :\n\n--------------------------\n");    
    printf(" Element    |    Frequency\n");    
    printf("--------------------------\n");    
    for(int i = 0; i < n ; i++){    
        if(fr[i] != visited){    
            printf("     %d", arr[i]);    
            printf("      |    ");    
            printf("  %d\n", fr[i]);    
        }    
    }    
    printf("--------------------------\n");
    return 0;
}
