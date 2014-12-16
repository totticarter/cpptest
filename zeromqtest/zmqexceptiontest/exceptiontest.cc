#include<zmq.hpp>
#include<iostream>

using namespace std;

int main(){

	try{
		zmq::context_t ctx (1);
		zmq::socket_t s(ctx, ZMQ_PUB);
		s.connect ("://192.168.0.115:5555");
		zmq::message_t msg (100);
		memset (msg.data (), 0, 100);
		s.send (msg);
	}
	catch(zmq::error_t e){

		cout << e.what() << endl;
	}
	return 0;

}
