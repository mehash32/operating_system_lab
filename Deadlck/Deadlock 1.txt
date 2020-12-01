#include <stdio.h>
#include <stdlib.h>

int p,r;
int *P,*R,*Available;
int **Max_request;
int **Allocated;
int **Need;

void create(){

	int i=0;
	P=(int*)malloc(p*sizeof(int));
	R=(int*)malloc(r*sizeof(int));
	Available=(int*)malloc(r*sizeof(int));
	Max_request=(int**)malloc(p*sizeof(int*));
	Allocated=(int**)malloc(p*sizeof(int*));
	Need=(int**)malloc(p*sizeof(int*));
	for(i=0;i<p;i++)
	{
		Max_request[i]=(int*)malloc(r*sizeof(int));
		Allocated[i]=(int*)malloc(r*sizeof(int));
		Need[i]=(int*)malloc(r*sizeof(int));
	}
}

void Find_Need(){

	int i,j;
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			Need[i][j]=Max_request[i][j] - Allocated[i][j];
		}
	}
	return;
}

int Safe_State(){

	int i,j;
	int found;
	int Finish[p];
	int Work[r];
	int count=0;
	int safe_sequence[p];

	for(i=0;i<p;i++)
		Finish[i]=0;

	for(j=0;j<r;j++)
		Work[j] = Available[j];
  while(1)
  {
  found=0;
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			if(Need[i][j] > Work[j])
				break;
		}

		if(j==r)
		{
			if(Finish[i]==0)
			{
				for(j=0;j<r;j++)
					Work[j] += Allocated[i][j];

				Finish[i]=1;
				found = 1;
				safe_sequence[count]=i;
				count++;
			}
		}
	}

	if(found==0)
	{
		printf("System is not in the safe state\n" );
		return 0;
	}

	if(count==p)
	{
		printf("System is in safe state\nSafe Sequence is:" );
		for(i=0;i<p;i++)
			printf("%d ",safe_sequence[i] );
		printf("\n" );
		return 1;
	}
 }

}

void Request(int pr,int new_request[]) {

	int i,j;
	for(j=0;j<r;j++)
	{
		if(Need[pr][j]<new_request[j])
		{
			printf("Request not Possible\n");
			return;
		}
	}

	for(j=0;j<r;j++)
	{
		if(Available[j]<new_request[j])
		{
			printf("Request not Possible since Resource are not Available\n");
			return;
		}
	}

	for(j=0;j<r;j++)
	{
		Available[j] -= new_request[j];
		Need[pr][j] -= new_request[j];
		Allocated[pr][j] += new_request[j];
	}


	Safe_State();

}

int main(int argc, char const *argv[])
{
	printf("Enter the no of Processes and Resource types\n");
	scanf("%d %d",&p,&r);
	int i,j;

	create();

	printf("Enter the total no instance of Resource types\n");
	for(i=0;i<r;i++)
		scanf("%d",&Available[i]);

  printf("Enter the Maximum requests Processes can make\n");
  for(i=0;i<p;i++)
  {
    printf("Enter for Process-%d:",i );
    for(j=0;j<r;j++)
    		scanf("%d",&Max_request[i][j]);
		printf("\n" );
  }

  printf("Enter the no of Resources Allocated for Processes\n");
  for(i=0;i<p;i++)
  {
    printf("Enter for Process-%d:",i );
    for(j=0;j<r;j++)
    {
    		scanf("%d",&Allocated[i][j]);
    		Available[j] = Available[j] - Allocated[i][j];
    }
		printf("\n" );
  }

  Find_Need();

  Safe_State();

	int new_request[r];
	printf("\nEnter the Process which need Resource\n" );
	scanf("%d",&i);
	printf("Enter the Resource Request\n");
	for(j=0;j<r;j++)
		scanf("%d",&new_request[j]);

	Request(i,new_request);

	return 0;
}