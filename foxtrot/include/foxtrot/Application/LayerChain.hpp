#ifndef FOXTROT_LAYER_CHAIN_HPP
#define FOXTROT_LAYER_CHAIN_HPP


#include <deque>
#include <foxtrot/Application/ILayer.hpp>


namespace fxt
{

class LayerChain
{
public:
    ~LayerChain();

    bool update_layers(const Event& event);
    void render_layers(IWindow& window);

    void push_back(ILayer* layer);
    void push_front(ILayer* layer);

private:
    Event m_event;
    std::deque<ILayer*> m_layers;
};

} // namespace fxt

#endif // FOXTROT_LAYER_CHAIN_HPP
