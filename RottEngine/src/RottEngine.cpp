#include "RottEngine.hpp"

void RottEngine::init(const char* title, int w, int h) {
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO)>0) {
		Logger::printSDLerror("Couldn't initialize SDL");
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		Logger::printSDL_IMGerror("Couldn't initialize SDL_image");
	}

	if (TTF_Init()==-1) {
		Logger::printSDL_TTFerror("Couldn't initialize SDL_TTF");
	}

	RenderWindow::init(title, w, h);
}

void RottEngine::startFrame() {
	RenderWindow::pollEvents();
	RenderWindow::clear();
}

void RottEngine::endFrame() {
	RenderWindow::display();
	Time::update();
}

void RottEngine::renderRect(const SDL_Rect& rect, const SDL_Color& color) {
	// Store the previous render color.
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(RenderWindow::getRenderer(), &r, &g, &b, &a);
	
	SDL_SetRenderDrawColor(RenderWindow::getRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(RenderWindow::getRenderer(), &rect);
	
	// Set the render color to the previous one.
	SDL_SetRenderDrawColor(RenderWindow::getRenderer(), r, g, b, a);
}

void RottEngine::terminate() {
	World::terminate();
	RenderWindow::cleanUp();
	SDL_Quit();
}