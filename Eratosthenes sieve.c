/* This finds primes within a range using Sieve of Eratosthenes*/
#include<stdio.h>
void sieve(int *arr,int size,int value)
{
	int iloop,first=0;
	for(iloop=0;iloop<size;iloop++)
	{
		if(arr[iloop]!=0)//Checking if array value is already deleted
		{
			if(arr[iloop]%value==0)//Checking if array value is divisible by value sent from main (VFM)
			{
				if(first==0)//If it is the first occurence of VFM, do nothing
				first=1;
				else if(first==1)//If it is multiple of VFM, delete it
				arr[iloop]=0;
			}
		}
	}
}
void display(int *arr,int size)
{
	int iloop;
	printf("\nPrimes upto the given range are:\n");
	for(iloop=1;iloop<size;iloop++)
	{
		if(arr[iloop]!=0)
		printf("%d,",arr[iloop]);
		else
		continue;
	}
}
int main()
{
	int input,iloop;
	printf("Enter upper bound of range upto which you want to find primes:\t");
	scanf("%d",&input);//Entering upper bound of range
	int iArr[input];
	for(iloop=0;iloop<input;iloop++)
	iArr[iloop]=iloop+1;//Creating array with consecutive values upto input
	for(iloop=2;iloop<=input/2;iloop++)
	{
		sieve(iArr,input,iloop);
	}
	display(iArr,input);//Displaying primes upto input
}
