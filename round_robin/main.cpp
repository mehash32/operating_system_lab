#include <iostream>
#include <cstdio>

using namespace std;

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
