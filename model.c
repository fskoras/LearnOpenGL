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
 * File:   model.c
 * Author: Hesitant
 * 
 * Created on 30 października 2018, 22:58
 */

#include "model.h"


#define ARRAY_INCREMENT_CONSTANT_RATE 3 * 85   // must be a multitude of 3

void load_model_from_obj_file(ModelObject * model, const char * path)
{
    char* pEnd;
    char buffer[256];
    FILE * f = fopen(path, "r");
    if (f == NULL)
    {
        printf("Did not found file in location: %s\n", path);
        return;
    }
    
    int vertices_array_size = ARRAY_INCREMENT_CONSTANT_RATE;
    model->vertices = (float *)malloc(sizeof(float) * vertices_array_size);
    model->vertices_count = 0;
    int indices_array_size = ARRAY_INCREMENT_CONSTANT_RATE;
    model->indices = (int *)malloc(sizeof(int) * indices_array_size);
    model->indices_count = 0;
    
    while( fgets(buffer, 256, f) != NULL )
    {
        switch(buffer[0])
        {
        case 'v':
            if (model->vertices_count >= vertices_array_size)
            {
                vertices_array_size += ARRAY_INCREMENT_CONSTANT_RATE;
                model->vertices = (float *)realloc((void *)model->vertices, sizeof(float) * vertices_array_size);
            }
            model->vertices[model->vertices_count++] = strtof (&buffer[2], &pEnd);
            model->vertices[model->vertices_count++] = strtof (&buffer[pEnd - buffer], &pEnd);
            model->vertices[model->vertices_count++] = strtof (&buffer[pEnd - buffer], NULL);
            break;
        case 'f':
            if (model->indices_count >= indices_array_size)
            {
                indices_array_size += ARRAY_INCREMENT_CONSTANT_RATE;
                model->indices = (int *)realloc((void *)model->indices, sizeof(int) * indices_array_size);
            }
            model->indices[model->indices_count++] = strtol (&buffer[2], &pEnd, 10) - 1;
            model->indices[model->indices_count++] = strtol (&buffer[pEnd - buffer], &pEnd, 10) - 1;
            model->indices[model->indices_count++] = strtol (&buffer[pEnd - buffer], NULL, 10) - 1 ;
            break;
        case '#':
            // comments
            break;
        default:
            // ...
            break;
        }
    }
    
    fclose(f);
}

void create_model(ModelObject * model, const char * path)
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    
    load_model_from_obj_file(model, path);
    
//    model->vertices_count = 12;
//    model->vertices = malloc(sizeof(float) * model->vertices_count);
//    
//    model->vertices[0] = 0.5f;   // top right
//    model->vertices[1] = 0.5f;
//    model->vertices[2] = 0.0f;
//    
//    model->vertices[3] = 0.5f;   // bottom right
//    model->vertices[4] = -0.5f;
//    model->vertices[5] = 0.0f;
//    
//    model->vertices[6] = -0.5f;  // bottom left
//    model->vertices[7] = -0.5f;
//    model->vertices[8] = 0.0f;
//    
//    model->vertices[9] = -0.5f;  // top left
//    model->vertices[10] = 0.5f;
//    model->vertices[11] = 0.0f;
//    
//    int i;
//    for(i = 0; i < model->vertices_count; ++i)
//    {
//        printf("%d. %f\n", i, model->vertices[i]);
//    }
//    
//    model->indices_count = 6;
//    model->indices = malloc(sizeof(float) * model->indices_count);
//    
//    model->indices[0] = 0;  // first triangle
//    model->indices[1] = 1;
//    model->indices[2] = 3;
//    
//    model->indices[3] = 1;  // second triangle
//    model->indices[4] = 2;
//    model->indices[5] = 3;
//    
//    for(i = 0; i < model->indices_count; ++i)
//    {
//        printf("%d. %d\n", i, model->indices[i]);
//    }

    glGenVertexArrays(1, &model->VAO);
    glGenBuffers(1, &model->VBO);
    glGenBuffers(1, &model->EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(model->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, model->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(model->vertices_count), model->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float)*(model->indices_count), model->indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void draw_model(ModelObject * model)
{
    // draw our first triangle
    glUseProgram(model->shaderProgram);
    glBindVertexArray(model->VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, model->indices_count, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time    
}


void destroy_model(ModelObject * model)
{
    glDeleteVertexArrays(1, &model->VAO);
    glDeleteBuffers(1, &model->VBO);
    glDeleteBuffers(1, &model->EBO);
}