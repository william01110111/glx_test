#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(string vertFile, string fragFile, bool debug)
{
	cout << "1.1" << endl;
	Shader vertShader(vertFile, GL_VERTEX_SHADER, debug);
	cout << "1.2" << endl;
	Shader fragShader(fragFile, GL_FRAGMENT_SHADER, debug);
	cout << "1.3" << endl;
	
    data = glCreateProgram();
    glAttachShader(data, vertShader);
    glAttachShader(data, fragShader);
    glLinkProgram(data);
    // Check for linking errors
    GLint success;
    glGetProgramiv(data, GL_LINK_STATUS, &success);
    if (!success) {
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << getInfoLog() << std::endl;
    }
}

string ShaderProgram::getInfoLog()
{
	GLchar infoLog[1024];
	glGetProgramInfoLog(data, 1024, NULL, infoLog);
	string out(infoLog);
	return out;
}

ShaderProgram::~ShaderProgram()
{
	//glDeleteProgram(data);
}

ShaderProgram::Shader::Shader(string file, GLenum type, bool debug)
{
	cout << "1.1.1" << endl;
	string sourceString;
	if (!loadFile(file, sourceString, debug))
		cout << "vertex shader file failed to load" << endl;
	cout << "1.1.2" << endl;
	const char* source=sourceString.c_str();
	cout << "1.1.3" << endl;
    data = glCreateShader(type);
	cout << "1.1.4" << endl;
    glShaderSource(data, 1, &source, NULL);
	cout << "1.1.5" << endl;
    glCompileShader(data);
	cout << "1.1.6" << endl;
    // Check for compile time errors
    GLint success;
    glGetShaderiv(data, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::cerr << "shader error: " << file << " " << getInfoLog() << std::endl;
    }
	cout << "1.1.10" << endl;
}

string ShaderProgram::Shader::getInfoLog()
{
	GLchar infoLog[1024];
	glGetShaderInfoLog(data, 1024, NULL, infoLog);
	string out(infoLog);
	return out;
}

ShaderProgram::Shader::~Shader()
{
	//glDeleteShader(data);
}
