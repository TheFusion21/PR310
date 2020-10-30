#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES


class GameObject;

namespace Game::Client
{
	class Application;
}
namespace Engine::Components
{

	enum class ComponentType
	{
		Invalid,
		Camera,
		MeshRenderer,
		Transform,
		FlyCamera
	};
	/*! @class Component \file component.h
	 *  @brief the base from which all components form
	 *  @author Kay Hennig
	 *  @date 11.08.2020
	 */
	class Component
	{
	public:
		/*! @brief the type of component */
		static ComponentType baseType;
		/*! @brief the type of instantiated component*/
		ComponentType type;
		/*! @brief game object that the component is attached to*/
		GameObject* const gameObject = nullptr;
	protected:
		Component(GameObject* attach, ComponentType type);
		friend class Game::Client::Application;
		virtual void Update() {}
	};
}
