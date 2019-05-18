#ifndef SERVER_HPP
#define SERVER_HPP

#include "Session.hpp"

#include <map>
#include <vector>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>


namespace fxt
{

class Server
{
public:
    ~Server() = default;

    static Server &get_instance();

    void run();

//    boost::uuids::uuid create_session(size_t session_capacity);

private:
    boost::mutex m_mutex;   /*! \brief lock work queue */

    boost::asio::io_context m_io_context;

    tcp::endpoint m_endpoint;
    tcp::acceptor m_acceptor;

    boost::uuids::random_generator m_uuid_gen;    /*! \brief session key */

    std::map<boost::uuids::uuid, Session> m_sessions;

private:
    Server();

    void do_accept();

};

}

#endif // SERVER_HPP