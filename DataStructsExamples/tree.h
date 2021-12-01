#pragma once

#ifdef USE_INCLUDES
#include <memory>
#include <vector>
#include <functional>
#else
import std.core;
#endif

template <typename T>
class Tree
{
	T value_;
	std::vector<Tree<T>> children_;

public:
	Tree()
	{

	}

	Tree(const T& value)
		: value_(value)
	{

	}

	~Tree()
	{

	}

	void Add(const T& value, const T& parent_value)
	{
		std::function<void(Tree<T>*)> callback = [=](Tree<T>* node)
		{
			if (node->GetValue() == parent_value)
			{
				node->AddChild(value);
			}
		};

		Traverse(callback);
	}
	
	void Delete(const T& value)
	{
		std::function<void(Tree<T>*)> callback = [=](Tree<T>* node)
		{
			for (size_t i = 0; i < children_.size(); ++i)
			{
				if (children_[i].GetValue() == value)
				{
					children_.erase(children_.begin() + i);
					break;
				}
			}
		};

		ForEachChild(callback);
	}

	void Traverse(std::function<void(Tree<T>*)> callback)
	{
		std::function<void(Tree<T>*)> walk = [=](Tree<T>* node)
		{
			callback(node);

			node->ForEach(callback);
		};

		walk(this);
	}

	void ForEach(std::function<void(Tree<T>*)> callback)
	{
		for (size_t i = 0; i < children_.size(); ++i)
			children_[i].Traverse(callback);
	}

	void ForEachChild(std::function<void(Tree<T>*)> callback)
	{
		for (size_t i = 0; i < children_.size(); ++i)
			callback(&children_[i]);
	}

	const T& GetValue()
	{
		return value_;
	}

	void SetValue(const T& value)
	{
		value_ = value;
	}

	bool operator ==(const Tree<T>& other_tree)
	{
		if (other_tree.value_ == this->value_)
			return true;

		return false;
	}

private:
	void AddChild(T value)
	{
		children_.push_back(Tree<T>(value));
	}

	void DeleteNode(T value)
	{
		auto it = std::find(children_.begin(), children_.end(), value);
		if (it != children_.end())
			children_.erase(it);
	}
};