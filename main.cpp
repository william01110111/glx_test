#include <unistd.h>
#include <iostream>
 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "TexRenderer.h"
#include "GLXContextManager.h"

int main (int argc, char ** argv)
{
    auto manager = GLXContextManager();
    
    auto renderer = TexRenderer();
    
    renderer.setup(100, 100);
    
    renderer.draw();
    
    manager.swapBuffer();
    
    sleep(4);
    
	/*
	glClearColor (0, 0.5, 1, 1);
	glClear (GL_COLOR_BUFFER_BIT);
	glXSwapBuffers (display, win);
	
	sleep(1);
	
	glClearColor (1, 0.5, 0, 1);
	glClear (GL_COLOR_BUFFER_BIT);
	glXSwapBuffers (display, win);
	
	sleep(1);
	*/
}