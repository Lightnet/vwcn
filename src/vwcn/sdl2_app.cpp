/*
 * Main Application 
 */


#include <imgui.h>
#include "imgui_impl_sdl2_glad.h"
#include <cstdio>
#include <cstdlib>
#include <SDL.h>
#include <glad/glad.h>

#include "vwcn/vwcn.h"
#include "sdl2_app.h"

#undef main

//namespace AppSDL{

	// Window management
	bool quit = false; // exit program
	SDL_Window *window = NULL;
	SDL_GLContext glContext;
	SDL_Event event;

	// Window parameters
	char title[] = "SDL2 APP Glad"; // window's title
	short unsigned int wHeight       = 600;
	short unsigned int wWidth        = 800;
	short unsigned int initialPosX   = 100;
	short unsigned int initialPosY   = 100;

	void _sdlError(const char *mes)
	{
		fprintf(stderr, "%s: %s\n", mes, SDL_GetError());
		exit(1);
	}

	void Init()
	{
		// Init SDL2     SDL_INIT_VIDEO - for video initialisation only
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
			_sdlError("Could not initialize SDL");

		// Set attributes
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		// Create window
		window = SDL_CreateWindow(title, initialPosX, initialPosY, wWidth, wHeight, SDL_WINDOW_OPENGL);
		if(window == NULL)
			_sdlError("Could not create window");

		ImGui_ImplSdlGLad_Init(window);

		// Create OpenGL context
		glContext = SDL_GL_CreateContext(window);
		if(glContext == NULL)
			_sdlError("Could not create the OpenGL context");

		// Load OpenGL functions glad SDL
		gladLoadGLLoader(SDL_GL_GetProcAddress);

		// V-Sync
		SDL_GL_SetSwapInterval(1);
	}

	void PreLoop()
	{
		printf("Vendor:          %s\n", glGetString(GL_VENDOR));
		printf("Renderer:        %s\n", glGetString(GL_RENDERER));
		printf("Version OpenGL:  %s\n", glGetString(GL_VERSION));
		printf("Version GLSL:    %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	}

	void LoadShaders()
	{
	// Shaders
	}

	void OpenGLSet() // set up OpenGL
	{
		GLint vpWidth, vpHeight;
		SDL_GL_GetDrawableSize(window, &vpWidth, &vpHeight);
		glViewport(0, 0, vpWidth, vpHeight);

		/*
		LoadShaders();
		*/
	}

	void app_DeleteGLTrash()
	{
		//glDeleteVertexArrays(1, &VAO);
		//glDeleteBuffers(1, &VBO);
	}

	void app_DeleteSDLTrash()
	{
		SDL_GL_DeleteContext(glContext);
		SDL_DestroyWindow(window);
	}

	int sdl_app(int argc, char* argv[])
	{
		Init(); // Init SDL2 Glad
		
		PreLoop(); // To do before loop (display graphics card info)
		
		OpenGLSet(); // set up OpenGL
		
		bool show_test_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImColor(114, 144, 154);
			
		// Main loop
		while(!quit)
		{
			glClearColor(0.4f, 0.2f, 0.2f, 1.0f); // Clear the color buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			ImGui_ImplSdlGLad_NewFrame(window);
			
			{
				static float f = 0.0f;
				ImGui::Text("Hello, world!");
				ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
				ImGui::ColorEdit3("clear color", (float*)&clear_color);
				//if (ImGui::Button("Test Window"))
				//{
						//show_test_window ^= 1;
						//printf("Window Click\n");
				//}
				if (ImGui::Button("Scene Nodes")){
					vwcn::print_nodes();
				}

				if (ImGui::Button("Add Polygon")){

					//using namespace vwcn;
					//PolygonGL* onode = new PolygonGL();
					//vwcn::addChild(onode);
					//std::unique_ptr<ObjectNode> ptr = std::unique_ptr<ObjectNode>(new PolygonGL());
					//vwcn::addChild(PT);
					//vwcn::addChild(std::move(ptr));
					//vwcn::PolygonGL PolyGL;
					//vwcn::nodes.push_back(PolyGL);
					//vwcn::addChild(PolyGL);
					//vwcn::nodeadd_test();
					//vwcn::addChild(PolyGL);
					//vwcn::nodeadd_test();
				}

				if (ImGui::Button("Polygon")){
					//PolyGL.Render();

				}

				if (ImGui::Button("Another Window")){
					show_another_window ^= 1;
					//Vwen::func();
					//Objnode.DoSomething();
					//PolyGL.Render();
				}
				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}
			
			vwcn::Renderer();

			//PolyGL.Render();
			
			ImGui::Render();
			
			SDL_GL_SwapWindow(window); // swap buffers
			while(SDL_PollEvent(&event)) // handle events
			{
				ImGui_ImplSdlGLad_ProcessEvent(&event);
				if(event.type == SDL_QUIT)
					quit = true;
			}
		}

		ImGui_ImplSdlGLad_Shutdown();
		// To do before exit the program
		app_DeleteGLTrash();
		app_DeleteSDLTrash();
		SDL_Quit();
		
		return 0;
	}
//}
