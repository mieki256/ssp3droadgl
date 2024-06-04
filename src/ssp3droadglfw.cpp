// Last updated: <2024/06/05 01:59:00 +0900>
//
// Draw pseudo 3d road by OpenGL + glfw
//
// 1, 2, 3, 4 key : Draw on/off tree, sloop, BG, beam
// F key : Change framerate 60, 30, 20 FPS
// T key : Display on/off FPS
//
// Use Windows10 x64 22H2 + MinGW (gcc 6.3.0) + glfw3
// by mieki256
// License: CC0 / Public Domain

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>

#include "render.h"

// #if 0
#ifdef _WIN32
// Windows
#include <windows.h>
#include <mmsystem.h>
#define WINMM_TIMER
#else
// Linux
#undef WINMM_TIMER
#endif

// window size
#define SCRW 1280
#define SCRH 720

// setting value
int waitValue = 15;
int fps_display = 1;
int enableDrawTree = 1;
int enableDrawSlope = 1;
int enableDrawBg = 1;
int enableDrawBeam = 1;
int enableGlErrChk = 0;

// ----------------------------------------
// prototype declaration
int main(void);
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
static void resize(GLFWwindow *window, int w, int h);
void error_callback(int error, const char *description);
void errmsg(const char *description);
void error_exit(const char *description);

// ----------------------------------------
// Main
int main(void)
{
    GLFWwindow *window;

    Width = SCRW;
    Height = SCRH;

#ifdef WINMM_TIMER
    timeBeginPeriod(1);
#endif

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        // Initialization failed
        errmsg("Could not initialize GLFW3");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1); // set OpenGL 1.1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // create window
    window = glfwCreateWindow(Width, Height, "Pseudo 3d road", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
        errmsg("Could not create an window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, resize);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    SetupAnimation(Width, Height);
    set_cfg_framerate(60.0);
    set_use_waittime(1);

    // main loop
    while (!glfwWindowShouldClose(window))
    {
        Render();
        // glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

#ifdef WINMM_TIMER
    timeEndPeriod(1);
#endif

    CleanupAnimation();

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

// ----------------------------------------
// Error callback
void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void errmsg(const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void error_exit(const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
    glfwTerminate();
    exit(EXIT_FAILURE);
}

// ----------------------------------------
// window resize callback
static void resize(GLFWwindow *window, int w, int h)
{
    if (h == 0)
        return;

    glfwSetWindowSize(window, w, h);
    glfwSwapInterval(1);
    resize_window(w, h);
}

// ----------------------------------------
// Key callback
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q)
        {
            // ESC or Q key to exit
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        else if (key == GLFW_KEY_1)
        {
            enableDrawTree = (enableDrawTree + 1) % 2;
        }
        else if (key == GLFW_KEY_2)
        {
            enableDrawSlope = (enableDrawSlope + 1) % 2;
        }
        else if (key == GLFW_KEY_3)
        {
            enableDrawBg = (enableDrawBg + 1) % 2;
        }
        else if (key == GLFW_KEY_4)
        {
            enableDrawBeam = (enableDrawBeam + 1) % 2;
        }
        else if (key == GLFW_KEY_T)
        {
            fps_display = !fps_display;
        }
        else if (key == GLFW_KEY_F)
        {
            float fps = get_cfg_framerate();
            if (fps == 60.0)
            {
                set_cfg_framerate(30.0);
            }
            else if (fps == 30.0)
            {
                set_cfg_framerate(20.0);
            }
            else if (fps == 20.0)
            {
                set_cfg_framerate(60.0);
            }
        }
    }
}
