#ifndef SERVER_HPP
#define SERVER_HPP


#include <foxtrot/Session/Session.hpp>

#include <map>
#include <vector>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <boost/thread/mutex.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

#include <foxtrot/WorkerPool/WorkerPool.hpp>


namespace fxt
{

using boost::asio::ip::tcp;

class Server
{
public:
    ~Server() = default; //TODO

    static Server &get_instance();

    void run();

    boost::uuids::uuid create_session(size_t session_capacity);

private:

    boost::asio::io_context m_io_context;

    tcp::endpoint m_endpoint;
    tcp::acceptor m_acceptor;

    boost::uuids::random_generator m_uuid_gen;    /*! \brief session key */

    std::map<boost::uuids::uuid, Session> m_sessions;

    WorkerPool m_worker_pool;

private:
    Server();

    void do_accept();

};

}

#endif // SERVER_HPP