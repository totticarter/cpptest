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
        keywords::file_name="%Y-%m-%d_%N.log",      //文件名
        keywords::rotation_size=10*1024*1024,       //单个文件限制大小
        keywords::time_based_rotation=sinks::file::rotation_at_time_point(0,0,0)    //每天重建
        );

    file_sink->locked_backend()->set_file_collector(sinks::file::make_collector(
        keywords::target="logs",        //文件夹名
        keywords::max_size=20*1024*1024,    //文件夹所占最大空间
        keywords::min_free_space=100*1024*1024  //磁盘最小预留空间
        ));

    file_sink->set_filter(log_severity>=info);   //日志级别过滤

    file_sink->locked_backend()->scan_for_files();

    console_sink->set_formatter(formatter);
    file_sink->set_formatter(formatter);
    file_sink->locked_backend()->auto_flush(true);

    logging::core::get()->add_global_attribute("Scope",attrs::named_scope());
    //logging::core::get()->add_sink(console_sink);
    logging::core::get()->add_sink(file_sink);
}
