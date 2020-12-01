#include<iostream>

using namespace std;

void print_gantt_chart(int bt[],string a[],int tat[], int n);

int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,totalwt=0,pos,temp;
    string a[1000],te;
    double avg_wt,avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;

    cout<<"\nEnter Process name, Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        //cout<<"\nP["<<i+1<<"]\n";
        cout<<"Process name:";
        cin>>a[i];
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
        cin>>pr[i];
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j]){
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                te=a[i];
                a[i]=a[j];
                a[j]=te;
            }
        }
    }

    wt[0]=0;            //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        totalwt+=wt[i];
    }

    avg_wt=totalwt/(n*1.0);      //average waiting time
    //total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\n"<<a[i]<<"\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }

    avg_tat=total/(n*1.0);     //average turnaround time
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


/*#include <iostream>

using namespace std;

int main()
{

    //int pr[3]={3,2,9},i,j,temp,pos;
    /*for(i=0;i<3;i++){pos=i;
        for(j=i+1;j<3;j++){
            if(pr[j]<pr[pos]){
                pos=j;
            }
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
    }*/
   /* for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            if(pr[i]>pr[j]){
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
            }
        }
    }*/

    //return 0;
//}*/
