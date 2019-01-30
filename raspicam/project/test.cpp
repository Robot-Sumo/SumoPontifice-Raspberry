#include <wiringPi.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <chrono>
#include <sys/timeb.h>


using namespace std::chrono;
using namespace std;
class Timestamp{


public:
    Timestamp(){}

    int64_t getNanoSecs(){
    
    nanoseconds ns = duration_cast< nanoseconds >(
        system_clock::now().time_since_epoch()
    );
    return ns.count();
    }



};

Timestamp timestamp;
int64_t time_stamp1, time_stamp2;
void alarmWakeup(int sig_num);


int main(int argc, char *argv[])
{
    unsigned int j;

    wiringPiSetupPhys();//use the physical pin numbers on the P1 connector


    pinMode(40, OUTPUT);
    pinMode(38, OUTPUT);

    signal(SIGALRM, alarmWakeup);   
    ualarm(5000, 5000);


    while(1)
    {
        digitalWrite(40, HIGH); //pin 40 high
        for(j=0; j<1000000; j++);//do something
        digitalWrite(40, LOW);  //pin 40 low
        for(j=0; j<1000000; j++);//do something
    }

    return 0;

}//int main(int argc, char *argv[])


void alarmWakeup(int sig_num)
{
    unsigned int i;
    
    if(sig_num == SIGALRM)
    {
        time_stamp1 = timestamp.getNanoSecs();
        std::cout << " time  = " << (time_stamp1-time_stamp2)/1000.0<< "us"<<std::endl;
        time_stamp2 = time_stamp1;
        digitalWrite(38, HIGH); //pin 38 high
        for(i=0; i<65535; i++); //do something
        digitalWrite(38, LOW);  //pin 38 low
    }
    
}