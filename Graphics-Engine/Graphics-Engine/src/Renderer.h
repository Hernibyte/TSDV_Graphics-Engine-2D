#ifndef RENDERER_H
#define RENDERER_H

#include "Window.h"
#include "ShaderSource.h"
#include "Transform.h"
#include <fstream>
#include <sstream>

class Renderer {
public:
	Renderer();
	~Renderer();

	void GenerateBuffers();

	void BindBuffers();

	void ClearBuffers();

	void VertexAttributes();

	void GetUniformsLocation();

	static ShaderSource ParceShader(const std::string_view filepath);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	
	void Draw(float* vertex, unsigned int* index, glm::mat4 model, int type);
private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
	
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int program;

	unsigned int modelLocation;
	//unsigned int typeLocation;
};

#endif // !RENDERER_H
