#include<stdio.h>
#include<conio.h>

int arr1[6],arr2[6],time=0;

void initial()
{
	int i;
	clrscr();
	for(i=0;i<6;i++)
	{
		arr1[i]=rand()%10;
		arr2[i]=arr1[i];
	}

}

void shuffle()
{
	int i,j,flag=0;
	time++;
	for(i=0;i<6;i++)
	{
		while(arr1[i]==arr2[i])
		{
			arr1[i]=rand()%10;
		}
		while(arr1[i]==0)
		{
			arr1[i]=rand()%10;
		}
	}
	for(i=0;i<6;i++)
	{
		arr2[i]=arr1[i];
	}
	for(i=0;i<3;i++)
	{
		for(j=5;j>2;j--)
		{
			if(arr1[i]==arr1[j])
			{
				flag++;
			}
		}
	}
	if(flag==0)
	{
		time--;
		shuffle();
	}
}

int cards(int a,int b)
{
	if(arr1[a-1]==arr1[b-1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int c1, c2, check=2, i;
	char ans='y';
	while(ans=='y')
	{
		if(time==0)
		{
			initial();
		}
		clrscr();
		printf("\n\nChoose two cards from below :-");
		printf("\n\n1) Card 1 \t2) Card 2 \t3) Card 3");
		printf("\n\n4) Card 4 \t5) Card 5 \t6) Card 6");
		printf("\n\nFirst card : ");
		scanf("%d",&c1);
		printf("\nSecond card : ");
		scanf("%d",&c2);
		if(c1>6 || c2>6)
		{
			clrscr();
			printf("\n\nERROR\n\nOut of scope. Press any key to exit");
			getch();
			exit(0);
		}
		check = cards(c1, c2);
		if(check==1)
		{
			printf("\n\nCongratulations!!!");
			printf("\nYou have the same cards, you won!");
			printf("\n\nTotal number of shuffles done : %d",time);
			ans='n';
		}
		else if(check==0)
		{
			printf("\n\nSorry, cards are not same.");
			printf("\n\nPress any key to shuffle again");
			getch();
			shuffle();
		}
		else
		{
			clrscr();
			printf("\n\nERROR\n\nPress any key to exit");
		}
		getch();
	}
	return 0;
	getch();
}
