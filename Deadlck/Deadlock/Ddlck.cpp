#include<bits/stdc++.h>
using namespace std;

int avial[20],allocation[20],available[20];
int  i, j, resource, process, k = 1;
int max_resources[20],avail[20],flag[20], current[20][20], max_claim[20][20];
bool state = false;
int main()
{
    printf("Enter number of processes: \n");
    	scanf("%d", &process);
    	printf("\nEnter number of resources : "); 
    	scanf("%d", &resource);
    printf("\nEnter maximum resource vector :"); 
    	for (i = 0; i < resource; i++) 
	{ 
	        scanf("%d", &max_resources[i]);
    	}
   
   

    printf("\nEnter Allocated Resource Matrix for processes:\n");
    	for (i = 0; i < process; i++) 
	{
	        for(j = 0; j < resource; j++) 
		{
  			scanf("%d", &current[i][j]);
        	}
    	}

    printf("\nEnter Request resource Matrix for  processes:\n");
    	for (i = 0; i < process; i++) 
	{
        	for(j = 0; j < resource; j++) 
		{
            		scanf("%d", &max_claim[i][j]);
        	}
    	}
    	//print
    	cout<<"Maximum Resourses Vector is: "<<endl;
	for (i = 0; i < resource; i++) 
	{
	        printf("\t%d", max_resources[i]);
	}
	
	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < process; i++) 
	{
	        for (j = 0; j < resource; j++) 
		{
            		printf("\t%d", current[i][j]);
        	}
		printf("\n");
    	}
    	
    		printf("\nThe Maximum Request Table:\n");
    	for (i = 0; i < process; i++) 
	{
        	for (j = 0; j < resource; j++) 
		{
		        printf("\t%d", max_claim[i][j]);
        	}
        	printf("\n");
    	}
    for (i = 0; i < process; i++) 
	{
        	for (j = 0; j < resource; j++) 
		{
            		allocation[j] += current[i][j];
        	}
    	}
 
    	printf("\nAllocated resource vector:\n");
    	for (i = 0; i < resource; i++) 
	{
        	printf("\t%d", allocation[i]);
    	}
 
    	for (i = 0; i < resource; i++) 
	{
	        available[i] = max_resources[i] - allocation[i];
	        if(available [i]<0)
	        {
	        	available [i]=0;	
			}
	}
 
	printf("\nAvailable resource vector:\n");
    	for (i = 0; i < resource; i++) 
	{
        	printf("\t%d", available[i]);
    	}
    	printf("\n");
    	

    for(int i=0; i<resource; i++)
    {
        for(int j=0; j<process; j++)
        {
            avail[i] += current[j][i];
        }

    }
    for(int i=0;i<resource;i++)
    {
    
        avail[i] = max_resources[i] - avail[i];
        if(avail[i]<0)
            avail[i]=0;  
    	
	}

  
    for(int m=0;m<process;m++)
    {
    	for(int n=0;n<resource;n++)
    	{
		
        	for(int i=0; i<process; i++)
        	{
            	if(flag[i] == 0)
            	{
                	int j;
                	for(j=0; j<resource ; j++)
                	{
                    	if(max_claim[i][j] <= avail[j])
                        	continue;
                    	else
                        	break;
                	}
                	if(j==resource)
                	{
                    	for(int k=0; k<resource; k++)
                    	{
                        	avail[k] += current[i][k];
                    	}
                    	flag[i] = 1;
                	}
            	}
        	}
    	}
    }

    printf("\n");
    
    for(int i=0; i<process; i++)
    {
        if(flag[i] == 0)
        {
            state = true;
            break;
        }
    }

    if(state)
    {
    	cout<<" The below processes are in deadlock : "<<endl;
        for(int i=0; i<process; i++)
        {
            if(flag[i] == 0)
                cout<<"process "<<i+1<<" "<<endl;
        }
        cout<<"_____________________________________________"<<endl;
        
    }
    else
        cout<<"All processes are safe: \n NO! Deadlock"<<endl;
}

