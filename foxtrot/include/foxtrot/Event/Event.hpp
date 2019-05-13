#ifndef FOXTROT_EVENT_HPP
#define FOXTROT_EVENT_HPP


#include <ostream>


namespace fxt
{

struct Event
{
    struct Test1Event
    {
        int message;
    };

    struct Test2Event
    {
        float x;
        float y;
    };

    enum EventType
    {
        Test1,
        Test2,
    };

    EventType type;

    union
    {
        Test1Event test1;
        Test2Event test2;
    };
};


inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
    return os << "Event of type:" << e.type;
}

} // namespace fxt

#endif // FOXTROT_EVENT_HPP
