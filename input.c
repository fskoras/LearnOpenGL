/*
 * The MIT License
 *
 * Copyright 2018 Hesitant.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   input.c
 * Author: Hesitant
 * 
 * Created on 30 października 2018, 22:33
 */

#include "input.h"

// process all keyboard input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ------------------------------------------------------------------------------------------------------------------
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    switch(action)
    {
    case GLFW_PRESS:
        printf("PRESSED: ");
        switch(key)
        {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, true);
            break;
        }
        break;
    case GLFW_RELEASE:
        printf("RELEASED: ");
        break;
    case GLFW_REPEAT:
        printf("REPEATED: ");
        break;
    }
    printf("Key %d scancode %d action %d mods %d\n", key, scancode, action, mods);
}

// process all mouse buttons: query GLFW whether relevant keys on the mouse are pressed/released this frame and react accordingly
// ------------------------------------------------------------------------------------------------------------------------------
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    printf("action: mouse key %s", action ? "pressed" : "released");
}

// process all mouse movements: query GLFW whether mouse is moved inside the client area
// -------------------------------------------------------------------------------------
void cursor_position_callback(GLFWwindow *window, double x, double y)
{
    printf("X: %.2f \tY: %.2f\n", x, y);
}