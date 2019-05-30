#include <foxtrot/Client/Client.hpp>


namespace fxt
{

void Client::do_read_header()
{
    auto self(shared_from_this());
    async_read(
        m_socket,
        boost::asio::buffer(m_buffer, max_msg_len),
        boost::asio::transfer_exactly(sizeof(uint32_t)),
        [this, self](const boost::system::error_code ec, std::size_t)
        {
            if (!ec)
            {
                LOGGER_CORE_TRACE("Packet header read");
                m_packet_header.ParseFromArray(m_buffer, max_msg_len);
                uint32_t packet_size = static_cast<uint32_t>(*m_buffer);

                if (packet_size > max_msg_len)
                {
                    LOGGER_CORE_ERROR("Got corrupt header");
                    do_read_header();
                }

                do_read_packet(packet_size);
            }
            else
            {
                LOGGER_CORE_ERROR("Error reading header");
            }
        });
}


void Client::do_read_packet(uint32_t packet_size)
{
    auto self(shared_from_this());

    async_read(
            m_socket,
            boost::asio::buffer(m_buffer, max_msg_len),
            boost::asio::transfer_exactly(packet_size),
            [this, self](const boost::system::error_code ec, std::size_t)
            {
                if (!ec)
                {
                    //TODO: probably move parse to worker job
                    m_event.ParseFromArray(m_buffer, max_msg_len);
                }
                else
                {
                    LOGGER_CORE_ERROR("Error reading packet {0}", ec.message());
                }

                do_read_header();
            });
}


void Client::process_events()
{
    //TODO: apply events such as move, go to the Session etc.
}

}