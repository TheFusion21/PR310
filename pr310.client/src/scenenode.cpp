#include "scenenode.h"

SceneNode::SceneNode(const char* name)
	: Node()
	, name(name)
	, transform()
	, isDirty(true)
{}

void SceneNode::Update()
{
	if (isDirty)
	{
		for (auto& child : children)
		{
			auto* sceneChild = static_cast<SceneNode*>(child);
			sceneChild->transform.position += this->transform.position;
			sceneChild->isDirty = true;
		}
		
		isDirty = false;
	}
	
	Node::Update();
}

void SceneNode::SetTransform(const Transform& newTransform)
{
	transform = newTransform;
	isDirty = true;
}

const Transform& SceneNode::GetTransform() const
{
	return transform;
}
