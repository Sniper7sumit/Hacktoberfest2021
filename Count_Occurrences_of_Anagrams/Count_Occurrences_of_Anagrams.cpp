
#include <bits/stdc++.h>

using namespace std;

int search(string pat, string txt) {
	int index;
	int count =0;
	int len = pat.length();
	int size = txt.length();
	int pattern[26];
	int txt_count[26];
	bool flag = true;
	for(int i = 0; i<26;i++){
		pattern[i]=0;
		txt_count[i] = 0;
	}
	for(int i = 0;i<len;i++){
		index = pat[i]-'a';
		pattern[index]++;
	}
	for(int i = 0;i<len;i++){
		index = txt[i]-'a';
		txt_count[index]++;
		
	}
	
	for(int j = 0; j<26;j++){
			if(txt_count[j] != pattern[j]){
				flag = false;
				break;
			}
		}
	if(flag==true){
		count++;
	}
	for(int i = len;i<size;i++){
		flag = true;
		index = txt[i-len]-'a';
		txt_count[index]--;
		index = txt[i]-'a';
		txt_count[index]++;
		for(int j = 0; j<26;j++){
			if(txt_count[j] != pattern[j]){
				flag = false;
				break;
			}
		}
		if(flag==true){
			count++;
		}
		
	}
	return count;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        int ans = search(pat, txt);
        cout << ans << "\n";
    }
    return 0;