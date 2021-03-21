#pragma once
#include <SDL.h>
#include "Entity.hpp"
#include "math/Vector2.hpp"

class RenderWindow {
public:
	/// <summary> Creates window with specified values. </summary>
	static void init(const char* title, int w, int h);

	/// <summary> Clears the window. </summary>
	static void clear();

	/// <summary> Displays the buffer. </summary>
	static void display();

	/// <summary> Destroys the renderer and window. </summary>
	static void cleanUp();

	/// <summary> Polls events. </summary>
	static void pollEvents();

	/// <summary> Sets the clear color to the specified value. </summary>
	static void setClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	/// <summary> Returns the m_running value. </summary>
	static bool getIsRunning();

	/// <summary> Returns the width of this window. </summary>
	static int getWidth();
	
	/// <summary> Returns the height of this window. </summary>
	static int getHeight();
	
	/// <summary> Returns the SDL_Window. </summary>
	static SDL_Window* getWindow();

	/// <summary> Returns the SDL_Renderer. </summary>
	static SDL_Renderer* getRenderer();

private:
	RenderWindow();

private:
	static bool m_running;
	static int m_width, m_height;

	static SDL_Window* mp_window;
	static SDL_Renderer* mp_renderer;
	static SDL_Event m_event;
	static SDL_Color m_clearColor;
};

