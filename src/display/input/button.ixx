export module synodic.soul.engine:display.input.button;

import std;

export enum class ButtonState { PRESS, REPEAT, RELEASE, OPEN };

export class Button {

public:

	Button();

	float timeToRepeat; //in milliseconds
	std::chrono::steady_clock::time_point sincePress;

	ButtonState state;

};

inline Button::Button():
	timeToRepeat(50.0f),
	state(ButtonState::OPEN)
{
}
