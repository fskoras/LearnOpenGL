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
 * File:   shader.c
 * Author: Hesitant
 * 
 * Created on 29 października 2018, 18:12
 */

#include "shader.h"

char * load_shader_ascii(const char * path)
{
    FILE *f = fopen(path, "rt");
    char * string;
    if(f)
    {
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);  //same as rewind(f);

        string = malloc(fsize + 1);
        fread(string, fsize, 1, f);
        fclose(f);

        string[fsize] = 0;
    }
    else
    {
        printf("Could not open file: %s\n", path);
    }
    return string;
}


int create_shader(const char * name)
{
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    char shaderSourceLocation[] = "C:/Users/Hesitant/Documents/NetBeansProjects/LearnOpenGL/shaders/";
    char vertexShaderSourcePath[256];
    sprintf(vertexShaderSourcePath, "%s%s.vs", shaderSourceLocation, name);
    char * vertexShaderSource[1];
    vertexShaderSource[0] = load_shader_ascii( vertexShaderSourcePath );
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, (const char **)vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }
    // fragment shader
    char * fragmentShaderSource[1];
    char fragmentShaderSourcePath[256];
    sprintf(fragmentShaderSourcePath, "%s%s.fs", shaderSourceLocation, name);
    fragmentShaderSource[0] = load_shader_ascii(fragmentShaderSourcePath);
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, (const char **)fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }
    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    return shaderProgram;
}