#include <emscripten/emscripten.h>
#include <functional>
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"
#include "VertexBufferLayout.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

std::function<void()> loop;
void main_loop() { loop(); }

int main(void)
{
    if (!glfwInit()){
        std::cout << "Unable to init glfw\n";
        return -1;
    }
    
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Ayush's Window", NULL, NULL);
    if(!window){
        std::cout << "Failed to create GLFW Window\n";
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    //glfwSwapInterval(1);
    
    if(glewInit() != GLEW_OK){
        std::cout << "Unable to init glew\n";
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader("/assets/shaders/BasicShader.shader");
    Texture texture("/assets/textures/container.jpeg");

    float vertices[] = {
            // positions // colors // texture coords
            0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
           -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
           -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };
    
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    VertexArray     VAO;
    VertexBuffer    VBO(vertices, sizeof(vertices));
    IndexBuffer     IBO(indices, 6);
    
    VertexBufferLayout layout;
    layout.Push(GL_FLOAT, 3); // for position
    layout.Push(GL_FLOAT, 3); // for vertex color
    layout.Push(GL_FLOAT, 2); // for texture coordinate
    VAO.AddBuffer(VBO, layout);
    
    VBO.UnBind();
    texture.UnBind();
    VAO.UnBind();

    Renderer renderer;
    
    /* Loop until the user closes the window */
    loop = [&] {
        processInput(window);

        /* Render here */
        renderer.Clear();
        
        texture.Bind();
        shader.Bind();
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.SetUniformMatrix4fv("transform", glm::value_ptr(trans));

        VAO.Bind();
        
        renderer.Draw(VAO, IBO, shader);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    };
    emscripten_set_main_loop(main_loop, 0, true);
    glfwTerminate();
    return 0;
}
