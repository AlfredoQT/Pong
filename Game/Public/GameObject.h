#pragma once

#include "..\Public\Component.h"
#include <vector>

class World;

// our game object, it's just a collection of components - that's it!
class GameObject
{
public:
	
	GameObject(World* pWorld);

	~GameObject();

	void Initialize();

	void AddComponent(Component* pComponent);

	template<class T>
	T* FindComponent(ComponentType eType)
	{
		for (Component* pComponent : mComponents)
		{
			if (pComponent->GetType() == eType)
			{
				return (T*)pComponent;
			}
		}

		return nullptr;
	}

	World* GetWorld() const;

private:
	std::vector<Component*> mComponents;

	World* mWorld;

};
