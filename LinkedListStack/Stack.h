#pragma once

class Stack
{
private:
	class Element {
	public:
		Element(int value, Element* previous)
			:
			value(value),
			previous(previous)
		{}

		int Value() const {
			return value;
		}

		Element& Previous() const {
			return *previous;
		}

	public:
		Element& operator=(const Element& source) {
			value = source.value;

			if (source.previous != nullptr)
				previous = new Element(*source.previous);
			else previous = nullptr;

			return *this;
		}
		Element(const Element& source) {
			*this = source;
		}
		~Element() = default;

	private:
		int value;
		Element* previous = nullptr;
	};

public:
	Stack() = default;

	Stack& operator=(const Stack& source) {
		nElements = source.nElements;
		top = new Element(*source.top);
		return *this;
	}

	Stack(const Stack& source) {
		*this = source;
	}

	~Stack() {
		Element* prev;
		for (Element* current = top; current != nullptr; current = prev) {
			prev = &current->Previous();
			delete current;
		}
	}

public:
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	int nElements = 0;
	Element* top = nullptr;
};