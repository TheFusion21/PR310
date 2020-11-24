#pragma once

#include "node.h"
#include "ecs/component/transform.h"

class SceneNode : public Node
{
public:
	SceneNode(const char* _name);
	void Update() override;
	void SetTransform(const Transform& newTransform);
	bool AddChild(Node* newChild) override;
	bool RemoveChild(Node* child) override;
	void SetDirty();
	const Transform& GetLocalTransform() const;
	const Transform& GetWorldTransform() const;
	
private:
	const char* name;
	Transform worldSpace;
	Transform localSpace;
	bool isDirty;
	
};
