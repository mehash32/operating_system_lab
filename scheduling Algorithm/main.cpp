#include <iostream>

using namespace std;
void FCFS();
void SJF();
void priority();
void Round_robin();

int main()
{int a;
 cout<< "for FCFS press 1"<<endl;
 cout<< "for sjf press 2"<<endl;
 cout<<"for priority press 3"<<endl;
 cout<<" for round robin press 4"<<endl;
 cin>>a;
 if (a==1){
    FCFS();
 }
 else if (a==2)
 {
     SJF();
 }
 else if(a==3)
 {
     priority();
 }
 else if(a==4)
 {
     Round_robin();
 }
 return 0;
}

void FCFS()
{
    struct Process
{
    int pid,arrival_time,burst_time,waiting_time,turnaround_time;
    string pn;
};

//void print_table(struct Process p[], int n);
//void print_gantt_chart(struct Process p[], int n);
void print_table(struct Process p[], int n)
{
    int i;
    cout<<"+-----+------------+--------------+-----------------+\n";
    cout<<"| PN  | Burst Time | Waiting Time | Turnaround Time |\n";
    cout<<"+-----+------------+--------------+-----------------+\n";
    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               ,p[i].pid,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
        printf("+-----+------------+--------------+-----------------+\n");
    }

}

void print_gantt_chart(struct Process p[], int n)
{
    int i, j;
    cout<<" ";
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++){
            cout<<"--";
        }
        cout<<" ";
    }
    cout<<"\n|";

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++){
            cout<<" ";;
        }
        cout<<p[i].pn;
        for(j=0; j<p[i].burst_time - 1; j++){
            cout<<" ";
        }
        cout<<"|";
    }
    cout<<"\n";

    cout<<" ";
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++){
            cout<<"--";
        }
        cout<<" ";
    }
    cout<<"\n";

    cout<<"0";
    for(i=0; i<n; i++) {
        for(j=0;j<(2*p[i].burst_time);j++){
            cout<<" ";
        }
        if(p[i].turnaround_time > 9){
            cout<<"\b";
        }
        cout<<p[i].turnaround_time;

    }
    cout<<"\n";
}
int main()
{
    int i,j,n,sum_waiting_time=0,sum_turnaround_time=0;
    double nn, aw,att;
    cout<<"Enter total number of process: ";
    cin>>n;
    nn=n;
    struct Process p[n];
    cout<<"Enter process name and burst time for each process:\n";
    for(i=0; i<n; i++) {
        p[i].pid = i+1;

        cin>>p[i].pn;
        cout<<"for process "<<p[i].pn<<"\n";

        cin>>p[i].burst_time;
        p[i].waiting_time = p[i].turnaround_time = 0;
    }
    p[0].turnaround_time = p[0].burst_time;

    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    // sum
    for(i=0; i<n; i++) {
            sum_waiting_time += p[i].waiting_time;
            sum_turnaround_time += p[i].turnaround_time;
    }
    aw=sum_waiting_time/(nn*1.0);
    att=sum_turnaround_time / (1.0*nn);
    cout<<"\n";
    print_table(p, n);
    cout<<"\n";
    cout<<"Total Waiting Time      : "<<sum_waiting_time<<"\n";
    cout<<"Average Waiting Time    : "<<aw<<"\n";
    cout<<"Total Turnaround Time   : "<<sum_turnaround_time<<"\n";
    cout<<"Average Turnaround Time : "<<att<<"\n";

    // Gantt chart
    cout<<"\n";
    cout<<"   GANTT CHART          \n";
    print_gantt_chart(p, n);
    return 0;
}



}
void SJF()
{
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

}
void priority()
{
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
}

void Round_robin()
{
   struct node
{
    int bt,bt1,bt2;
    int ct=0;
    int wt;
    int tt;
    string pn;
} a[10];

int main() {
    int np, i, q, totalb = 0,t=0,totalb1,totalb2,j,s=0;
    double tw=0,ttt=0;
    cin >> np;
    for (i = 0; i < np; i++) {
        cin >> a[i].pn;
        cin >> a[i].bt;
        a[i].bt1 = a[i].bt;
        a[i].bt2 = a[i].bt;
        totalb = totalb + a[i].bt;
    }
    cin >> q;
    totalb1=totalb;
    totalb2=totalb;
    while (totalb != 0) {
        for (i = 0; i < np; i++) {
            if(a[i].bt!=0){
                if (q > a[i].bt) {
                    t= t + a[i].bt;
                    a[i].ct=t;
                    totalb = totalb - a[i].bt;
                    a[i].bt = 0;
                } else {
                    t= t + q;
                    a[i].ct=t;
                    a[i].bt = a[i].bt - q;
                    totalb = totalb - q;
                }
                s++;
            }

        }


    }
    for(i=0;i<np;i++){
        a[i].tt=a[i].ct-0;
        a[i].wt=a[i].tt-a[i].bt1;
        tw=tw+a[i].wt;
        ttt=ttt+a[i].tt;
    }
    for(i=0;i<np;i++)
    {
        cout<<"Process name : "<<a[i].pn<<"\tWaiting time : "<<a[i].wt<<"\tTurn around time : "<<a[i].tt<<"\n";

    }
    cout<<"\n";
    cout<<"Total wating : "<<tw;
    cout<<"\n";
    cout<<"average wating : "<<tw/np;
    cout<<"\n";
    cout<<"Total turnaround time : "<<ttt;
    cout<<"\n";

    cout<<" ";
    for(i=0;i<s;i++){
        for(j=0;j<6;j++){
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<"\n";

    while (totalb1 != 0) {
        for (i = 0; i < np; i++) {
            if (a[i].bt1 != 0) {
                if (q > a[i].bt1) {
                    t = t + a[i].bt1;
                    cout<<"|  "<<a[i].pn<<"  ";
                    totalb1 = totalb1 - a[i].bt1;
                    a[i].bt1 = 0;
                } else {
                    t = t + q;
                    a[i].bt1 = a[i].bt1 - q;
                    cout<<"|  "<<a[i].pn<<"  ";
                    totalb1 = totalb1 - q;
                }
            }
        }
    }
    cout<<"|";

    cout<<"\n";

    cout<<" ";
    for(i=0;i<s;i++){
        for(j=0;j<6;j++){
            cout<<"-";
        }
        cout<<" ";
    }
    cout<<"\n";
    t=0;
    cout<<"0";
    while (totalb2 != 0) {
        for (i = 0; i < np; i++) {
            if (a[i].bt2 != 0) {
                if (q > a[i].bt2) {
                    t = t + a[i].bt2;
                    if(t<100)
                    cout<<"     "<<t;
                    else
                        cout<<"    "<<t;
                    totalb2 = totalb2 - a[i].bt2;
                    a[i].bt2 = 0;
                } else {
                    t = t + q;
                    a[i].bt2 = a[i].bt2 - q;
                    if(t<100)
                        cout<<"     "<<t;
                    else
                        cout<<"    "<<t;
                    totalb2 = totalb2 - q;
                }
            }
        }
    }




    return 0;
}

}

