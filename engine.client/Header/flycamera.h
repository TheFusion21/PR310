#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "gameobject.h"
#include "vec2.h"

namespace Engine::Components
{
	/*! @class FlyCamera \file flycamera.h
	 *  @brief a component to add fly capability to the camera
	 *  @author Kay Hennig
	 *  @date 09.08.2020
	 */
	class FlyCamera : public Component
	{
	public:
		/*! @brief the type of component */
		static ComponentType baseType;

	private:
		Engine::Math::Vec2 oldMousePosition = Engine::Math::Vec2::Zero;
		real speed = 2.f;
		real rotX = 0, rotY = 0;
	protected:
		/*! @brief updates the new rotation, speed and position via inputs */
		void Update();
		/*! @brief construct a new Fly cam component attached to a game object */
		FlyCamera(GameObject* attach);
		friend class GameObject;
	};
}