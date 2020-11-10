#include "node.h"

Node::Node() :
	parent(nullptr)
{}

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

void Node::AddChild(Node* newChild)
{
	if (!newChild) return;
	
	children.push_back(newChild);
	newChild->parent = this;
}

Node* Node::GetRoot()
{
	if (!parent) return this;
	return parent->GetRoot();
}
