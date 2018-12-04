#pragma once

#include <vector>
#include <algorithm>

// all the different types of components
enum class ComponentType : int
{
	Transform = 0,
	Physics,
	BoxShape,
	CircleShape,
	Bounce,
	Reset,
	Scorer,
	PaddleController,
	PlayerController,
	AIController
};

class GameObject;

// our base component class
class Component
{
public:

	Component(GameObject* pGO);

	virtual ComponentType GetType() const = 0;

	virtual void Initialize();
	virtual void Destroy();

	GameObject* GetOwner() const;

protected:

	template<class T>
	void AddToComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.push_back((T*)this);
	}

	template<class T>
	void RemoveFromComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), this), componentVector.end());
	}

protected:

	GameObject * mGO;

};
