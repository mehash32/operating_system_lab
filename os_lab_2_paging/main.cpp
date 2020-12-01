#include<bits/stdc++.h>

using namespace std;

int lmsize, pmsize, unit;
int CNT[1000];

int main()
{
    printf("Logical Memory Size: ");
    cin >> lmsize;
    printf("Physical Memory Size: ");
    cin >> pmsize;
    printf("Page Unit: ");
    cin >> unit;
    int block = lmsize / unit;
    int k = pmsize / unit;
    int prev = 0;


    printf("logical memory address : ");
    printf("\n");
    for (int i=1;i<=block;i++)
    {
        printf ("%d\t%d\t%d\n",i, prev, unit * i-1);
        prev = unit * i;
    }
    printf("physical memory address : ");
    printf("\n");
    prev = 0;
    for (int i=1;i<=k;i++)
    {
        printf ("%d\t%d\t%d\n",i, prev, unit * i-1);
        prev = unit * i;
    }
    cout << endl;
    int n;
    cout << "combination of connection" << endl;
    cout<< "input n no of combination : " << endl;
    cin>>n;

    cout << endl;
    for(int i=1;i<=n;i++) {
            int a, b;
            cin >> a >> b;
            CNT[a] = b;
    }

    cout << "output part" << endl;
    cout << "inter logical address" << endl;
    for( int i=0;i<=n;i++) {

            int m, x, ans, p;
            cin >> m;
            x = m / unit + 1;
            p = CNT[x] - 1;
            ans = p * unit + m % unit;
            printf("Phyical memory address : %d\n", ans);
            printf("page no : %d\n ",CNT[x]);

    }

    return 0;
}
