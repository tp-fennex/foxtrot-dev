#include <foxtrot/Application/LayerChain.hpp>


namespace fxt
{

LayerChain::~LayerChain()
{
    for(auto layer : m_layers)
    {
        delete layer;
    }
}


bool LayerChain::update_layers(const Event& event)
{
    for(auto layer : m_layers)
    {
        if(layer->handle_event(event))
        {
            return true;
        }
    }

    return false;
}


void LayerChain::render_layers(IWindow& window)
{
    for(auto layer = m_layers.rbegin(); layer != m_layers.rend(); ++layer)
    {
        (*layer)->render(window);
    }
}


void LayerChain::push_back(ILayer* layer)
{
    m_layers.emplace_back(std::move(layer));
}


void LayerChain::push_front(ILayer* layer)
{
    m_layers.emplace_front(std::move(layer));
}

} // namespace fxt
