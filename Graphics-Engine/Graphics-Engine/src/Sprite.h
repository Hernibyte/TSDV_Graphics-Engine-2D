#ifndef SPRITE_H
#define SPRITE_H

#include "Shape.h"

class Sprite : public Entity2D {
public:
	Sprite(Renderer& renderer);

	void ImportTexture(const char* filePath, TextureType type);

	void ChangeColor(float r, float g, float b);

	void ChangeAlpha(float alpha);

	void Draw();

private:
	float vertex[36] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};
	Texture texture{};
};

#endif // !SPRITE_H
