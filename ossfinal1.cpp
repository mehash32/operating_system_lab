#include<bits/stdc++.h>

using namespace std;

int main() {
    int option;
    cout<<"Options: 1:FCFS | 2:SJF | 3:Priority"<<endl;
    cout<<"==============================================================\n"<<endl;
    cout << "Choose Option=>";
    cin >> option;
    puts("");
    switch (option) {
        case 1: {
            int n, burst[30], wt[20], tat[20], i, j;
            float avwt = 0, avtat = 0;
            cout << "      //////first come first serve scheduling algorithms///////" << endl << endl;
            cout << "enter the total number of process : ";
            cin >> n;
            cout << "\n Enter each process  burst time considering same arrival time:\n\n";
            for (i = 0; i < n; i++) {
                printf(" P[%2d] = ", i + 1);
                cin >> burst[i];

            }
            wt[0] = 0;

            for (i = 1; i < n; i++) {
                wt[i] = 0;
                for (j = 0; j < i; j++) {
                    wt[i] += burst[j];
                }
                avwt += wt[i];

            }
            cout << "  +-------+-----------+------------+---------------+" << endl;
            cout << "  | PID   | Burst Time| Waitng time| Turnarond Time|" << endl;
            cout << "  +-------+-----------+------------+---------------+" << endl;
            for (i = 0; i < n; i++) {
                tat[i] = burst[i] + wt[i];
                avtat += tat[i];
                printf("  |  %2d   |     %2d    |    %2d      |      %2d       |\n", i + 1, burst[i], wt[i], tat[i]);
            }
            cout << "  +-------+-----------+------------+---------------+" << endl << endl;
            cout << "Total waiting Time = " << avwt << endl;
            cout << "Average Waiting Time = " << avwt / n << endl;
            cout << "Total  Turnaround Time = " << avtat << endl;
            cout << "Average Turnaround Time = " << avtat / n << endl;

            cout << "     \t**Gantt Chart**     " << endl << endl;
            printf("+");
            for (i = 0; i < n; i++) {
                for (j = 0; j < burst[i]; j++) {
                    cout << "--";
                }
                printf("+");
            }

            printf("\n|");


            for (i = 0; i < n; i++) {

                for (j = 0; j < burst[i] - 1; j++) {
                    printf("  ");
                    if (j == burst[i] / 2 - 1) {
                        printf("P%d", i + 1);
                    }

                }
                printf("|");

            }
            printf("\n+");
            for (i = 0; i < n; i++) {
                for (j = 0; j < burst[i]; j++) {
                    cout << "--";
                }
                printf("+");
            }
            printf("\n0 ");
            for (i = 0; i < n; i++) {
                for (j = 0; j < burst[i]; j++) {
                    printf("  ");
                }
                if (tat[i] > 0) {
                    printf("\b");
                    printf("%d", tat[i]);
                }
            }
            cout << endl << endl;

        }
        case 3: {
            int bt[20], p[20], wt[20], tat[20], pr[20], ar[20], i, j, n, pos, temp;
            float total1 = 0, total2 = 0, avg_wt, avg_tat;
            cout << "Enter Total Number of Process:";
            cin >> n;

            cout << "\nEnter Burst Time and Priority and arrival time\n";
            for (i = 0; i < n; i++) {
                cout << "\nP[" << i + 1 << "]\n";
                cout << "Burst Time:";
                cin >> bt[i];
                cout << "Priority:";

                cin >> pr[i];
                cout << "Arrival time:";
                cin >> ar[i];

                p[i] = i + 1;
            }


            for (i = 0; i < n; i++) {
                pos = i;
                for (j = i + 1; j < n; j++) {
                    if (pr[j] < pr[pos])
                        pos = j;
                }

                temp = pr[i];
                pr[i] = pr[pos];
                pr[pos] = temp;

                temp = bt[i];
                bt[i] = bt[pos];
                bt[pos] = temp;

                temp = p[i];
                p[i] = p[pos];
                p[pos] = temp;
            }

            wt[0] = 0;
            for (i = 1; i < n; i++) {
                wt[i] = 0;
                for (j = 0; j < i; j++)
                    wt[i] += bt[j];

                total1 += wt[i];
            }
            cout<<"          *******Priority Scheduling algorithms********"<<endl<<endl<<endl;
            cout<< " \nProcess\t    priority \t         Arrival time\t     Burst Time    \tWaiting Time\tTurnaround Time";
            for (i = 0; i < n; i++) {
                tat[i] = bt[i] + wt[i];
                total2 += tat[i];
                cout << " \nP[" << p[i] << "]\t\t" << pr[i] << "\t\t  " << ar[i] << "\t\t\t" << bt[i] << "\t\t    "
                     << wt[i] << "\t\t  " << tat[i] << endl << endl;
            }

            avg_tat = total2 / n;
            cout << "Total waiting Time = " << total1 << endl;
            cout << "\n\nAverage Waiting Time= " << avg_wt << endl;
            cout << "Total  Turnaround Time = " << total2 << endl;
            cout << "\nAverage Turnaround Time= " << avg_tat << endl << endl;
            cout << "     \t**Gantt Chart**     " << endl << endl;
            printf("+");
            int s=0;
            for (i = 0; i < n; i++) {

                for (j = 0; j < bt[i]; j++) {
                    cout << "--";
                }
                printf("+");
            }

            printf("\n|");


            for (i = 0; i < n; i++) {

                for (j = 0; j < bt[i] - 1; j++) {
                    printf(" ");
                }

                        printf("P%d",p[i]);
                 for(j=0; j<bt[i]-1; j++)
        {
             printf(" ");
        }

                printf("|");

            }
            printf("\n+");
            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i]; j++) {
                    cout << "--";
                }
                printf("+");
            }
            printf("\n0 ");
            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i]; j++) {
                    printf("  ");
                }
                s=s+bt[i];
                if(s>9)
                {
                    printf("\b");
                }
                 printf("%d", s);
            }
            cout << endl << endl;

        }
        case 2: {
            int i, n, p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, min, k = 1, btime = 0;
            int bt[10], temp, j, at[10], wt[10], tt[10], ta = 0, sum = 0;
            float wavg = 0, tavg = 0, tsum = 0, wsum = 0;
            printf(" -------Shortest Job First Scheduling ( NP )-------\n");
            printf("\nEnter the No. of processes :");
            scanf("%d", &n);

            for (i = 0; i < n; i++) {
                printf("\tEnter the burst time of %d process :", i + 1);
                scanf(" %d", &bt[i]);
                printf("\tEnter the arrival time of %d process :", i + 1);
                scanf(" %d", &at[i]);
            }


            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (at[i] < at[j]) {

                        temp = p[j];
                        p[j] = p[i];
                        p[i] = temp;
                        temp = at[j];
                        at[j] = at[i];
                        at[i] = temp;
                        temp = bt[j];
                        bt[j] = bt[i];
                        bt[i] = temp;
                    }
                }
            }


            for (j = 0; j < n; j++) {
                btime = btime + bt[j];
                min = bt[k];
                for (i = k; i < n; i++) {
                    if (btime >= at[i] && bt[i] < min) {
                        temp = p[k];
                        p[k] = p[i];
                        p[i] = temp;
                        temp = at[k];
                        at[k] = at[i];
                        at[i] = temp;
                        temp = bt[k];
                        bt[k] = bt[i];
                        bt[i] = temp;
                    }
                }
                k++;
            }
            wt[0] = 0;
            for (i = 1; i < n; i++) {
                sum = sum + bt[i - 1];
                wt[i] = sum - at[i];
                wsum = wsum + wt[i];
            }

            wavg = (wsum / n);
            for (i = 0; i < n; i++) {
                ta = ta + bt[i];
                tt[i] = ta - at[i];
                tsum = tsum + tt[i];
            }

            tavg = (tsum / n);

            printf("************************");
            printf("\n RESULT:-");
            printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around");
            for (i = 0; i < n; i++) {
                printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d", p[i], bt[i], at[i], wt[i], tt[i]);
            }
            cout << "Total waiting Time = " << wsum << endl;
            printf("\n\nAERAGE WAITING TIME : %f\n", wavg);
            cout << "Total  Turnaround Time = " << tsum << endl;
            printf("\nAVERAGE TURN AROUND TIME : %f\n", tavg);
            cout << "     \t**Gantt Chart**     " << endl << endl;
            printf(" ");
            int s = 0;
            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i]; j++) {
                    printf("--");
                }
                printf(" ");
            }
            printf("\n|");


            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i] - 1; j++) {
                    printf(" ");
                }
                printf("p%d", p[i]);
                for (j = 0; j < bt[i] - 1; j++) {
                    printf(" ");
                }
                printf("|");
            }
            printf("\n ");



            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i]; j++) {
                    printf("--");
                }
                printf(" ");
            }
            printf("\n");


            printf("0");
            for (i = 0; i < n; i++) {
                for (j = 0; j < bt[i]; j++) {
                    printf("  ");
                } printf("%d", s);
                s = s + bt[i];
                if (s > 9) {
                    printf("\b");
                }
                printf("%d", s);

            }

                  cout<<endl<<endl;
        }

    }
}

