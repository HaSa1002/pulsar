#pragma once

#include "core/server/event.hpp"
#include "events.hpp"
#include <vector>
#include <SDL_events.h>

class Input;

/// Input provider take system input and convert them into pulsar input.
/// The behaviour is specialised in child classes for different input provider.
/// You can specify as many input filters as you wish. See Input for an explanation
///
/// Input provider are also responsible to distribute the raw pulsar events.
class InputProvider {
	std::vector<Input*> input_filters;
public:

	void registerInputFilter(Input* inputFilter);

protected:
	void pushEvent(const InputEvent& event);
};

/// Parses SDL events and feeds them into the pulsar input system.
class InputProviderSDL : public InputProvider {
public:
	void consumeEvent(SDL_Event& sdlEvent);

	bool canConsumeEvent(SDL_Event& sdlEvent);
};

/// Input is essentially a filtering class that parses input events and matches
/// them with actions. Actions are strings that map any number of input events together.
/// Actions can be pressed, held, and released.
/// TODO: There is a design flaw! I want to be able to have multiplayer/user action support.
/// TODO: If player based actions are used, they should have the same name across all players.
/// TODO: However, it should be still possible to query if the action is pressed by any player.
/// TODO: For example like this: action_name/player and action_name
/// TODO: However, this doesn't work with multiple input filters, so the support needs to be built into it
/// TODO: Still, using multiple input filter may be valid?
class Input {
public:
	Input() = default;
	~Input() = default;

	/// Parses the event with the actions
	void pushEvent(const InputEvent& event);

	/// Updates the action states (Pressed -> Held and Released -> Unpressed)
	/// Should probably be private and only called by an input provider or main loop
	void next_frame();



public:
	pulsar::Event<void> eventArrived;

private:
};


