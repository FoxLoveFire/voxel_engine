#include "ShaderManager.h"

ShaderManager::ShaderManager(RenderWindow* window) : window(window)
{
    shader = nullptr;
}

int ShaderManager::load()
{
    shader = load_shader("res/main.glslv", "res/main.glslf");
	if (shader == nullptr){
		std::cerr << "failed to load shader" << std::endl;
		window->terminate();
		return 1;
	}
}

void ShaderManager::run() 
{
    shader->use();
} 

ShaderManager::~ShaderManager()
{  
    delete shader;
}