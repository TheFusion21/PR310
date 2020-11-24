#include "scenenode.h"

SceneNode::SceneNode(const char* name)
	: Node()
	, name(name)
	, worldSpace()
	, isDirty(true)
{}

void SceneNode::Update()
{
	if (isDirty)
	{
		this->worldSpace.position += this->localSpace.position;
		
		for (auto& child : children)
		{
			auto* sceneChild = static_cast<SceneNode*>(child);
			sceneChild->worldSpace.position = this->localSpace.position;
			sceneChild->isDirty = true;
		}
		
		isDirty = false;
	}
	
	Node::Update();
}

bool SceneNode::AddChild(Node* newChild)
{
	auto* childNode = static_cast<SceneNode*>(newChild);
	
	if (Node::AddChild(childNode))
	{
		childNode->localSpace.position -= GetWorldTransform().position;
		childNode->SetDirty();
		return true;
	}
	
	return false;
}

bool SceneNode::RemoveChild(Node* child)
{
	auto* childNode = static_cast<SceneNode*>(child);

	if (Node::RemoveChild(child))
	{
		static_cast<SceneNode*>(GetRoot())->Update();
		childNode->localSpace = childNode->worldSpace;
		childNode->SetDirty();
		return true;
	}
	
	return false;
}

void SceneNode::SetDirty()
{
	isDirty = true;
	static_cast<SceneNode*>(GetRoot())->isDirty = true;
}

void SceneNode::SetTransform(const Transform& newTransform)
{
	localSpace = newTransform;
	isDirty = true;
}

const Transform& SceneNode::GetWorldTransform() const
{
	return worldSpace;
}

const Transform& SceneNode::GetLocalTransform() const
{
	return localSpace;
}
