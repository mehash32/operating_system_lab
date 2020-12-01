#include<bits/stdc++.h>

using namespace std;

int base[100], limit[100];

struct Point
{
    int p, bd, lm;
}point[100];

bool com(Point A, Point B)
{
    return A.bd < B.bd;
}

int main()
{
    char ch;
    int n, i, j, ix, s, v, k;
    cout<<"         SEGMENTATION            "<<endl;
    cout<<"_________________________________"<<endl;
    cout << "Enter number of segments : " << " ";
    cout<<"_________________________________"<<endl;
    cin >> n;
    printf ("Enter base address && base address limit\n");
    cout<<"_____________________________________________"<<endl;
    for (i = 0; i < n; i++) {
        cin >> base[i] >> limit[i];
        point[i].p = i;
        point[i].bd = base[i];
        point[i].lm = limit[i];
    }
    sort(point, point + n, com);

    cout<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cout<<"segment no - "<<point[i].p<< " :--   "<< point[i].bd<< " <-> "<<point [i].bd + point[i].lm<<endl;
        }
    }




    cout<<"Enter segment no && offset : "<<endl;
    for ( i=0;i<n;i++)
    {
        cin>>s>>v;
        k = base[s];

            if(v > limit[s])
                    cout << "Invalid !" << endl;

            else
                cout << k + v << endl;


    }

    return 0;
}
