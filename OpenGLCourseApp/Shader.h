#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

class Shader
{
public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string ReadFile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetLightDirectionLocation();
	GLuint GetAmbientColourLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetCameraLocalPos();

	void UseShader();
	void ClearShader();

	~Shader();

private:
	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformAmbientIntensity, uniformAmbientColour, uniformLightDirection, uniformDiffuseIntensity, uniformSpecularIntensity, uniformCameraPos, uniformLightPosition, uniformLightConstant, uniformLightLinear, uniformLightQuadratic;

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

