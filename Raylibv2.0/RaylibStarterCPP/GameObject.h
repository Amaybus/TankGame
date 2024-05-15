#pragma once

#include "Vector3.h"
#include "Matrix3.h"

#include <vector>

class GameObject
{
protected:
	GameObject* Parent;
	std::vector<GameObject*> Children;

	vec3 LocalPosition;
	float LocalRotation;
	vec3 LocalScale;

	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw();

public:
	GameObject();

	void Update(float deltaTime);
	void Draw();

	void SetParent(GameObject* newParent);
	GameObject* GetParent();
	const GameObject* GetParent() const;

	GameObject* GetChild(size_t childIndex);
	const GameObject* GetChild(size_t childIndex) const;

	vec3 GetLocalPosition() const;
	void SetLocalPosition(vec3 newPosition);
	void SetLocalPosition(float x, float y);
	vec3 GetWorldPosition() const;

	float GetLocalRotation() const;
	void SetLocalRotation(float newRotation);
	float GetWorldRotation() const;

	vec3 GetLocalScale() const;
	void SetLocalScale(vec3 newScale);
	void SetLocalScale(float x, float y);
	vec3 GetWorldScale() const;

	vec3 GetForward() const;

	MathClasses::Matrix3 GetLocalMatrix() const;
	MathClasses::Matrix3 GetWorldMatrix() const;

	void Translate(float x, float y);
	void Translate(vec3 translation);
	void Rotate(float radians);
	void Scale(float x, float y);
	void Scale(vec3 scale);
};