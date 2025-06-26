////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////
/// HEADER FILE INCLUDES
////////////////////////////////////////////////////////////

#include <vector>
#include <forward_list>
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

////////////////////////////////////////////////////////////
/// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////

namespace hob::engine
{

class asset_manager;
class application_interface;

////////////////////////////////////////////////////////////
/// TYPE DEFINITIONS
////////////////////////////////////////////////////////////

using drawable_reference = std::reference_wrapper<sf::Drawable>;

using drawable_list = std::forward_list<drawable_reference>;

class scene
{
public:
	scene(application_interface& app_interface, asset_manager& assets);

	virtual ~scene() noexcept;

	void handle_event(const sf::Event& event);

	void update(float delta_time);

	virtual drawable_list get_drawables() = 0;

protected:
	application_interface& app_interface;

	asset_manager& assets;

	std::vector<std::unique_ptr<scene>> children;

private:
	virtual void on_event(const sf::Event::Closed& event);

	virtual void on_event(const sf::Event::Resized& event);

	virtual void on_event(const sf::Event::FocusLost& event);

	virtual void on_event(const sf::Event::FocusGained& event);

	virtual void on_event(const sf::Event::TextEntered& event);

	virtual void on_event(const sf::Event::KeyPressed& event);

	virtual void on_event(const sf::Event::KeyReleased& event);

	virtual void on_event(const sf::Event::MouseWheelScrolled& event);

	virtual void on_event(const sf::Event::MouseButtonPressed& event);

	virtual void on_event(const sf::Event::MouseButtonReleased& event);

	virtual void on_event(const sf::Event::MouseMoved& event);

	virtual void on_event(const sf::Event::MouseMovedRaw& event);

	virtual void on_event(const sf::Event::MouseEntered& event);

	virtual void on_event(const sf::Event::MouseLeft& event);

	virtual void on_event(const sf::Event::JoystickButtonPressed& event);

	virtual void on_event(const sf::Event::JoystickButtonReleased& event);

	virtual void on_event(const sf::Event::JoystickMoved& event);

	virtual void on_event(const sf::Event::JoystickConnected& event);

	virtual void on_event(const sf::Event::JoystickDisconnected& event);

	virtual void on_event(const sf::Event::TouchBegan& event);

	virtual void on_event(const sf::Event::TouchMoved& event);

	virtual void on_event(const sf::Event::TouchEnded& event);

	virtual void on_event(const sf::Event::SensorChanged& event);

	virtual void on_update(float delta_time);
};

////////////////////////////////////////////////////////////
/// FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////

extern "C" scene* create_scene(application_interface& app_interface, asset_manager& assets);

} // namespace hob::engine

