#pragma once

#include <vector>

class Node
{
public:
	Node();
	virtual void Update();
	virtual void AddChild(Node* newChild);
	virtual const std::vector<Node*>& GetChildren() const;
	virtual Node* GetRoot();

protected:
	std::vector<Node*> children;
	
private:
	Node* parent;
	
};
