/// Scheduling Algothim
/// by Md. Mithun Rahman
/// student id. 170225

#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int burst_time, wait_time, turn_time, pos, proi_num;
    int start_time, arrival_time, end_time, num;
};

bool com1(Process A, Process B)
{
    if (A.burst_time != B.burst_time)
        return A.burst_time < B.burst_time;
    return A.arrival_time < B.arrival_time;
}

bool com2(Process A, Process B)
{
    if (A.proi_num != B.proi_num)
        return A.proi_num < B.proi_num;
    return A.num < B.num;
}

void FCFS()
{
    Process P1[100];
    int n, wt = 0;
    cout << "Enter number of process" << " : ";
    cin >> n;
    cout << "Enter Arrival time and Burst time" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> P1[i].arrival_time >> P1[i].burst_time;
        if (i == 1)
            P1[i].start_time = P1[i].arrival_time;
        else
            P1[i].start_time = P1[i - 1].end_time;
        P1[i].end_time = P1[i].burst_time + P1[i].start_time;
        P1[i].wait_time = P1[i].start_time - P1[i].arrival_time;
        P1[i].turn_time = P1[i].wait_time + P1[i].burst_time;
        wt += P1[i].turn_time;
    }
    cout << "GANTT CHART" << endl;
    cout << P1[1].start_time << "";
    for (int i = 1; i <= n; i++) {
        cout << "---" << "P" << i << "---" << P1[i].end_time << "";
    }
    cout << endl;
    cout << "Turnaround Time" << " : " << wt << endl;
    cout << "Individual waiting time" << endl;
    wt = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Process No.(" << i << ") waiting time : " << P1[i].wait_time << endl;
        wt += P1[i].wait_time;
    }
    cout << "Total waiting time " << " : " << wt << endl;
    cout << "Average waiting time " << " : " << wt * 1.0 / n << endl;
}

void SJF()
{
    Process P2[100];
    int n, wt = 0;
    cout << "Enter number of process" << " : ";
    cin >> n;
    cout << "Enter Arrival time and Burst time" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> P2[i].arrival_time >> P2[i].burst_time;
        P2[i].pos = i;
    }
    sort (P2 + 2, P2 + n + 1, com1);
    P2[0].end_time = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            P2[i].start_time = P2[i].arrival_time;
        else
            P2[i].start_time = P2[i - 1].end_time;
        P2[i].end_time = P2[i].burst_time + P2[i].start_time;
        P2[i].wait_time = P2[i].start_time - P2[i].arrival_time;
        P2[i].turn_time = P2[i].wait_time + P2[i].burst_time;
        wt += P2[i].turn_time;
    }
    cout << "GANNT CHART" << endl;
    cout << P2[1].arrival_time << "";
    for (int i = 1; i <= n; i++) {
        cout << "---" << "P" << P2[i].pos << "---" << P2[i].end_time << " ";
    }
    cout << endl;
    cout << "Turnaround Time" << " : " << wt << endl;
    cout << "Individual waiting time" << endl;
    wt = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Process No.(" << i << ") waiting time : " << P2[i].wait_time << endl;
        wt += P2[i].wait_time;
    }
    cout << "Total waiting time " << " : " << wt << endl;
    cout << "Average waiting time " << " : " << wt * 1.0 / n << endl;
}

void PS()
{
    Process P3[100];
    int n, wt = 0;
    cout << "Enter number of process" << " : ";
    cin >> n;
    cout << "Enter Burst time and Priority number" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> P3[i].burst_time >> P3[i].proi_num;
        P3[i].pos = P3[i].num = i;
        P3[i].arrival_time = 0;
    }
    sort (P3 + 1, P3 + n + 1, com2);
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            P3[i].start_time = 0;
        else
            P3[i].start_time = P3[i - 1].end_time;
        P3[i].end_time = P3[i].burst_time + P3[i].start_time;
        P3[i].wait_time = P3[i].start_time - P3[i].arrival_time;
        P3[i].turn_time = P3[i].wait_time + P3[i].burst_time;
        wt += P3[i].turn_time;
    }
    cout << "GANNT CHART" << endl;
    cout << P3[1].arrival_time << "";
    for (int i = 1; i <= n; i++) {
        cout << "---" << "P" << P3[i].pos << "---" << P3[i].end_time << "";
    }
    cout << endl;
    cout << "Turnaround Time" << " : " << wt << endl;
    cout << "Individual waiting time" << endl;
    wt = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Process No.(" << i << ") waiting time : " << P3[i].wait_time << endl;
        wt += P3[i].wait_time;
    }
    cout << "Total waiting time " << " : " << wt << endl;
    cout << "Average waiting time " << " : " << wt * 1.0 / n << endl;
}

