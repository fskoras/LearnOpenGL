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
 * File:   main.c
 * Author: Hesitant
 *
 * Created on 29 października 2018, 18:12
 */

#include "system.h"
#include "shader.h"
#include "model.h"
#include "lib/cglm/include/cglm/mat3.h"
#include "lib/cglm/include/cglm/vec3.h"

int main()
{
    GLFWwindow* window;
    init_system(&window);
    
    ModelObject model1;
    ModelObject model2;
    create_model(&model1, "models/monkey.obj");
    create_model(&model2, "models/sphere.obj");
    model1.shaderProgram = create_shader("color");
    model2.shaderProgram = model1.shaderProgram;
    
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_model(&model1);
        draw_model(&model2);
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    
    destroy_model(&model1);
    destroy_model(&model2);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}



