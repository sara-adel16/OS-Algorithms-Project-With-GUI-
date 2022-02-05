#include <bits/stdc++.h>
#include <fstream>
using std::atoi;
using namespace std;
struct processTemp{
    int executionTime, deadline, period;
    processTemp(int e, int d, int p) : executionTime(e), deadline(d), period(p){}
};

//includes all the processes of the system
vector<processTemp> process, updatedProcess;

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
        sum += (double) process[i].executionTime / (double) process[i].period;

    //if sum <= 1, then the set of processes MAY be Schedulable .. Otherwise it cannot be scheduled
    return sum <= 1;
}

//get the index of the next process to be executed
//Processes are assigned priorities inversely based on it's Earliest Deadline
int getEarliestDeadLine(){
    int earliestDeadline = lcm, index = -1;
    /*
    variable index will store the index of the Process which has the highest Priority
    -> The shorter Time Period a Process has, The Higher Priority it will be assigned
    */
    for(int i = 0; i < processCount; ++i){
        if(updatedProcess[i].executionTime == 0) continue;

        if(updatedProcess[i].deadline < earliestDeadline)
            earliestDeadline = updatedProcess[i].deadline, index = i;
    }
    return index;
}

void schedule(){

	int execTime, deadLine, period;
	for(int i = 0; i < processCount; ++i){

		execTime = process[i].executionTime;
		deadLine = process[i].deadline;
		period = 0;

		processTemp process(execTime, deadLine, period);
		updatedProcess.push_back(process);
	}

	ofstream file;
	file.open("EDF_Result.txt");
	file << "\n\tSchedule:\n\n";

	for(int time = 0; time < lcm; ++time){


			//getting the index of the next process to be executed based on it's priority
            int nxtProcess = getEarliestDeadLine();

            //if we found a process to be executed
            if(~nxtProcess)
                file << "\tTime [" << time <<" , "<< time + 1 << "] : " << "Process " << nxtProcess + 1 <<"\n";

            //else there is no process ready to be executed
            else
                file << "\tTime [" << time <<" , "<< time + 1 << "] : " << "NO Process Is Running\n";


            //reduce the execution time of the running process by 1 after each time unit
            if(~nxtProcess)
			updatedProcess[nxtProcess].executionTime --;

			//get the next deadline distance
			for(int i = 0; i < processCount; ++i){

                //reduce the time period of each process by 1 after each time unit
                updatedProcess[i].period ++;

                /*
                if the current period of the process is completely finished,
                reset the process data (restore the original execution time, deadline, and set time period to zero)
                */
                if(updatedProcess[i].period == process[i].period){
                    updatedProcess[i].deadline = process[i].deadline;
                    updatedProcess[i].executionTime = process[i].executionTime;
                    updatedProcess[i].period = 0;
                }
                else {
                    //if deadline is not reached yet, decrease it by 1
                    if(updatedProcess[i].deadline != 0)
                        updatedProcess[i].deadline --;

                    /*
                    if the deadline is reached & the current process hasn't completed it's execution time yet,
                    This means that it has missed it's deadline and cannot be completed..
                    -->>> The system is not schedulable
                    */
                    else if(updatedProcess[i].executionTime != 0)
                        file << "\n\tThe process "<< i + 1 <<" cannot be completed\n";
                }
			}
	}
	file << "\n";
	file.close();
	return;
}

int main(int argc, char * argv[])
{
	processCount = atoi(argv[1]);

    int execTime, deadLine, period;
	for(int i = 2; i < 3 * processCount + 2; i += 3){

		execTime = atoi(argv[i]);
		deadLine = atoi(argv[i + 1]);
		period = atoi(argv[i + 2]);

        processTemp oneProcess(execTime, deadLine, period);
        process.push_back(oneProcess);
	}

	//check if the system can be scheduled or not
    bool schedulable = check();

	//if it cannot be scheduled, report this and terminate the program
	if(!schedulable){
        ofstream file;
        file.open("EDF_Result.txt");
        file << "This System is not schedulable!\n";
        file.close();
        return 0;
    }

    //Compute the Least Common Multiple of the Time periods of the whole set of processes
    lcm = process[0].period;
    for(int i = 1; i < processCount; ++i)
        lcm = LCM(lcm, process[i].period);

    //schedule the set of processes
    schedule();
}
