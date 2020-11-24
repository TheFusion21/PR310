#pragma once

#include <vector>

class Node
{
public:
	Node();
	virtual void Update();
	virtual bool AddChild(Node* newChild);
	virtual void RemoveChild(Node* child);
	[[nodiscard]] virtual const std::vector<Node*>& GetChildren() const;
	virtual Node* GetRoot();
	virtual Node* GetParent();

protected:
	Node* parent;
	std::vector<Node*> children;
	
};
