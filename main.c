/*Name : Shiva prasad 
Date :
Description : 
Sample input : 
Sample output : 
*/
#include<stdio.h>
#include"digital_parking.h"
int main()
{
	printf("--------------------------\n");
	printf("WELCOME TO DIGITAL PARKING\n");
	
	if(print_availability() == SUCCESS)
	{ 
		char choice;
		printf("1.Entry\n2.Exit\n");
		scanf("%c",&choice);
		if(choice == '1')
		{
			available_slot();
		}
		else if(choice == '2')
		{
			exit_slot();
		}
	}


}

