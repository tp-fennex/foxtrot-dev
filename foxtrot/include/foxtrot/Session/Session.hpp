#ifndef SESSION_HPP
#define SESSIN_HPP


#include <set>

#include <foxtrot/Client/Client.hpp>


namespace fxt
{

class Session
{
public:
    explicit Session(size_t _session_capacity) :
            m_session_capacity(_session_capacity) {};

    ~Session() = default;

private:
    std::set<Client> m_clients;

    size_t m_session_capacity;

private:
    void add_client(Client &&client);

    bool ready();

    void start_session();
};

}

#endif // SESSION_HPP