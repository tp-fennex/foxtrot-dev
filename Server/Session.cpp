#include "Session.hpp"

namespace fxt {

/**
 * here should be implemented logic of calling ping
 * from clients to sync game start
 */
void Session::start_session() {

}

/*!
 * \brief Adding client to the session
 * @param client - client to add to the session
 * Maybe better to implement move semantics here
 */
void Session::add_client(Client &client) {
    m_clients.insert(client);
}


bool Session::ready() {
    if (m_clients.size() == m_session_capacity) {
        return true;
    }
    return false;
}

}