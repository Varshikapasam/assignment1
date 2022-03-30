#include<stdio.h>
#include<string.h>

#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{	
	char tmpchr[10];
	int year;
	printf("Please enter a year (example: 1999) : ");
	fgets(tmpchr,9,stdin);
	if (sscanf(tmpchr,"%d",&year)==1){
		return year;
	}
	if(sscanf(tmpchr,"%d",&year)!=1){
		system("cls");
		printf("Invalid input please enter any numeric value");
		sleep(3);
		return -1;
	}
	
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

int main(void)
{
	int year, daycode, leapyear,end;
	while(1){
	system("cls");
	year = inputyear();
	if (year<0){
		continue;
	}
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\nPress 1 to end this session anyother number to continue\n");
	scanf("%d",&end);
	if(end == 1){
		printf("Thank you see again");
		break;
	}
	
	printf("\n");
	}
}
