#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "vec3.h"
#include "quaternion.h"
#include "component.h"

namespace Engine::Components
{
	/*! @class Transform \file transform.h
	 *  @brief a component to a transformation to a game object
	 *  @author Kay Hennig
	 *  @date 11.08.2020
	 */
	class Transform : public Component
	{
	public:
		/*! @brief the type of component */
		static ComponentType baseType;
		/*! @brief the position of the gameobject */
		Engine::Math::Vec3 position;
		/*! @brief the rotation of the gameobject */
		Engine::Math::Quaternion rotation;
		/*! @brief the local size of the gameobject */
		Engine::Math::Vec3 scale;
	protected:
		/*! @brief construct a new transform component attached to a game object */
		Transform(GameObject* attach);
		friend class GameObject;
	};
}