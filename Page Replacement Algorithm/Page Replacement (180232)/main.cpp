#include<bits/stdc++.h>
///Mehedi Hasan Shanto
///180232
using namespace std;

int present(int table_frame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
		if(page == table_frame[i])
			return 1;
	return 0;
}

void printtable(int table_frame[], int nf)
{
	for(int i=0; i<nf; i++)
	{
		if(table_frame[i] == -1)
			printf("-- ");
		else
			printf("%2d ", table_frame[i]);
	}
	printf("||");
}


///for Second chance algo
int present1(int a[],int nf,int page,int rf_bit[])
{
    for(int i=0;i<nf;i++)
    {
        if(a[i]==page)
        {
          rf_bit[i]=1;
          return 1;
        }

    }
    return 0;
}

//for LRU
int findpos(int table_frame[], int nf, int pages[], int curr, int np)
{
	for(int i=0; i<nf; i++)
		if(table_frame[i] == -1)
			return i;

	int pos[nf] = {0};
	for(int i=0; i<nf; i++)
	{
		pos[i] = -1e9;
		for(int j=curr-1; j>=0; j--)    //checking or element in array backward of current position
			if(pages[j] == table_frame[i])
			{
				pos[i] = j;
				break;
			}
	}

	int min1 = 1000000, retPos = -1;
	for(int i=0; i<nf; i++)
		if(min1 > pos[i])
		{
			min1 = pos[i];
			retPos = i;
		}

	return retPos;
}
///for Optimal 
int findpos1(int table_frame[],int nf,int pages[],int curr,int np)
{
    int i,j;
    for(i=0;i<nf;i++)
    {
        if(table_frame[i] == -1)
            return i;
    }

    int pos[nf]={0};
    for(i=0;i<nf;i++)  //checking for elememt in array after current posintion
    {
        pos[i]=1e9;
        for(j=curr+1;j<np;j++)
        {
            if(pages[j]==table_frame[i])
            {
                pos[i]=j;
                break;
            }
        }
    }

    int max1=-1;
    int returnpos=-1;
    for(i=0;i<nf;i++)
    {
        if(pos[i]>max1)
        {
            max1=pos[i];
            returnpos=i;
        }
    }

    return returnpos;
}
///FIFO page replacement

void fifo()
{
    //nf-number of frames
    cout<<"\n\t\t Fifo Page Replacement Algorithm\n\n";
    int n,nf,i,pos=0;

    printf("enter number of frames\n");
    scanf("%d",&nf);
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }

    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter reference string\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]);
        if(!present(table_frame,nf,pages[i]))
        {
           table_frame[pos] = pages[i];
           pos = (pos+1)%nf ;//considering it as a queue
           printtable(table_frame,nf);
           printf("page fault\n");
           count1++;
           continue;
        }

        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1);
}

///OPTIMAL page replacement

void optimal()
{
    //nf-number of frames
    cout<<"\n\t\t Optimal Page Replacement Algorithm\n\n";
    int n,nf,i,pos=0;

    printf("enter number of frames\n");
    scanf("%d",&nf);
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }

    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter page refference\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]);
        if(!present(table_frame,nf,pages[i]))
        {
             int pos = findpos1(table_frame,nf,pages,i,n);
             table_frame[pos]=pages[i];

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1);
}

///Least Recently Used page replacement
void lru()
{
    //nf-number of frames
    cout<<"\n\t\t Least Recently Used Page Replacement Algorithm\n\n";
    int n,nf,i,pos=0;

    printf("enter number of frames\n");
    scanf("%d",&nf);
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }

    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter pages refferences\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]);
        if(!present(table_frame,nf,pages[i]))
        {
             int pos = findpos(table_frame,nf,pages,i,n);
             table_frame[pos]=pages[i];

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1);
}

///Second chance page replacement
void second_chance()
{
    cout<<"\n\t\t Second Chance Page Replacement Algorithm\n\n";
	int nf;
    cout<<"enter number of frames"<<endl;
    cin>>nf;
    int a[nf],rf_bit[nf];
    for(int i=0;i<nf;i++)
    {
        a[i]=-1;
        rf_bit[i]=0;
    }

    int np;
    cout<<"enter total number of page requests\n"<<endl;
    cin>>np;
    int b[np];
    
     /*
     int n;
	 printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    */
    
    
    cout<<"enter reference string\n"<<endl;
    for(int i=0;i<np;i++)
    {
        cin>>b[i];
    }
    int pos=0,count1=0;
	cout<<"position of frame table after each request\n";
    for(int i=0;i<np;i++)
    {
        printf("page table after request from %2d || ",b[i]);
        if(!present1(a,nf,b[i],rf_bit))
        {
            //int pos=findpos(a,nf,b,i,np);
            pos=(pos+1)%nf;
            while(rf_bit[pos]==1)
            {
                rf_bit[pos]=0;
                pos=(pos+1)%nf;
                
            }

            a[pos]=b[i];
            printtable(a,nf);
            printf("page fault\n");
            count1++;
            continue;
        }

        printtable(a,nf);
		printf("\n");
    }

     printf("\nNumber of page faults : %d\n\n", count1);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nPage Replacement Algorithms\n1.FIFO\n2.Optimal\n3.LRU\n4.Second Chance\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        
        case 1:
            fifo();
            break;
        case 2:
            optimal();
            break;
        case 3:
            lru();
            break;
       
        case 4:
            second_chance();
            break;
        default:
            return 0;
            break;
        }
    }
}

		
