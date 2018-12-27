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
 * File:   model.h
 * Author: Hesitant
 *
 * Created on 30 października 2018, 22:58
 */

#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float * vertices;
    int vertices_count;
    int * indices;
    int indices_count;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int VAO;
    int shaderProgram;
}ModelObject;

void load_model_from_obj_file(ModelObject * model, const char * path);
void create_model(ModelObject * model, const char * path);
void draw_model(ModelObject * model);
void destroy_model(ModelObject * model);

#endif /* MODEL_H */
