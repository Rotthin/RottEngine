#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL.h>
#include "RenderWindow.hpp"
#include "Logger.hpp"
#include "math/Time.hpp"
#include "World.hpp"

namespace RottEngine {
	/// <summary> Inits the RenderWindow, SDL, SDL_IMG and SDL_TTF. </summary>
	void init(const char* title, int w, int h);

	/// <summary> Renders specified rect with specified color. </summary>
	void renderRect(const SDL_Rect& rect, const SDL_Color& color);

	/// <summary> Cleans up the window, calls World::terminate and quits SDL. </summary>
	void terminate();

	/// <summary> Call this on the start of your game loop. NOTE: Calls RenderWindow::clear 
	/// and RenderWindow::pollEvents. </summary>
	void startFrame();

	/// <summary> Call this on the end of your game loop. NOTE: Calls RenderWindow::display 
	/// and Time::Update. </summary>
	void endFrame();
}