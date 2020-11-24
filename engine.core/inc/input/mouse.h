#pragma once

#include "math/vec2.h"
#include <queue>
#include <unordered_map>
#include "singleton.h"

enum EMouseButton
{
	MouseButton1,
	MouseButton2,
	MouseButton3,
	MouseButton4,
	MouseButton5,
	MouseButtonCount
};

struct MouseButtonData
{
	EMouseButton ButtonType;
	bool isPressed;
};

struct MousePositionData
{
	Vec2 position;
};

typedef void (*OnButtonPressedCallback)(bool);

class MouseInput
{
DECLARE_SINGLETON(MouseInput)

public:

	void SetMousePosition(MousePositionData positionData);

	Vec2 GetMousePosition();

	void SetMouseButtonData(MouseButtonData mouseButtonData);

	bool GetMouseButtonDown(EMouseButton);

	void Update();
	
	void AddCallback(EMouseButton, OnButtonPressedCallback);


	std::queue<MouseButtonData*> ButtonInputQueue;

	std::queue<MousePositionData*> MousePositionInputQueue;

	Vec2 CurrentMousePos;

	bool isButtonPressed[EMouseButton::MouseButtonCount];

	std::unordered_map<EMouseButton, OnButtonPressedCallback> actionMap;
};