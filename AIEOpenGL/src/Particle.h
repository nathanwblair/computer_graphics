#pragma once
#include <functional>
#include "Utils.h"

struct Particle
{
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec4 color;


	float size;
	float lifetime;
	float lifespan;
	float radius;

	float weight;
	Particle * target;
	float mass;
	float maxMass;

	Particle() : weight(1.0f), mass(1.0f), maxMass(3.0f)
	{
		velocityModifier = &Particle::Seek;
	}

	std::function<glm::vec3(const glm::vec3& input, float weight)> velocityModifier;

	void Update(float deltaTime) 
	{
		velocity += (glm::vec3)Modify(this, velocityModifier, velocity, weight * deltaTime);
	}

	glm::vec3 Seek(const glm::vec3& input, float weight)
	{
		return glm::normalize(target->position);
	}

	//glm::vec3 SeekArea(const glm::vec3& input, float weight)
	//{
	//	auto distance = glm::abs(glm::length(glm::distance(input, target->position)));

	//	return Seek(input, SoftMinLimit(distance, target->radius, target->Softness()) * weight);
	//}

	//float Softness()
	//{
	//	return (maxMass - MaxLimit(mass, maxMass, 5.0f)) / radius;
	//}
};
