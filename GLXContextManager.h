#pragma once

#include <GL/glx.h>
#include <GL/gl.h>

class GLXContextManager
{
	public:
	GLXContextManager();
	~GLXContextManager();
	
	void swapBuffer();
	
	//private:
	Display * display = nullptr;
	GLXContext ctx;
	Window win;
};

