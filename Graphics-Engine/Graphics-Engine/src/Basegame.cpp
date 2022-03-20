#include "Basegame.h"

Basegame::Basegame() {
	window.Width(800);
	window.Height(800);
	window.Tittle("Window");

	render = Renderer();
}

Basegame::Basegame(int width, int height, const char* tittle) {
	window.Width(width);
	window.Height(height);
	window.Tittle(tittle);

	render = Renderer();
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
	ShaderSource shaderSource = Renderer::ParceShader("src/StandardShader/StandardShader.glsl");
	render.CreateProgram(shaderSource.Vertex, shaderSource.Fragment);
	render.GenerateBuffers();
	render.BindBuffers();
	render.VertexAttributes();
	render.GetUniformsLocation();
}

void Basegame::Core_Update() {

}

void Basegame::Core_Sleep() {

}
