#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"					WELLCOME TO PAGGING                       "<<endl;
    cout<<"			__________________________________________________________		"<<endl;
    cout<<endl;
    int logical_memory_size;//byte
    int physical_memory_size;//byte
    int page_table[100];
    int page_table_space[100];

    int unit;//byte
    cout<<"ENTER LOGICAL MEMORY SIZE : ";

    cin>>logical_memory_size;
    cout<<"________________________________"<<endl;
    cout<<"ENTER PHYSICAL MEMORY SIZE : ";

    cin>>physical_memory_size;
    cout<<"________________________________"<<endl;
    cout<<"ENTER UNIT SIZE : ";

    cin>>unit;
    cout<<"________________________________"<<endl;

    int logical_block=logical_memory_size/unit;
    int physical_block=physical_memory_size/unit;
    int a,b,i=0,k=0;

    cout<<"PAGE NO"<<" 	"<<"FRAME NO"<<endl;
    cout<<"________"<<"	 "<<"________"<<endl;

    for(int j=0; j<physical_block; j++)//loop will continue to frame number 
    {
        cin>>a>>b;

        page_table[a]=b;
        for(; i<logical_memory_size;)
        {
            page_table_space[i++]=k++;

            if(i%unit==0)
            {

                break;
            }
        }


    }
   /* 
   for(int i=0; i<logical_memory_size; i++)
    {
        cout<<page_table_space[i]<<" ";
        int f=i;
        if(f==3||f==7||f==11||f==15||f==19||f==23||f==27||f==31||f==35||f==39||f==43||f==47||f==51)
            {
				
                cout<<" logical  address in one block of page  ";
                cout<<endl;
                f+=4;
                //aa++;
               
            }

    }
    */
    int logical_address;
    int physical_address;
    cout<<"ENTER LOGICAL ADDRESS : ";
    cin>>logical_address;
    cout<<"________________________"<<endl;
    int page_no=logical_address/unit;
    int offset=logical_address%unit;

    int frame=page_table[page_no];
    physical_address=(frame*unit)+offset;
   
    cout<<"PAGE NUMBER IS : "<<page_no<<endl;
    cout<<"________________________"<<endl;
     if(page_no>a)
    {
    	cout<<" This page is not the page table"<<endl;
    	return 0;
	}
    cout<<"FRAME NUMBER IS : "<<frame<<endl;
    cout<<"________________________"<<endl;
    cout<<"OFFSET NUMBER IS : "<<offset<<endl;
    cout<<"________________________"<<endl;

    cout<<"PHYSICAL ADDRESS IS : "<<physical_address<<endl;
    cout<<"________________________"<<endl;
    cout<< "PROGRAMME IS ENDED"<<endl;
    cout<<"___________________________________________"<<endl;
    

    return 0;


}

