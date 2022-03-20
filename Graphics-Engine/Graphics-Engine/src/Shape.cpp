#include "Shape.h"

Shape::Shape(Renderer& renderer) : Entity2D(renderer) {

}

void Shape::ChangeColor(float r, float g, float b) {
	vertex[3] = r;
	vertex[10] = r;
	vertex[17] = r;
	vertex[24] = r;

	vertex[4] = g;
	vertex[11] = g;
	vertex[18] = g;
	vertex[25] = g;

	vertex[5] = b;
	vertex[12] = b;
	vertex[19] = b;
	vertex[26] = b;
}

void Shape::ChangeAlpha(float alpha) {
	vertex[6] = alpha;
	vertex[13] = alpha;
	vertex[20] = alpha;
	vertex[27] = alpha;
}

void Shape::Draw() {
	render->Draw(vertex, index, transform.Model(), 0);
}