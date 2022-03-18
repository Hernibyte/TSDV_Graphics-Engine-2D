#ifndef BASEGAME_H
#define BASEGAME_H

#include "Window.h"

class Basegame {
public:
	Basegame();
	Basegame(int width, int height, const char* tittle);

	void Run();
protected:
	~Basegame() = default;

	virtual void Start() {}
	virtual void Update() {}
private:
	Window window;

	void Core_Start();
	void Core_Update();
	void Core_Sleep();
};

#endif // !BASEGAME_H
