/*WELCOME TO

PARKING LOT SYSTEM


|------       /\        |-----   |   /  ---------  |\     | --------        |           |-------|   ---------
|     |      /  \       |     |  |  /       |      | \    | |               |           |       |       |
|     |     /    \      |------  |/         |      |  \   | |               |           |       |       |
|------    /------\     |\       |\         |      |   \  | |   ---|        |           |       |       |
|         /        \    | \      |  \       |      |    \ | |      |        |           |       |       |
|        /          \   |  \     |   \   --------  |     \| --------        |--------   |-------|       |

|----   \    /  |-----     --------     |-------    |\    /|
|        \  /   |              |        |           | \  / |
|----     \/    |----|         |        |-------    |  \/  |
    |     |          |         |        |           |      |
    |     |          |         |        |           |      |
----|     |      ----|         |        |-------    |      |


*/

/*
#include <iostream>
#include<queue>
#include<vector>
//#include<functional>
#include<stdlib.h>
#include<math.h>
#include<cmath>
*/


#include<bits/stdc++.h>
using namespace std;


float corx[130]={0};
float cory[130]={0};
float lx,ly,plx,ply;
int k=0;

void menu();



class car{
    public:

        float x;
        float y;

    car(float x, float y)
    {

        this->x=x;
        this->y=y;

    }

    float dist()
    {

        return abs(((lx-x)*(lx-x))+((ly-y)*(ly-y)));
    }

    void print()
    {

        cout<<"\nCoordinates at which your car can be parked are ("<<x<<","<<y<<")\n"<<endl;
    }
};


class carcompare{
    public:
    bool operator()(car a, car b)
    {

        return a.dist()>b.dist();
    }
};


priority_queue<car,vector<car>,carcompare> pq;

/*
void showpq (priority_queue <car, vector<car>, carcompare> pq)
{
    priority_queue <car, vector<car>, carcompare> g = pq;
    while (!g.empty())
    {
        car s=g.top();
        s.print();
        g.pop();
    }
    cout << "\n";
}
*/

void in()
{
cout<<"Don't worry, we are here to tell the empty parking slot near the lift \n"<<endl;

char ch='y';

 while(ch=='y')
 {

     if(pq.empty())
     {
         cout<<"\n Oops!!  Parking full\n";
         break;
     }
     car p=pq.top();

    k++;

    p.print();

     pq.pop();


//showpq(pq);
    cout<<"\nDo you want to park one more car? (y/n)\n"<<endl;
    cin>>ch;


 }

menu();

}


void out()
{

    char rch='y';
 while(rch=='y')
 {
 priority_queue<car,vector<car>,carcompare> rpq=pq;

    float a,b;

    if(k==0)
        {
            cout<<"\nNo cars are there in the parking lot\n";
            break;
        }
    k--;
     int pno;
     cout<<"Enter x and y coordinates"<<endl;

     cin>>a>>b;

car c(a,b);
int flag=0;
while (!rpq.empty())
    {
        car s=rpq.top();
        if ((s.x==c.x) && (s.y==c.y))
        {
            cout<<"This slot is already empty!!"<<endl;
            flag=1;
            break;
        }
        rpq.pop();
    }
if (flag==0)
    pq.push(c);



     if(pq.empty())
     {
         cout<<"No more cars left to remove"<<endl;

         break;
     }

/*

     car p=rpq.top();

         if(pno==p.no)
         {
             cout<<p.no;

             for(int i=0;i<5;i++)
             {
                 cout<<x[i];

               if(x[i]==p.x && y[i]==p.y)
                    {
                    z[i]=true;
                    break;
                    }
             }
             break;
         }


            rpq.pop();

 } */

//showpq(pq);

cout<<"Remove more cars(y/n)"<<endl;

cin>>rch;
}

menu();
}



void menu()
{
    cout<<"*******************************Welcome to DLF Mall Parking*******************************"<<endl;

    int n;

    cout<<"Choose an option :"<<endl;

    cout<<" 1. Park your car \n 2. Exit your car \n 3. Exit \n"<<endl;

    cout<<"\nYour choice: ";

    cin>>n;


    switch(n)
    {
    case 1:
        in();
        break;
    case 2:
        out();
        break;
    case 3:
        exit(1);
        break;
    default:
        cout<<"Error! \nPlease select from the given options. \n";
        menu();
    }
}





int main()
{
    cout<<" **********                                                                                             "<<endl;
    cout<<" *        *                                                                                             "<<endl;
    cout<<" *        *       *       ******** *   * ******* *     * ********        *        ******** *******      "<<endl;
    cout<<" *        *      * *      *      * *  *     *    **    * *               *        *      *    *         "<<endl;
    cout<<" **********     *   *     *      * * *      *    * *   * *               *        *      *    *         "<<endl;
    cout<<" *             *******    ******** **       *    *  *  * *   ****        *        *      *    *         "<<endl;
    cout<<" *            *       *   * *      * *      *    *   * * *      *        *        *      *    *         "<<endl;
    cout<<" *           *         *  *   *    *  *     *    *    ** *      *        *        *      *    *         "<<endl;
    cout<<" *          *           * *     *  *   * ******* *     * ********        ******** ********    *         "<<endl;
    cout<<"                  PARKING LOT SYSTEM FOR SHORTEST DISTANCE NEAR THE LIFT                                "<<endl<<endl;

cout<<"Enter No of columns and number of rows in the parking lot"<<endl;

cin>>plx>>ply;

int i,j,count=0;

for(j=1;j<=ply;j++)
    {
        for(i=1;i<=plx;i++)
        {
            corx[count]=i;
            count++;
        }
    }

count=0;

for(j=1;j<=ply;j++)
    {
        for(i=1;i<=plx;i++)
        {
            cory[count]=j;
            count++;
        }
    }


/*
for(i=0;i<(plx*ply);i++)
{

    cout<<corx[i];
}


for(i=0;i<(plx*ply);i++)
{
    cout<<cory[i];

}

*/

cout<<"Enter x and y coordinates of the lift"<<endl;

cin>>lx>>ly;

for(int i=0;i<(plx*ply);i++)
 {
     car c(corx[i],cory[i]);
     pq.push(c);
 }

 //showpq (pq);

pq.pop();
k++;

menu();

return 0;
}