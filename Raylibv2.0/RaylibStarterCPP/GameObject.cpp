#include "GameObject.h"

void GameObject::OnUpdate(float deltaTime)
{
}

void GameObject::OnDraw()
{
}

GameObject::GameObject()
{
	Parent = nullptr;
	LocalPosition = vec3(0, 0, 1);
	LocalScale = vec3{ 1, 1, 1 };
	LocalRotation = 0;
}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);

	for (int i = 0; i < Children.size(); i++)
	{
		Children[i]->Update(deltaTime);
	}
}

void GameObject::Draw()
{
	OnDraw();

	for (int i = 0; i < Children.size(); i++)
	{
		Children[i]->Draw();
	}
}

void GameObject::SetParent(GameObject* newParent)
{
	if (Parent != nullptr)
	{
		auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

		if (findIt != Parent->Children.end())
		{
			Parent->Children.erase(findIt);
			Parent = nullptr;
		}
	}

	if (newParent != nullptr)
	{
		Parent = newParent;
		Parent->Children.push_back(this);
	}
}

GameObject* GameObject::GetParent()
{
	return Parent;
}

const GameObject* GameObject::GetParent() const
{
	return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return Children[childIndex];
}

vec3 GameObject::GetLocalPosition() const
{
	return LocalPosition;
}

void GameObject::SetLocalPosition(vec3 newPosition)
{
	LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float x, float y)
{
	LocalPosition = vec3(x, y, LocalPosition.z);
}

vec3 GameObject::GetWorldPosition() const
{
	MathClasses::Matrix3 worldMat = GetWorldMatrix();
	return vec3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetLocalRotation() const
{
	return LocalRotation;
}

void GameObject::SetLocalRotation(float newRotation)
{
	LocalRotation = newRotation;
}

float GameObject::GetWorldRotation() const
{
	vec3 fwd = GetForward();
	return atan2(fwd.y, fwd.x);
}

vec3 GameObject::GetLocalScale() const
{
	return LocalScale;
}

void GameObject::SetLocalScale(vec3 newScale)
{
	LocalScale = newScale;
}

void GameObject::SetLocalScale(float x, float y)
{
	LocalScale = vec3(x, y, LocalScale.z);
}

vec3 GameObject::GetWorldScale() const
{
	MathClasses::Matrix3 myTransform = GetWorldMatrix();

	return vec3(vec3(myTransform.m1, myTransform.m2, 0).Magnitude(),
		vec3(myTransform.m4, myTransform.m5, 0).Magnitude(),
		1.0f);
}

vec3 GameObject::GetForward() const
{
	auto worldMat = GetWorldMatrix();
	return vec3(worldMat[0], worldMat[1], worldMat[2]);
}

MathClasses::Matrix3 GameObject::GetLocalMatrix() const
{
	return
		MathClasses::Matrix3::MakeTranslation(LocalPosition) *
		MathClasses::Matrix3::MakeRotateZ(LocalRotation) *
		MathClasses::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

MathClasses::Matrix3 GameObject::GetWorldMatrix() const
{
	if (Parent == nullptr)
	{
		return GetLocalMatrix();
	}
	else
	{
		return Parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

void GameObject::Translate(float x, float y)
{
	LocalPosition += vec3(x, y, 0);
}

void GameObject::Translate(vec3 translation)
{
	LocalPosition += translation;
}

void GameObject::Rotate(float radians)
{
	LocalRotation += radians;
}

void GameObject::Scale(float x, float y)
{
	LocalScale *= vec3(x, y, 0);
}

void GameObject::Scale(vec3 scale)
{
	LocalScale *= scale;
}

