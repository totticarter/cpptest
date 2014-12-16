#include "log3.h"

void InitLog()
{
    logging::formatter formatter=
	expr::format("[%1%]<%2%>(%3%): %4%")
	% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
	%expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
	%expr::attr< SeverityLevel >("Severity")
	%expr::message;

	logging::add_common_attributes();

    auto console_sink=logging::add_console_log();
    auto file_sink=logging::add_file_log
        (
        keywords::file_name="%Y-%m-%d_%N.log",      //�ļ���
        keywords::rotation_size=10*1024*1024,       //�����ļ����ƴ�С
        keywords::time_based_rotation=sinks::file::rotation_at_time_point(0,0,0)    //ÿ���ؽ�
        );

    file_sink->locked_backend()->set_file_collector(sinks::file::make_collector(
        keywords::target="logs",        //�ļ�����
        keywords::max_size=20*1024*1024,    //�ļ�����ռ���ռ�
        keywords::min_free_space=100*1024*1024  //������СԤ���ռ�
        ));

    file_sink->set_filter(log_severity>=info);   //��־�������

    file_sink->locked_backend()->scan_for_files();

    console_sink->set_formatter(formatter);
    file_sink->set_formatter(formatter);
    file_sink->locked_backend()->auto_flush(true);

    logging::core::get()->add_global_attribute("Scope",attrs::named_scope());
    //logging::core::get()->add_sink(console_sink);
    logging::core::get()->add_sink(file_sink);
}
