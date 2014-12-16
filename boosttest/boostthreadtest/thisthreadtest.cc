#include<boost/thread/thread.hpp>
#include<iostream>

using namespace std;

void fun(){

	cout << boost::this_thread::get_id() << endl;
	boost::this_thread::sleep(boost::posix_time::seconds(2));
	cout << "func call" << endl;
}
int main(){

	boost::thread t(&fun);
	t.join();
}

