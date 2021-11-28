#pragma once

#ifdef USE_INCLUDES
#include <memory>
#else
import std.memory;
#endif

template <typename T = int>
struct Cell
{
	T value_;
	Cell<T>* next_;

	Cell()
		: value_(nullptr), next_(nullptr)
	{

	}

	Cell(T value, Cell<T>* cell = nullptr)
		: value_(value), next_(cell)
	{

	}

	Cell(const Cell<T>& cell)
		: value_(cell.value_), next_(cell.next_)
	{

	}
};

template <typename T = int>
class LinkedList
{
	std::shared_ptr<Cell<T>> head_;
	int lenght_;

public:
	LinkedList()
		: head_(nullptr), lenght_(0)
	{

	}

	LinkedList(T value)
		: head_(std::make_shared<Cell<T>>(value)), lenght_(1)
	{

	}

	~LinkedList()
	{

	}

	void Place(T value, int index = -1)
	{
		Cell<T>* cell = head_.get();

		if (index < 0)
		{
			index = lenght_ - 1;
		}

		for (int i = 0; i <= index; ++i, cell = cell->next_)
		{
			if (!cell->next_)
			{
				cell->next_ = new Cell<T>(value);
				++lenght_;
				break;
			}
			else if (i == index)
			{
				cell->next_ = new Cell<T>(*cell);
				cell->value_ = value;
				++lenght_;
				break;
			}
		}
	}

	T Get(int index)
	{
		Cell<T>* cell = head_.get();

		if (index < 0)
		{
			index = lenght_ - 1;
		}

		for (int i = 0; i <= index; ++i)
		{
			if (i == index)
			{
				return cell->value_;
			}

			cell = cell->next_;
		}

		return T();
	}

	int GetLenght()
	{
		return lenght_;
	}
};