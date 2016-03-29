#pragma once
#include "GLAsset.h"

#include "ShaderProgram.h"
#include "RenderData.h"
#include "Camera.h"
#include "Material.h"
#include "BoundingSphere.h"
#include "Transform.h"

#include <FBXFile.h>

class Mesh :
	public GLAsset
{
public:
	bool isVisible;

	Mesh();
	~Mesh();

	FBXFile* fbx;
	Transform transform;

	ShaderProgram shaderProgram;
	RenderData renderer;

	BoundingSphere boundingSphere;
	vector<Material> materials;

	void Load(string path);

	void Init(FBXFile * fbx);

	void Create() override;

	void Draw(const Camera& camera, const glm::vec3& lightDirection, const glm::vec3& lightColor);

	void GLDelete() override;

	bool CheckGLErrors() override
	{
		// TODO
		return true;
	}
};

