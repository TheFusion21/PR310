#include "node.h"

Node::Node() :
	parent(nullptr)
{
}

void Node::Update()
{
	for (auto* child : children)
	{	
		if (!child) continue;

		child->Update();
	}
}

const std::vector<Node*>& Node::GetChildren() const
{
	return children;
}

bool Node::AddChild(Node* newChild)
{
	if (newChild != nullptr && newChild->parent == nullptr)
	{
		children.push_back(newChild);
		newChild->parent = this;
		return true;
	}

	return false;
}

bool Node::RemoveChild(Node* child)
{
	if (child == nullptr) return false;

	const auto it = std::find(children.begin(), children.end(), child);
	if (it != children.end())
	{
		child->parent = nullptr;
		children.at(std::distance(children.begin(), it)) = *(children.end()--);
		children.pop_back();
		
		return true;
	}
	return false;
}

Node* Node::GetRoot()
{
	if (!parent) return this;
	return parent->GetRoot();
}

Node* Node::GetParent()
{
	if (!parent) return nullptr;
	return parent;
}
