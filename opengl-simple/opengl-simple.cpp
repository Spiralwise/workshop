// OpenGL related libs
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Standard c++ libs
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#define MOVE_NONE 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define MOVE_UP 3
#define MOVE_DOWN 4


using namespace std;


static char currentMove = MOVE_NONE;
static const float moveSpeed = 0.01f;

/*static const GLfloat triangle_vertex_data [] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};*/

static const GLfloat triangle_vertex_data [] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

/*static GLfloat mat_translate [] = {
	1.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 1.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};*/

glm::mat4 mat_translate = glm::mat4(1.0f);

void keyCallback (GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_UP: currentMove = MOVE_UP; break;
		case GLFW_KEY_DOWN: currentMove = MOVE_DOWN; break;
		case GLFW_KEY_LEFT: currentMove = MOVE_LEFT; break;
		case GLFW_KEY_RIGHT: currentMove = MOVE_RIGHT; break;
		}
	}
	else if (action == GLFW_RELEASE)
		currentMove = MOVE_NONE;
}

/** Not mine **/
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){
 
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
 
    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }
 
    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }
 
    GLint Result = GL_FALSE;
    int InfoLogLength;
 
    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);
 
    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
 
    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);
 
    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
 
    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
 
    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
 
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
 
    return ProgramID;
}
/** -------- **/

int main ()
{
	// ---- Initialization
	if (!glfwInit())
	{
		cout << "GLFW initialization has failed." << endl;
		return -1;
	}
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	cout << "GLFW initialized." << endl;

	GLFWwindow* window = glfwCreateWindow (640, 480, "OpenGL-Simple", NULL, NULL);
	if (window == NULL)
	{
		cout << "Unable to open a window." << endl;
		return -1;
	}
	glfwMakeContextCurrent (window);
	glfwSetInputMode (window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetKeyCallback (window, keyCallback);
	cout << "Window initialized." << endl;

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW initialization has failed." << endl;
		return -1;
	}
	cout << "GLEW initialized." << endl;
	// --------

	// ---- Rendering preparation
	GLuint vao;
	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	GLuint shaders = LoadShaders ("vertex.glsl", "fragment.glsl");

	GLuint vb;
	glGenBuffers (1, &vb);
	glBindBuffer (GL_ARRAY_BUFFER, vb);
	glBufferData (GL_ARRAY_BUFFER, sizeof (triangle_vertex_data), triangle_vertex_data, GL_STATIC_DRAW);
	// --------

	// ---- Main loop
	cout << "Run..." << endl;
	do
	{
		switch (currentMove)
		{
			case MOVE_UP: mat_translate = glm::translate (mat_translate, glm::vec3 (0.0f, moveSpeed, 0.0f)); break;
			case MOVE_DOWN: mat_translate = glm::translate (mat_translate, glm::vec3 (0.0f, -moveSpeed, 0.0f)); break;
			case MOVE_LEFT: mat_translate = glm::translate (mat_translate, glm::vec3 (-moveSpeed, 0.0f, 0.0f)); break;
			case MOVE_RIGHT: mat_translate = glm::translate (mat_translate, glm::vec3 (moveSpeed, 0.0f, 0.0f)); break;
		}
		
		glClear (GL_COLOR_BUFFER_BIT);
		glUseProgram (shaders);
		GLint transformMat = glGetUniformLocation (shaders, "TransformMat");
		glUniformMatrix4fv (transformMat, 1, GL_FALSE, &mat_translate[0][0]);
		
		glEnableVertexAttribArray (0);
		glBindBuffer (GL_ARRAY_BUFFER, vb);
		glVertexAttribPointer (
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		glDrawArrays (GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray (0);
		
		glfwSwapBuffers (window);
		glfwPollEvents();
	} 
	while (glfwGetKey (window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose (window)
	);
	// --------

	// ---- Epilogue
	glDeleteBuffers (1, &vb);
	glDeleteVertexArrays (1, &vao);
	glDeleteProgram (shaders);
	glfwTerminate();
	// --------

	return 0;
}