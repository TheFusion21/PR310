#pragma once

// EXTERNAL INCLUDES
#include <vector>
// INTERNAL INCLUDES
#include "transform.h"

/*! @class GameObject \file gameobject.h
 *  @brief Object containing Components
 *  @author Kay Hennig
 *  @date 09.08.2020
 */
class GameObject
{
public:
	/*! @brief the transform component of the game object*/
	Engine::Components::Transform*const transform;
	
	/*! @brief construct a game object with default Components*/
	GameObject();

	/*! @brief add a new component to the game object*/
	template<class T>
	T* AddComponent();

	/*! @brief get component from the game object*/
	template<class T>
	T* GetComponent() const;
private:
	std::vector<Engine::Components::Component*> components;
	Engine::Components::Transform * _transform;
	friend class Game::Client::Application;
};

template<class T>
T* GameObject::GetComponent() const
{
	T* foundComponent = nullptr;
	for (auto& cmpnt : components)
	{
		foundComponent = static_cast<T*>(cmpnt);
		if (foundComponent != nullptr)
		{
			if (cmpnt->type == T::baseType)
			{
				return foundComponent;
			}
		}
	}
	return nullptr;
}
template<class T>
T* GameObject::AddComponent()
{
	components.push_back(static_cast<Engine::Components::Component*>(new T(this)));
	return GetComponent<T>();
}