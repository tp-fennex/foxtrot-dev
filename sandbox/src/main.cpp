#include "foxtrot/Event/EventManager.hpp"


int main()
{
    fxt::EventManager manager;
    manager.init_network_worker();

    while(true) ;
    return 0;
}
