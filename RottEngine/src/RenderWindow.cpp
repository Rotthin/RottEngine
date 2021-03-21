#include <SDL/SDL_image.h>

#include "RenderWindow.hpp"
#include "Logger.hpp"
#include "Input.hpp"

bool RenderWindow::m_running = false;
int RenderWindow::m_width, RenderWindow::m_height;

SDL_Window* RenderWindow::mp_window;
SDL_Renderer* RenderWindow::mp_renderer;
SDL_Event RenderWindow::m_event;
SDL_Color RenderWindow::m_clearColor;

void RenderWindow::init(const char* title, int w, int h) {
	m_running = true;
	m_width = w;
	m_height = h;
	m_clearColor = {0, 0, 0, 255};

	// Create the window.
	mp_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, NULL);
	if (!mp_window) {
		Logger::printSDLerror("Couldn't create window");
		m_running = false;
	}

	// Create the renderer.
	mp_renderer = SDL_CreateRenderer(mp_window, -1, SDL_RENDERER_ACCELERATED);
	if (!mp_window) {
		Logger::printSDLerror("Couldn't create renderer");
		m_running = false;
	}
}

void RenderWindow::pollEvents() {
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type) {
		case SDL_QUIT:
			m_running = false;
			break;

		case SDL_KEYDOWN:
			Input::setKeyState(m_event.key.keysym.sym, true);
			break;

		case SDL_KEYUP:
			Input::setKeyState(m_event.key.keysym.sym, false);
			break;
		}
	}
}

void RenderWindow::clear() {
	// Store the previous render colors.
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(mp_renderer, &r, &g, &b, &a);
	
	// Clear and set the render color back to the previous.
	SDL_RenderClear(mp_renderer);
	SDL_SetRenderDrawColor(mp_renderer, r,g,b,a);
}

void RenderWindow::display() {
	SDL_RenderPresent(mp_renderer);
}

void RenderWindow::cleanUp() {
	SDL_DestroyRenderer(mp_renderer);
	SDL_DestroyWindow(mp_window);
}

void RenderWindow::setClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	m_clearColor = {r, g, b, a};
}

bool RenderWindow::getIsRunning()					{ return m_running; }

int RenderWindow::getWidth()					{ return m_width; }

int RenderWindow::getHeight()					{ return m_height; }

SDL_Renderer* RenderWindow::getRenderer()		{ return mp_renderer; }

SDL_Window* RenderWindow::getWindow()			{ return mp_window; }
