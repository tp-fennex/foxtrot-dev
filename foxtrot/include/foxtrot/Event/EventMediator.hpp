#ifndef FOXTROT_EVENT_MEDIATOR_HPP
#define FOXTROT_EVENT_MEDIATOR_HPP


#include "foxtrot/Event/Event.hpp"


namespace fxt
{

class EventMediator
{
public:
    virtual ~EventMediator() = default;

    virtual bool produce(Event& event) = 0;
};

} // namespace fxt

#endif // FOXTROT_EVENT_MEDIATOR_HPP
