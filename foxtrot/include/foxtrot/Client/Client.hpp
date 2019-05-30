#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <queue>
#include <string>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>


namespace fxt
{

using boost::asio::ip::tcp;

class Client : public boost::enable_shared_from_this<Client>, boost::asio::noncopyable
{
public:

    explicit Client(tcp::socket socket) :  m_buffer{0}, m_socket(std::move(socket))
    {
        std::cout << "Client constructed with ip: " << m_socket.remote_endpoint().address().to_string() << "\n";
    }

    Client(Client &&client) noexcept :  m_buffer{0}, m_socket(std::move(client.m_socket)) {}

    ~Client() = default;

    bool operator<(const Client &r_client) const
    {
        return &m_socket < &r_client.m_socket;
    }

    void do_connect();

private:

    enum
    {
        max_msg_len = 1024
    };

    char m_buffer[max_msg_len];

    tcp::socket m_socket;

};

}

#endif // CLIENT_HPP