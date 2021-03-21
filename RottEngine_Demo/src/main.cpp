#include "RottEngine.hpp"
#include "AssetManager.hpp"
#include "Input.hpp"
#include "World.hpp"
#include "Definitions.hpp"
#include "ui/UILabel.hpp"

#include <sstream>
#include <iomanip>

int main(int argc, char* args[]) {
	RottEngine::init("RottEngine DEMO - Breathing Timer", WIDTH, HEIGHT);

	AssetManager::addFont(RenderWindow::getRenderer(), "InputMono", 24);

	UILabel* fpsLabel = new UILabel(RenderWindow::getRenderer(), HALF_WIDTH, HALF_HEIGHT, "0", "InputMono", LABEL_FLAGS_ALIGN_CENTER | LABEL_FLAGS_QUALITY_BEST);
	World::addUiEntity("fps_label", fpsLabel);

	float i = 0;
	while (RenderWindow::getIsRunning()) {
		RottEngine::startFrame();

		i += Time::getDelta();
		fpsLabel->setText(std::to_string(i) + "s");
		fpsLabel->setScale({cosf(i) + 2, sinf(i) + 2});

		World::render();
		
		RottEngine::endFrame();
	}

	RottEngine::terminate();
	return 0;
}