void RB()
{
    Process P4[100];
    deque <int> dq, ready_q, sm1, result1, result, sm, pr_end[100], pr_st[100];
    int n, cnt = 1, tm, sum, rm;
    cout << "Enter the number of Process : " << "";
    cin >> n;
    cout << "Enter the quantam time : " << "";
    cin >> tm;
    cout << "Enter Arrival time and Burst time" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> P4[i].arrival_time >> P4[i].burst_time;
        dq.push_front(i);
    }
    ready_q.push_back(1);
    sum = 0;
    rm = tm;
    dq.pop_back();
    while (!ready_q.empty()) {
        sum += rm;
        if (cnt <= n) {
            while (sum >= P4[dq.back()].arrival_time && (!dq.empty())) {
                cnt++;
                ready_q.push_back(dq.back());
                dq.pop_back();
            }
        }
        result.push_front(ready_q.front());
        sm.push_front(sum - tm);
        if (tm >= P4[ready_q.front()].burst_time) {
            rm = P4[ready_q.front()].burst_time;
            ready_q.pop_front();
        }
        else {
            rm = tm;
            P4[ready_q.front()].burst_time -= tm;
            int v = ready_q.front();
            ready_q.pop_front();
            ready_q.push_back(v);
        }
    }
    sm.push_front(sum);
    sm1 = sm;
    result1 = result;
    cout << "GANNT CHART" << endl;
    cout << sm.back() <<"";
    sm.pop_back();
    while (!result.empty()) {
        cout << "---" << "P" << result.back() << "---" << sm.back() << "";
        pr_end[result.back()].push_back(sm.back());
        result.pop_back();
        sm.pop_back();
    }
    cout << endl;
    sm1.pop_front();
    while (!sm1.empty()) {
       // cout << result1.back() << " " << sm1.back() << endl;
        pr_st[result1.back()].push_back(sm1.back()) ;
        sm1.pop_back();
        result1.pop_back();
    }
    for (int i = 1; i <= n; i++) {
        int wt = 0;
        for (int j = 0; j < pr_end[i].size(); j++) {
            if (j == 0)
                wt += pr_st[i][j];
            else {
                wt += (pr_st[i][j] - pr_end[i][j - 1]);
            }
        }
        P4[i].wait_time = wt;
    }
    int tat = 0;
    for (int i = 1; i <= n; i++) {
        tat += (P4[i].wait_time + P4[i].arrival_time);
    }
    cout << "Turnaround Time" << " : " << tat << endl;
    cout << "Individual waiting time" << endl;
    int wt = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Process No.(" << i << ") waiting time : " << P4[i].wait_time << endl;
        wt += P4[i].wait_time;
    }
    cout << "Total waiting time " << " : " << wt << endl;
    cout << "Average waiting time " << " : " << wt * 1.0 / n << endl;
}


int main()
{
    int n;
    cout << "Press 1 for FCFS" << endl;
    cout << "Press 2 for SJF" << endl;
    cout << "Press 3 for PS" << endl;
    cout << "Press 4 for RB" << endl;
    cout << "Press others for exit" << endl;
    while (cin >> n) {
        if (n == 1) FCFS();
        else if (n == 2) SJF();
        else if (n == 3) PS();
        else if (n == 4) RB();
        else break;
    }
    cout << "Happy coding" << endl;
    return 0;
}
