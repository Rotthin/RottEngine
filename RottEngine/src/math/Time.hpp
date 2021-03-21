#pragma once

#include <chrono>
#include <SDL/SDL_stdinc.h>

class Time {
public:
	/// <summary> Returns time between last frame and this frame. </summary>
	static double getDelta();

	/// <summary> Calculates the delta. </summary>
	static void update();

private:
	Time() {}

private:
	static Uint64 m_lastFrame;
	static double m_deltaTime;
};