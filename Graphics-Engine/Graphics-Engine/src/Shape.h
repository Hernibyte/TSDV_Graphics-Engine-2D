#ifndef SHAPE_H
#define SHAPE_H

#include "Entity2D.h"

class Shape : public Entity2D {
public:
	Shape(Renderer& renderer);

	void ChangeColor(float r, float g, float b);

	void ChangeAlpha(float alpha);

	void Draw();

private:
	float vertex[28] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};
};

#endif // !SHAPE_H
