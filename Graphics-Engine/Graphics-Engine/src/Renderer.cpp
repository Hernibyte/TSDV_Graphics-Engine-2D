#include "Renderer.h"

Renderer::Renderer() {
	program = 0;
	vao = 0;
	vbo = 0;
	ebo = 0;

	modelLocation = 0;
	//typeLocation = 0;
}

Renderer::~Renderer() {
	ClearBuffers();
}

void Renderer::GenerateBuffers() {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

void Renderer::BindBuffers() {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}

void Renderer::ClearBuffers() {
	glClearBufferData(GL_ARRAY_BUFFER, GL_RGB32F, GL_RGB, GL_FLOAT, &vbo);
	glClearBufferData(GL_ELEMENT_ARRAY_BUFFER, GL_RGBA8, GL_RGB, GL_UNSIGNED_INT, &ebo);
}

void Renderer::VertexAttributes() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
	//glEnableVertexAttribArray(2);
}

void Renderer::GetUniformsLocation() {
	modelLocation = glGetUniformLocation(program, "model");
	//typeLocation = glGetUniformLocation(program, "type");
}

void Renderer::Draw(float* vertex, unsigned int* index, glm::mat4 model, int type) {
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glBufferData(GL_ARRAY_BUFFER,
		28 * sizeof(vertex), vertex,
		GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		6 * sizeof(index), index,
		GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

ShaderSource Renderer::ParceShader(const std::string_view filepath) {
	std::ifstream stream(filepath.data());

	enum class ShaderType {
		NONE = -1,
		VERTEX,
		FRAGMENT
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (std::getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
			ss[(int)type] << line << '\n';
	}

	return {
		ss[0].str(),
		ss[1].str()
	};
}

unsigned int Renderer::CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	//
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	//
	return id;
}

void Renderer::CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
	program = glCreateProgram();
	unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);
	glUseProgram(program);

	glDetachShader(program, vertex);
	glDetachShader(program, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}