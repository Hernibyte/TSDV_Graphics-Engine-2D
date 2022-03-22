#ifndef BASEGAME_H
#define BASEGAME_H

#include "Sprite.h"

class Basegame {
public:
	Basegame();
	Basegame(int width, int height, const char* tittle);

	void Run();
protected:
	~Basegame() = default;
	
	Window window;
	Renderer render;

	virtual void Start() {}
	virtual void Update() {}
private:

	void Core_Start();
	void Core_Update();
	void Core_Sleep();
};

#endif // !BASEGAME_H
