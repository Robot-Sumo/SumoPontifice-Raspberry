#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <chrono>

#include <iostream>

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
struct sum_runner_struct {
	long long limit;
	long long answer;
};


int64_t time_stamp1, time_stamp2, time_stamp3, time_stamp4, timeStart, timeStarter;
Timestamp timestamp;
// Thread function to generate sum of 0 to N
void* sum_runner(void* arg)
{
	struct sum_runner_struct *arg_struct =
			(struct sum_runner_struct*) arg;

	long long sum = 0;

	int64_t time_stamp1 = timestamp.getNanoSecs();
	int64_t time_stamp2 = timestamp.getNanoSecs();
	for (long long i = 0; i <= arg_struct->limit; i++) {
		sum += i;
		time_stamp2 = timestamp.getNanoSecs();
		if ((time_stamp2- time_stamp1 )>5000000)
		{
			time_stamp1 = timestamp.getNanoSecs();
			std::cout <<"time stamp2 " << (time_stamp2- timeStarter)/1000000.0<< std::endl;
		}
		
	}

	arg_struct->answer = sum;

	pthread_exit(0);
}

void* sum_runner2(void* arg)
{
	struct sum_runner_struct *arg_struct =
			(struct sum_runner_struct*) arg;

	long long sum = 0;

	int64_t time_stamp1 = timestamp.getNanoSecs();
	int64_t time_stamp2 = timestamp.getNanoSecs();
	for (long long i = 0; i <= arg_struct->limit; i++) {
		sum += i;
		time_stamp2 = timestamp.getNanoSecs();
		if ((time_stamp2- time_stamp1 )>5000000)
		{
			time_stamp1 = timestamp.getNanoSecs();
			std::cout <<"time stamp 1 " << (time_stamp2- timeStarter)/1000000.0<< std::endl;
		}
		
	}

	arg_struct->answer = sum;

	pthread_exit(0);
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: %s <num 1> <num 2> ... <num-n>\n", argv[0]);
		exit(-1);
	}
	int num_args = argc - 1;

	struct sum_runner_struct args[num_args];


	timeStarter = timestamp.getNanoSecs();
	// Launch thread
	pthread_t tids[num_args];
	for (int i = 0; i < num_args; i++) {
		args[i].limit = atoll(argv[i + 1]);

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		if (i == 1) pthread_create(&tids[i], &attr, sum_runner, &args[i]);
		else pthread_create(&tids[i], &attr, sum_runner2, &args[i]);
		
	}

	// Wait until thread is done its work
	for (int i = 0; i < num_args; i++) {
		pthread_join(tids[i], NULL);
		printf("Sum for thread %d is %lld\n",
				i, args[i].answer);
	}
}
