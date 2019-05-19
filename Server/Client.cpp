#include "Client.hpp"
#include "Server.hpp"

#include <iostream>
#include <boost/asio.hpp>

namespace fxt
{

void Client::do_connect()
{
    std::cout << "Connect packet received. " << &m_socket << "\n";

    auto self(shared_from_this());

    async_read(
        m_socket,
        boost::asio::buffer(m_buffer, max_msg_len),
        boost::asio::transfer_at_least(1), //FOR TEST PURPOSE
        [this, self](const boost::system::error_code ec, std::size_t)
        {
            if (!ec)
            {
                std::cout << m_buffer << "\n";
            }
            else
            {
                std::cout << "Error occurred: " << ec.message() << "\n";
            }

            do_connect();
        });
}

}