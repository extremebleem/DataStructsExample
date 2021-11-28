#pragma once

#ifdef USE_INCLUDES
#include <memory>
#else
import std.memory;
#endif

template <typename T = int>
class Node
{
	std::unique_ptr<Node<T>> right_;
	std::unique_ptr<Node<T>> left_;
	T value_;

public:
	Node(Node<T>* right, Node<T>* left, T value)
		: right_(right), left_(left), value_(value)
	{

	}

	~Node()
	{

	}

	Node<T>* GetRight()
	{
		return right_.get();
	}

	void SetRight(Node<T>* right)
	{
		right_ = std::unique_ptr<Node<T>>(right);
	}

	Node<T>* GetLeft()
	{
		return left_.get();
	}

	void SetLeft(Node<T>* left)
	{
		left_ = std::unique_ptr<Node<T>>(left);
	}

	const T& GetValue()
	{
		return value_;
	}
};

template <typename T = int>
class BinaryTree
{
	Node<T> head_;
	int lenght_;

public:

	BinaryTree(T value)
		: head_(nullptr, nullptr, value), lenght_(1)
	{
		
	}

	BinaryTree(Node<T>& head)
		: head_(head), lenght_(1)
	{

	}

	~BinaryTree()
	{

	}

	Node<T>* GetHead()
	{
		return &head_;
	}

	void Add(T value)
	{
		Node<T>* node = GetHead();

		while (node)
		{
			T node_value = node->GetValue();

			if (node_value > value)
			{
				Node<T>* left = node->GetLeft();
				
				if (!left)
				{
					node->SetLeft(new Node<T>(nullptr, nullptr, value));
					++lenght_;
				}

				node = left;
			}
			else if (node_value < value)
			{
				Node<T>* right = node->GetRight();
				
				if (!right)
				{
					node->SetRight(new Node<T>(nullptr, nullptr, value));
					++lenght_;
				}

				node = right;
			}
			else
			{
				break;
			}	
		}
	}

	bool Contains(T value)
	{
		Node<T>* node = GetHead();

		while (node)
		{
			const T& node_value = node->GetValue();

			if (node_value > value)
			{
				node = node->GetLeft();
			}
			else if (node_value < value)
			{
				node = node->GetRight();
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	int GetLenght()
	{
		return lenght_;
	}
};