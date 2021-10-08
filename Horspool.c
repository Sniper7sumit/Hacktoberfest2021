//Input : String and pattern
//Output: Position of match if pattern is present else print not found

#include<stdio.h>
#include<string.h>

//making Shift Table
void genShiftTable(char pattern[],int Table[]){
	for(int i=0;i<256;i++)
		Table[i]=strlen(pattern);

	for(int i=0;i<strlen(pattern)-1;i++){
		Table[pattern[i]]=strlen(pattern)-i-1;
	}
}

//searching with Horspool Algorithm
int searchHorspool(char* string,char* pattern,int Table[256]){
	int n=strlen(string);
	int m=strlen(pattern);

	//assigning pattern length to i
	for(int i=m-1;i<n;){
		int j=0;

		//matching till the pattern is matching with string
		while(j<m && pattern[m-1-j]==string[i-j])
			j++;

		//if pattern is totally matched
		if(j==m)
			return i-m+1;

		//increase i according to shift Table
		i+=Table[string[i]];
	}
	return -1;
}

int main(){
	int shiftTable[256];
	char string[23];
	gets(string);
	char pattern[20];
	gets(pattern);

	printf("%s %s\n",string,pattern);

	genShiftTable(pattern,shiftTable);
	int found=searchHorspool(string,pattern,shiftTable);

	if(found==-1)
		printf("Sorry pattern not found");
	else
		printf("Pattern is found at %d position\n",found+1);
	return 0;
}
