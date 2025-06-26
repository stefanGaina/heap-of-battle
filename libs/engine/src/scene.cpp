#include "scene.hpp"
#include "application_interface.hpp"

namespace hob::engine
{

scene::scene(application_interface& app_interface, asset_manager& assets)
	: assets{ assets }
	, app_interface{ app_interface }
	, children{}
{
}

scene::~scene() noexcept = default;

void scene::handle_event(const sf::Event& event)
{
	for (const std::unique_ptr<scene>& child : children)
	{
		child->handle_event(event);
	}

	event.visit([this](auto&& event)
	{
		on_event(event);
	});
}

void scene::update(const float delta_time)
{
	for (const std::unique_ptr<scene>& child : children)
	{
		child->update(delta_time);
	}

	on_update(delta_time);
}

void scene::on_event(const sf::Event::Closed& event)
{
	(void)event;
	app_interface.stop();
}

void scene::on_event(const sf::Event::Resized& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::FocusLost& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::FocusGained& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::TextEntered& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::KeyPressed& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::KeyReleased& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseWheelScrolled& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseButtonPressed& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseButtonReleased& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseMoved& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseMovedRaw& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseEntered& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::MouseLeft& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::JoystickButtonPressed& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::JoystickButtonReleased& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::JoystickMoved& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::JoystickConnected& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::JoystickDisconnected& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::TouchBegan& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::TouchMoved& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::TouchEnded& event)
{
	(void)event;
}

void scene::on_event(const sf::Event::SensorChanged& event)
{
	(void)event;
}

void scene::on_update(const float delta_time)
{
	(void)delta_time;
}

} // namespace hob::engine

