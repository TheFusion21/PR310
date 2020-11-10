#pragma once

#include "node.h"
#include "ecs/component/transform.h"
#include <vector>

class SceneNode : public Node
{
public:
	SceneNode(const char* _name);
	void Update() override;
	void SetTransform(const Transform& newTransform);
	const Transform& GetTransform() const;
	
private:
	const char* name;
	Transform transform;
	bool isDirty;
	
};
