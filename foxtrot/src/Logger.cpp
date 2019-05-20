#include "foxtrot/Logger.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace fxt
{

std::shared_ptr<spdlog::logger> Logger::s_core_logger(spdlog::stdout_color_mt("Engine"));
std::shared_ptr<spdlog::logger> Logger::s_client_logger(spdlog::stdout_color_mt("Application"));


void Logger::init()
{
    // Logging format: <color_esc>[<timestamp>] <log_name>: <log_message>
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_core_logger->set_level(spdlog::level::trace);
    s_client_logger->set_level(spdlog::level::trace);

    LOGGER_CORE_INFO("Logger initialized.");
}


std::shared_ptr<spdlog::logger>& Logger::get_core_logger()
{
    return s_core_logger;
}


std::shared_ptr<spdlog::logger>& Logger::get_client_logger()
{
    return s_client_logger;
}

} // namespace fxt
