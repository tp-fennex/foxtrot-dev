#include "Server.hpp"

#include "Client.hpp"

#include <iostream>
#include <boost/make_shared.hpp>

namespace fxt {


using namespace boost::asio::ip;


Server::Server() :
        m_endpoint(tcp::v4(), 6666),
        m_acceptor(m_io_context, m_endpoint) {
    do_accept();
}


Server &Server::get_instance() {
    static Server server_instance;
    return server_instance;
}


void Server::run() {
    m_io_context.run();
}


void Server::do_accept() {
    m_acceptor.async_accept(
            [this](const boost::system::error_code &ec, tcp::socket socket) {
                if (!ec) {
                    std::cout << "Connection accepted" << "\n";
                    boost::make_shared<Client>(std::move(socket))->do_connect();
                }

                do_accept();
            });
}


//boost::uuids::uuid Server::create_session(size_t session_capacity)
//{
//    boost::uuids::uuid session_id = m_uuid_gen();
//    m_sessions.emplace(session_id, session_capacity);
//    return session_id;
//}

}