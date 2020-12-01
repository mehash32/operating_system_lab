#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int pid,arrival_time,burst_time,waiting_time,turnaround_time;
    string pn;
};

void print_table(struct Process p[], int n);
void print_gantt_chart(struct Process p[], int n);

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
