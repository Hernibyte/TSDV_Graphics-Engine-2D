#include "Basegame.h"

Basegame::Basegame() {
	window.Width(800);
	window.Height(800);
	window.Tittle("Window");
}

Basegame::Basegame(int width, int height, const char* tittle) {
	window.Width(width);
	window.Height(height);
	window.Tittle(tittle);
}

void Basegame::Run() {
	Core_Start();
	Start();

	while (!window.IsWindowShouldClose()) {
		window.Clear(0, 0, 0, 0);

		Core_Update();
		Update();

		window.Refresh();
	}

	Core_Sleep();
}

void Basegame::Core_Start() {

}

void Basegame::Core_Update() {

}

void Basegame::Core_Sleep() {

}