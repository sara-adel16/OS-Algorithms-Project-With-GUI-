#include <bits/stdc++.h>
#include <fstream>
using std::atoi;
using namespace std;
//first is the execution time of the process
//second is the time period of the process
vector<pair<int,int> > process;

//This vector contains the same data as the vector "process" but it will be updated in the runTime
vector<pair<int,int> > updatedProcess;

int processCount; //Number of the processes to be scheduled
int lcm; //Least Common Multiple

//Calculates the Least Common Multiple of two numbers
int LCM(int a, int b){
    return a / __gcd(a,b) * b;
}

//check schedulability
bool check(){
    double sum = 0;
    for(int i = 0; i < processCount; ++i)
        sum += (double) process[i].first / (double) process[i].second;

    //if sum <= 1, then the set of processes MAY be Schedulable .. Otherwise it cannot be scheduled
    return sum <= 1;
}

bool check_deadline(){
    for(int i = 0; i < processCount; ++i){
        /*
        for any process i: if the execution time exceeded the time period
        then process i has missed it's deadline which means that This set of processes is not schedulable..
        */
        if(updatedProcess[i].first > updatedProcess[i].second)
            return 1;
    }
    return 0;
}

//get the index of the next process to be executed
//Processes are assigned priorities inversely based on it's Time Period
int getPriority(){
    int leastPeriod = lcm, index = -1;
    /*
    variable index will store the index of the Process which has the highest Priority
    -> The shorter Time Period a Process has, The Higher Priority it will be assigned
    */
    for(int i = 0; i < processCount; ++i){
        if(updatedProcess[i].first == 0) continue;

        if(updatedProcess[i].second < leastPeriod)
            leastPeriod = updatedProcess[i].second, index = i;
    }
    return index;
}

void schedule(){
    for(int i = 0; i < processCount; ++i)
        updatedProcess.push_back(process[i]);

    ofstream file;
    file.open("output.txt");
    file << "\n";
    for(int time = 0; time < lcm; ++time){

        //Check if any process has missed it's deadline
        bool missed_deadline = check_deadline();
        if(missed_deadline){
            file << "This System is not schedulable!\n";
            return;
        }

        //Index of the next process to be executed based on it's priority
        int nxtProcess = getPriority();


        //if we found a process to be executed
        if(~nxtProcess)
            file << "\tTime [" << time <<" , "<< time + 1 << "] : " << "Process " << nxtProcess + 1 <<"\n";

        //else there is no process ready to be executed
        else
            file << "\tTime [" << time <<" , "<< time + 1 << "] : " << "NO Process Is Running\n";


        //reduce the execution time of the running process by 1 after each time unit
        if(~nxtProcess)
            updatedProcess[nxtProcess].first --;

        for(int i = 0; i < processCount; ++i){
            //reduce the time period of each process by 1 after each time unit
            updatedProcess[i].second --;

            /*
            if the current period of the process is completely finished,
            reset the process data (restore the original execution time & time period of the process)
            */
            if(!updatedProcess[i].second)
                updatedProcess[i] = process[i];
        }
    }
    file << "\n";
    file.close();
    return;
}

int main(int argc, char * argv[])
{
    //read data
    processCount = atoi(argv[1]);

    int executionTime, timePeriod;
    for(int i = 2; i < 2 * processCount + 2; i += 2){
        executionTime = atoi(argv[i]), timePeriod = atoi(argv[i + 1]);
        process.push_back({executionTime, timePeriod});
    }


    //check if the system can be scheduled or not
    bool schedulable = check();

    //if it cannot be scheduled, report this and terminate the program
    if(!schedulable){
        ofstream file;
        file.open("RMA.txt");
        file << "This System is not schedulable!\n";
        file.close();
        return 0;
    }

    //Compute the Least Common Multiple of the Time periods of the whole set of processes
    lcm = process[0].second;
    for(int i = 1; i < processCount; ++i)
        lcm = LCM(lcm, process[i].second);

    //schedule the set of processes
    schedule();
    return 0;
}
