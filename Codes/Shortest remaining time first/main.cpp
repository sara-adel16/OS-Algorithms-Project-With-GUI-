#include <fstream>
#include <bits/stdc++.h>
using namespace std;
using std::atoi;

int main(int argc,char** argv)

{

    int arrival[10],burst[10],x[10];
    /*
     a[i] --> Array to take Arrival time data
     b[i] --? Array to take burst time data

    */
    int waiting[10],turnaround[10],completion[10];
    int index,smallestIndex,Counter=0,time,numOfProcess;
    double averageWaitingTime=0,tt=0,End;


    numOfProcess = atoi(argv[1]);
    for(index=0; index<numOfProcess; index++)
    {
        arrival[index] = atoi(argv[index + 2]);
    }
    for(index=0; index<numOfProcess; index++)
    {
        burst[index] =  atoi(argv[index+2+numOfProcess]);
    }



    for(index=0; index<numOfProcess; index++) // TO save burst time data in Array x;
        x[index]=burst[index];

    burst[9]=9999; //to initialize the highest number into last index
    for(time=0; Counter!=numOfProcess; time++)
    {
        smallestIndex=9; //assign the smallest equal to 9 to go to last index;
        for(index=0; index<numOfProcess; index++)
        {
            if(arrival[index]<=time && burst[index]<burst[smallestIndex] && burst[index]>0 )
                smallestIndex=index;
        }
        burst[smallestIndex]--;

        if(burst[smallestIndex]==0)
        {
            Counter++;
            End=time+1;
            completion[smallestIndex] = End;
            waiting[smallestIndex] = End - arrival[smallestIndex] - x[smallestIndex];
            turnaround[smallestIndex] = End - arrival[smallestIndex];
        }
    }


    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(index=0; index<numOfProcess; index++)
    {
        cout<<"p"<<index+1<<"\t\t"<<x[index]<<"\t\t"<<arrival[index]<<"\t\t"<<waiting[index]<<"\t\t"<<turnaround[index]<<"\t\t"<<completion[index]<<endl;
        averageWaitingTime = averageWaitingTime + waiting[index];
        tt = tt + turnaround[index];
    }
    float resavg=averageWaitingTime/numOfProcess;
    ofstream myfile;
    myfile.open ("Average.txt");
    myfile << resavg;
    myfile.close();
    float resturn = tt/numOfProcess;
    myfile.open ("Turnaround.txt");
    myfile << resturn;
    myfile.close();

//system("pause");

}
