#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for(i = 1; i < n; ++i)
    {
        if(time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}


void second_chance()
{
  int i,pn,pt[1000]={0},fn;
  printf("\nEnter no of pages : ");
  scanf("%d",&pn);
  printf("\n Enter the request   : ");
  for(i=0;i<pn;i++)
  {
    scanf("%d",&pt[i]);
  }

  printf("\nEnter the no of frames : ");
  scanf("%d",&fn);
  int fr[fn],ch[fn];
  for(i=0;i<fn;i++)
  {fr[i]=-1; ch[i]=0; }

  int j,flag,ctr=0,hit=0,miss=0;
  for(i=0;i<pn;i++)
  {
    printf("request:  %d \t\n",pt[i]);
    printf("\n");
    
    flag=0;
    for(j=0;j<fn;j++)
    {
      if(fr[j]==pt[i])
      { ch[j]=1;
        flag=1;
        break;
      }
    }

    if(flag==0)
    { miss++;

      if(ch[ctr]==0)
      fr[ctr]=pt[i];
      else
      {   for(;ch[ctr]==1;ctr=(ctr+1)%fn)
          ch[ctr]=0;

          fr[ctr]=pt[i];

      }
      ctr=(ctr+1)%fn;
      for(j=0;j<fn;j++)
      {
        printf("\t %d \n",fr[j]);
      }
      printf("--------------------\n");
      
    }
    else
    hit++;

    printf("\n");
  }

//  printf("\n Number of hits : %d",hit);
  printf("\n Page fault : %d",miss);
 
}


















void lru()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames in Main Memory: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages in Secondary Memory: ");
    scanf("%d", &no_of_pages);

    printf("Enter the sequence in which pages will be requested: ");

    for(i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for(j = 0; j < no_of_frames; ++j)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0)
        {
            for(j = 0; j < no_of_frames; ++j)
            {
                if(frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d \n", faults);

    
}

void optimal()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames in Main Memory: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages in Secondary Memory: ");
    scanf("%d", &no_of_pages);

    printf("Enter the sequence in which pages will be requested: ");

    for(i = 0; i < no_of_pages; ++i)
	{
        	scanf("%d", &pages[i]);
    }

    for(i = 0; i < no_of_frames; ++i)
	{
        	frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i)
	{
        	flag1 = flag2 = 0;

        	for(j = 0; j < no_of_frames; ++j)
            {
	            if(frames[j] == pages[i])
                    {
        	           flag1 = flag2 = 1;
	                   break;
                    }
	        }

	        if(flag1 == 0)
            {
	            for(j = 0; j < no_of_frames; ++j)
                {
	                if(frames[j] == -1)
                    {
	                	    faults++;
        	            	frames[j] = pages[i];
        	            	flag2 = 1;
        	            	break;
                    }
                }
        	}

	        if(flag2 == 0)
            {
            	flag3 =0;

            for(j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for(k = i + 1; k < no_of_pages; ++k)
                {
                    if(frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for(j = 0; j < no_of_frames; ++j)
            {
                if(temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if(flag3 ==0)
            {
                max = temp[0];
                pos = 0;

                for(j = 1; j < no_of_frames; ++j)
                {
                    if(temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for(j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

  

}
void fifo()
{

int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("\n Enter the number of pages in Secondary Memory:\n");
scanf("%d",&n);
            printf("\n Enter the number of frames in Main Memory :");
            scanf("%d",&no);
            printf("\n Enter the sequence in which pages will be requested :\n");
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

    for(i=0;i<no;i++)
            frame[i]= -1;
                        j=0;
                        printf("\tref string\t page frames\n");
for(i=1;i<=n;i++)
                        {
                                    printf("%d\t\t",a[i]);
                                    avail=0;
                                    for(k=0;k<no;k++)
if(frame[k]==a[i])
                                                avail=1;
                                    if (avail==0)
                                    {
                                                frame[j]=a[i];
                                                j=(j+1)%no;
                                                count++;
                                                for(k=0;k<no;k++)
                                                printf("%d\t",frame[k]);
}
                                    printf("\n");
}
                        printf("Page Fault Is %d",count);
                      
}


int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		fifo();
	}
	else if (n==2)
	{
		optimal();
	}
	else if(n==3)
	{
		lru();
	}
	else if(n==4)
	{
		second_chance();
	}
}
