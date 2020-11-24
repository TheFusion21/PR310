#include "input/mouse.h"
#include "logging.h"

DEFINE_SINGLETON(MouseInput)

Vec2 MouseInput::GetMousePosition()
{
	return CurrentMousePos;
}

void MouseInput::SetMousePosition(MousePositionData positionData)
{
	MousePositionInputQueue.push(new MousePositionData{positionData});

	CurrentMousePos = positionData.position;
}

void MouseInput::SetMouseButtonData(MouseButtonData mouseButtonData)
{
	ButtonInputQueue.push(new MouseButtonData{mouseButtonData});

	if (mouseButtonData.ButtonType >= 0 && mouseButtonData.ButtonType < EMouseButton::MouseButtonCount)
		isButtonPressed[mouseButtonData.ButtonType] = mouseButtonData.isPressed;
}

void MouseInput::Update()
{
	while (true)
	{
		if (ButtonInputQueue.size() <= 0)
			break;

		auto* buttonData = ButtonInputQueue.front();
	
		auto callback = actionMap[buttonData->ButtonType];

		if (callback)
			callback(buttonData->isPressed);

		DebugLog("Mouse button: (%i was %s)", buttonData->ButtonType, buttonData->isPressed ? "pressed" : "released");
		delete buttonData;
		ButtonInputQueue.pop();
	}

	//while (true)
	//{
	//	if (MousePositionInputQueue.size() < 0)
	//		break;

	//	auto* positionData = MousePositionInputQueue.front()
	//	delete positionData;
	//}
}

void MouseInput::AddCallback(EMouseButton mouseButton, OnButtonPressedCallback callback)
{
	actionMap[mouseButton] = callback;
}
