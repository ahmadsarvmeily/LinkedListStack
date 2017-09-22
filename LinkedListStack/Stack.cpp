#include "Stack.h"

void Stack::Push(int val) {

	top = new Element(val, top);
	nElements++;
}

int Stack::Pop() {

	if (!Empty()) {
		int value = top->Value();

		nElements--;
		Element* topOld = top;
		top = &topOld->Previous();
		delete topOld;
		return value;
	}
	else return -1;
}

int Stack::Size() const {

	return nElements;
}

bool Stack::Empty() const {

	return nElements == 0;
}