#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "gameobject.h"
#include "mat4x4.h"

namespace Engine::Components
{
	/*! @class Camera \file camera.h
	 *  @brief A component to add to a gameobject used to render with
	 *  @author Kay Hennig
	 *  @date 03.08.2020
	 */
	class Camera : public Component
	{
	public:
		/*! Indicates the type of the component */
		static ComponentType baseType;
		/*! sets a new FOV for the camera */
		void SetFov(real h_fov);
		/*! sets a new aspect ratio (use with caution)*/
		void SetAspect(real aspect);
		/*! sets new near and far planes */
		void SetPlanes(real nearPlane, real farPlane);
		/*! indicates the currently used Camera component to render with */
		static Camera* activeCamera;
		/*! @brief Retrieves matrix to project models with
		 *  @return View Projection Matrix
		 */
		const Engine::Math::Mat4x4& GetViewProjMatrix() { return viewProjMatrix; }
	private:
		Engine::Math::Mat4x4 viewProjMatrix;
		real h_fov;
		real aspect;
		real nearPlane;
		real farPlane;
	protected:
		/*! updates the matrices with set variables */
		void Update();
		Camera(GameObject* attach);
		friend class GameObject;
	};
}