#include <bits/stdc++.h>

using namespace std;

void print_gantt_chart(int bt[],string a[],int tat[], int n);

int main()
{
    int bt[1000],p[100],wt[100],tat[100],i,j,n,total=0,totalwt=0,pos,temp;
    float avg_wt,avg_tat;
    string a[1000],te;
    cout<<"Enter number of process:";
    cin>>n;

    printf("\nEnter Process name and Burst Time:\n");
    for(i=0;i<n;i++)
    {
        //printf("p%d:",i+1);
        cout<<"Process name:";
        cin>>a[i];
        cout<<"Burst Time:";
        cin>>bt[i];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                te=a[i];
                a[i]=a[j];
                a[j]=te;

            }
        }
    }

    wt[0]=0;            //waiting time for first process will be zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        totalwt+=wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\n"<<a[i];
        printf("\t\t  %d\t\t    %d\t\t\t%d",bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //average turnaround time
    cout<<"\nTotal Waiting Time= "<<totalwt<<"\n";
    cout<<"Average Waiting Time="<<avg_wt<<"\n";
    cout<<"Total Turnaround Time = "<<total<<"\n";
    cout<<"Average Turnaround Time="<<avg_tat<<"\n";

    print_gantt_chart(bt,a,tat,n);
    return 0;
}

void print_gantt_chart(int bt[],string a[],int tat[], int n)
{
    int i, j;
    cout<<" ";
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++){
            cout<<"--";
        }
        cout<<" ";
    }
    cout<<"\n|";

    for(i=0; i<n; i++) {
        for(j=0; j<bt[i] - 1; j++){
            cout<<" ";;
        }
        cout<<a[i];
        for(j=0; j<bt[i] - 1; j++){
            cout<<" ";
        }
        cout<<"|";
    }
    cout<<"\n";

    cout<<" ";
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++){
            cout<<"--";
        }
        cout<<" ";
    }
    cout<<"\n";

    cout<<"0";
    for(i=0; i<n; i++) {
        for(j=0;j<(2*bt[i]);j++){
            cout<<" ";
        }
        if(tat[i] > 9){
            cout<<"\b";
        }
        cout<<tat[i];
    }
    cout<<"\n";
}
