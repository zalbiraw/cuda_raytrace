
// Describes the canvas (for displaying results) in the raytracer system

#ifndef _h_canvas
#define _h_canvas

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <string.h>

#include "color.h"

#define MESSAGE_FONT GLUT_BITMAP_TIMES_ROMAN_10
#define FONT_HEIGHT 10

#define WINDOW_TITLE_BUFFER 256
#define MESSAGE_BUFFER 512
#define DEFAULT_REDRAW_DELAY 100
#define DEFAULT_WINDOW_X 50
#define DEFAULT_WINDOW_Y 50

// Defines a canvas
typedef struct canvas_t {
	unsigned int height;                   // Pixel height of canvas
	unsigned int width;                    // Pixel width of canvas
	COLOR * pixels;                        // Actual pixel data
	char window_name[WINDOW_TITLE_BUFFER]; // Name of canvas window
	char message[MESSAGE_BUFFER];          // Buffer for message to be rendered
	void (* animate)();                     // Function to animate canvas
	unsigned int delay;                    // Delay between redraws
} canvas_t;

/**********************
* Creates a new canvas
* NOTE: must be freed with Canvas_free()
* @param width        Width of the opengl window
* @param height       Height of the opengl window
* @param window_title Name of the opengl window
**********************/
canvas_t * Canvas_create (int height, int width, char * window_name);

/***********************
* Sets the pixel at the current location to the specified value
* @param x x-coordinate of the pixel to set
* @param y y-coordinate of the pixel to set
* @param r red value of the pixel
* @param g freen value of the pixel
* @param b blue value of the pixel
***********************/
void Canvas_setPixel(int x, int y, int r, int g, int b);

/**********************
* Set the loop function for the canvas.
* The specified function will be called every specified amount of time
* for redrawing
* @param can  Canvas to set render function for
* @param func Animation function that will be called between redraws
* @param time Amount of time (ms) between redraws
**********************/
void Canvas_setRenderFunction (canvas_t * can, void (func)(),
	unsigned int time);

/**********************
* Runs the render loop of the specified canvas
* @param can  Canvas to run render loop for
* @param argc
* @oaram argv
**********************/
void Canvas_startLoop (canvas_t * can, int argc, char ** argv);

/**********************
* Frees resources allocated for a canvas
* @param target Canvas to free resources for
**********************/
void Canvas_free (canvas_t * target);

#endif
