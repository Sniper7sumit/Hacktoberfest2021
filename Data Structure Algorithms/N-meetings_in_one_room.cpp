/*
*******ALGORITHEM********

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do following for remaining activities in the sorted array. 
.......a) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.
In the following C implementation, it is assumed that the activities are already sorted according to their finish time.
*/


/*
N meetings in one room

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation:
Four meetings can be held with
given start and end timings.

Example 2:

Input:
N = 8
S[] = {75250, 50074, 43659, 8931, 11273,
27545, 50879, 77924}
F[] = {112960, 114515, 81825, 93424, 54316,
35533, 73383, 160252}
Output: 
3
Explanation:
Only three meetings can be held
with given start and end timings.
 */


#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends


static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n) {
    
    vector<pair<int,int>> meetingPair;
    for(int i=0; i<n; i++){
        meetingPair.push_back(make_pair(start[i], end[i]));
    }
    
    sort(meetingPair.begin(), meetingPair.end(), cmp);
    
    
 //   cout<<meetingPair[0].first<<", "<<meetingPair[0].second<<"\t";
    int i=0;
    int count =1;
    for(int j=1; j<n; j++){
        if(meetingPair[j].first > meetingPair[i].second){
         //   cout<<meetingPair[j].first<<", "<<meetingPair[j].second<<"\t";
            count ++;
            i=j;
        }
    }
   // cout<<endl;
    return count;
}