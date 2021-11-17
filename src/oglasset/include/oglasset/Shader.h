#pragma once

#include <string>
#include <stdexcept>

#include <glm/glm.hpp>

class Shader
{
private:
	unsigned int rendererId;

public:
	Shader(const std::string& vertPath, const std::string& fragPath);
	~Shader();

	void bind() const;
	void unbind() const;

	// Utility uniform methods
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, const glm::vec3& vec) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
	static unsigned int buildShader(const char* vertexPath, const char* fragmentPath);
};

class shader_build_error : public std::runtime_error
{
public:
	explicit shader_build_error(const std::string& msg) 
		: std::runtime_error(msg) {}
};