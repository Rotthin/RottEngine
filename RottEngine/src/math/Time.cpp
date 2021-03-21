#include "Time.hpp"
#include <SDL.h>

Uint64 Time::m_lastFrame=0;
double Time::m_deltaTime=0;

void Time::update() {
	Uint64 now = SDL_GetPerformanceCounter();
	if (m_lastFrame) {
		m_deltaTime = (double) ((now-m_lastFrame)/(double) SDL_GetPerformanceFrequency());
	}
	m_lastFrame = now;
}

double Time::getDelta(){
	return m_deltaTime;
}