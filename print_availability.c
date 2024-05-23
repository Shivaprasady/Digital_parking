#include"digital_parking.h"
int print_availability()
{
	printf("      AVAILABLE SLOTS     \n");

	FILE *fptr = fopen("availability.txt","r");
	if(fptr == NULL)
	{
		printf("Error : problem in opening availability.txt file\n");
		return FAILURE;
	}

	for(int i = 1 ; i <= 20 ; i++)
	{
		int availabity;
		availabity = fgetc(fptr);
		printf("A%d - ",i);
		if(availabity == '0')
			printf("\033[32m%c\033[37m\t",'A');
		else if(availabity == '1')
			printf("\033[31m%c\033[37m\t",'F');

		if(i % 5 == 0)
			printf("\n");
	}

	fclose(fptr);
	return SUCCESS;
}

int available_slot()
{
	FILE *fptr = fopen("availability.txt","r+");
	if(fptr == NULL)
	{
		printf("Error : problem in opening availability.txt file\n");
		return FAILURE;
	}

	int i;
	for(i = 0 ; i <= 20 ; i++)
	{
		if(fgetc(fptr) == '0')
		{
			printf("A%d is available to park\n",(i+1));
			break;
		}
	}

	char accept;
	printf("Would you like to park? (y/n):\n");
	getc(stdin);
	scanf("%c",&accept);

	if(accept == 'y')
	{
		fseek(fptr,i,SEEK_SET);
		fputc('1',fptr);
		fclose(fptr);
		print_availability();
	}
	else
	{
		printf("Thank You for visiting\n.");
	}


	return SUCCESS;
}

int exit_slot()
{
	int slot;
	printf("Enter the slot : ");
	getc(stdin);
	scanf("%d",&slot);

	FILE *fptr = fopen("availability.txt","r+");
	if(fptr == NULL)
	{
		printf("Error : problem in opening availability.txt file\n");
		return FAILURE;
	}

	fseek(fptr,(slot-1),SEEK_SET);
	fputc('0',fptr);

	fclose(fptr);

	printf("Thank You\nVisit again\n.");
}
