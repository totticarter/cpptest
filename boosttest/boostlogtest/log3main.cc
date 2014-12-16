#include"log3.h"

int main(){

	InitLog();
	src::severity_logger<SeverityLevel> slg;
	logging::core::get()->add_global_attribute("Scope",attrs::named_scope());
	
	for(int i = 0; i< 10000000; i++){
		BOOST_LOG_SEV(slg, info) << "info";
	}	

}
