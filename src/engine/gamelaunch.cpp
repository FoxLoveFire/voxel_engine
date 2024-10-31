#include "gamelaunch.h"

#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "RenderWindow.h"
#include "Events.h"
#include "../graphics/Texture.h"
#include "../graphics/Shader.h"
#include "../graphics/ShaderManager.h"

gamelaunch::gamelaunch()
{
    render_w = new RenderWindow();
    event = new Events();

    this->width = 1280;
    this->height = 720;
}

float vertices[] = {
		// x    y     z     u     v
	   -1.0f,-1.0f, 0.0f, 0.0f, 0.0f,
		1.0f,-1.0f, 0.0f, 1.0f, 0.0f,
	   -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

		1.0f,-1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
	   -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
};


int gamelaunch::launch() 
{
    render_w->initialize("Voxel Engine", 1200, 720);

    event->initialize(render_w->get_window());

	// Shader* shader = load_shader("res/main.glslv", "res/main.glslf");
	// if (shader == nullptr){
	// 	std::cerr << "failed to load shader" << std::endl;
	// 	render_w->terminate();
	// 	return 1;
	// }

	ShaderManager shadermanager(render_w); 
	shadermanager.load();


    Texture* texture = load_texture("image.png");
    if (texture == nullptr) {
        render_w->terminate();
        return -1;
    }


    glClearColor(0.6f, 0.62f, 0.65f, 1);

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

    while (!render_w->isShouldClose()) 
    {
        if (event->pressed(GLFW_KEY_ESCAPE))
            render_w->setShouldClose(true);

        if (event->jpressed(GLFW_KEY_TAB))
            event->toggleCursor(render_w);


        glClear(GL_COLOR_BUFFER_BIT);


        //shader -> use();
		shadermanager.run();
        texture->bind();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

        render_w->swapBuffers();
        event->pullEvents();
    }

	//delete shader;
	delete texture;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

    render_w->terminate();

    return 0;
}

gamelaunch::~gamelaunch()
{
    delete render_w;
    delete event;

}