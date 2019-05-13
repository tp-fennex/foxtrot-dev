#ifndef FOXTROT_LOGGER_HPP
#define FOXTROT_LOGGER_HPP

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace fxt
{

class Logger
{
public:
    static void init();

    static std::shared_ptr<spdlog::logger>& get_core_logger();
    static std::shared_ptr<spdlog::logger>& get_client_logger();

private:
    static std::shared_ptr<spdlog::logger> s_core_logger;
    static std::shared_ptr<spdlog::logger> s_client_logger;
};

} // namespace fxt

// Core logging macros
#define LOGGER_CORE_TRACE(...)    ::fxt::Logger::get_core_logger()->trace(__VA_ARGS__)
#define LOGGER_CORE_DEBUG(...)    ::fxt::Logger::get_core_logger()->debug(__VA_ARGS__)
#define LOGGER_CORE_INFO(...)     ::fxt::Logger::get_core_logger()->info(__VA_ARGS__)
#define LOGGER_CORE_WARN(...)     ::fxt::Logger::get_core_logger()->warn(__VA_ARGS__)
#define LOGGER_CORE_ERROR(...)    ::fxt::Logger::get_core_logger()->error(__VA_ARGS__)
#define LOGGER_CORE_CRITICAL(...) ::fxt::Logger::get_core_logger()->critical(__VA_ARGS__)

// Client logging macros
#define LOGGER_TRACE(...)    ::fxt::Logger::get_client_logger()->trace(__VA_ARGS__)
#define LOGGER_DEBUG(...)    ::fxt::Logger::get_client_logger()->debug(__VA_ARGS__)
#define LOGGER_INFO(...)     ::fxt::Logger::get_client_logger()->info(__VA_ARGS__)
#define LOGGER_WARN(...)     ::fxt::Logger::get_client_logger()->warn(__VA_ARGS__)
#define LOGGER_ERROR(...)    ::fxt::Logger::get_client_logger()->error(__VA_ARGS__)
#define LOGGER_CRITICAL(...) ::fxt::Logger::get_client_logger()->critical(__VA_ARGS__)

#endif // FOXTROT_LOGGER_HPP
