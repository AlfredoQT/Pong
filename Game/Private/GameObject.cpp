#include "..\Public\GameObject.h"
#include "Game\Public\World.h"

GameObject::GameObject(World* pWorld)
{
	mWorld = pWorld;
}

GameObject::~GameObject()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Destroy();

		delete pComponent;
	}
}

void GameObject::Initialize()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Initialize();
	}
}

void GameObject::AddComponent(Component * pComponent)
{
	mComponents.push_back(pComponent);
}

World * GameObject::GetWorld() const
{
	return mWorld;
}
