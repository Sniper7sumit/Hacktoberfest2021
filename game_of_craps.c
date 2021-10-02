#include <stdio.h>
#include <stdlib.h>
int main()
{	
  int dice1, dice2, sum, point;
	int win = 0, lose = 0;
	for(int i = 1 ; i <= 1000 ; ++i)
	{	START :	//label
		dice1 = 1 + rand() % 6;
		dice2 = 1 + rand() % 6;
		sum = dice1 + dice2;	//sum of the faces of dices
		printf("%d " ,sum);
		if((sum == 7) || (sum == 11)|| (sum == point))
		{	win++ ;
			puts("WINS");
		}
		else if((sum == 2)|| (sum == 3)|| (sum == 12)|| (sum == 7))
		{	lose++ ;
			puts("LOSES");
		}
		else	//if sum is equal to 4,5,6,8,9,10
		{
			point = sum;
			goto START;
		}
		
	}
	printf("total wins = %d \n total failure = %d \n" ,win ,lose); 
		
	return 0;
}
