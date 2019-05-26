#ifndef FOXTROT_EVENT_HPP
#define FOXTROT_EVENT_HPP


#include <ostream>


namespace fxt
{

struct Event
{
    struct SizeEvent
    {
        uint width;
        uint height;
    };

    struct KeyEvent
    {
        int code;
    };

    struct ConnectionEvent
    {
        char address[16];
        unsigned short port;
    };

    enum EventType
    {
        NONE = -1,
        WINDOW_CLOSED = 0,
        WINDOW_RESIZED,
        KEY_PRESSED,
        KEY_RELEASED,
        NETWORK_CONNECT,
        NETWORK_SUCCESS,
        NETWORK_FAILED,
        NETWORK_DISCONNECT,
        WORKER_TERMINATE,
    };

    EventType type;

    union
    {
        SizeEvent size;
        KeyEvent key;
        ConnectionEvent connection;
    };
};


inline std::ostream& operator<<(std::ostream& os, const Event& event)
{
    return os << "Event (" << event.type << ')';
}

} // namespace fxt

#endif // FOXTROT_EVENT_HPP
