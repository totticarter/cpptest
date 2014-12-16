#include "zhelpers.h"
#include <unistd.h>

int main (void)
{
	void *context = zmq_ctx_new ();


	void *sender = zmq_socket (context, ZMQ_PUSH);
	zmq_bind (sender, "tcp://*:5557");


	void *sink = zmq_socket (context, ZMQ_PUSH);
	zmq_connect (sink, "tcp://localhost:5558");

	printf ("Press Enter when the workers are ready: ");
	getchar ();
	printf ("Sending tasks to workers…\n");


	s_send (sink, "0");


	srandom ((unsigned) time (NULL));


	int task_nbr;
	int total_msec = 0; // Total expected cost in msecs
	for (task_nbr = 0; task_nbr < 100; task_nbr++) {
		sleep(1);
		int workload;

		workload = randof (100) + 1;
		total_msec += workload;
		char string [10];
		sprintf (string, "%d", workload);
		s_send (sender, string);
	}
	printf ("Total expected cost: %d msec\n", total_msec);

	zmq_close (sink);
	zmq_close (sender);
	zmq_ctx_destroy (context);
	return 0;
}
