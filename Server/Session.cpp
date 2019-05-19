#include "Session.hpp"

namespace fxt {

/**
 * here should be implemented logic of calling ping
 * from clients to sync game start
 */
void Session::start_session() {

}


//void Session::add_client(Client &client) {
////    m_clients.emplace(//move semantics for client);
//}


bool Session::ready() {
    if (m_clients.size() == m_session_capacity) {
        return true;
    }
    return false;
}

}