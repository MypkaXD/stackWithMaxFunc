#include <iostream>
#include <stack>

template <class T>
class StackWithMax {
	std::stack<T> steck, steck_max;
public:

	StackWithMax() {}
	StackWithMax(const std::stack <T>& other) {
		steck = other;
		steck_max = other.steck_max;
	}

	StackWithMax<T>& operator=(const std::stack<T>& other) {
		steck = other.steck;
		steck_max = other.max_steck;
		return *this;
	}

	int size() {
		return steck.size();
	}

	void pop() {
		if (steck.size() == 0)
			throw "ERROR: this steck is empty";

		else {
			if (steck.top() == steck_max.top()) {
				steck_max.pop();
				steck.pop();
			}
			else if (steck.top() != steck_max.top()) {
				steck.pop();
			}
		}
	}

	void push(const T& value) {
		if (steck.size() == 0 || steck_max.top() < value) {
			steck_max.push(value);
			steck.push(value);
		}
		else if (steck.size() > 0 || steck_max.top() >= value)
			steck.push(value);
	}


	T top() {
		if (size() == 0) {
			throw "ERROR: this steck is empty";
			return T();
		}
		return steck.pop();
	}

	T maxelem() {
		if (size() == 0) {
			throw "ERROR: this steck is empty";
			return T();
		}
		return steck_max.top();
	}


	void print() { // how can i do this?
		StackWithMax<int> temp = *this;
		for (int count = 0; count < temp.size(); count++) {
			std::cout << temp.steck.top() << "\t";
			temp.pop();
		}
	}

	friend std::ostream& operator<<(std::ostream& out, StackWithMax<int>& other) // how can i do this?
	{
		StackWithMax<int> temp = other;
		for (int count = 0; count < temp.size(); count++) {
			out << temp.steck.top() << "\t";
			temp.pop();
		}
		return out;
	}
};



int main() {
	StackWithMax<int> steck1;
	StackWithMax<int> steck2;

	for (int count = 0; count < 100; count++) {
		steck1.push(count);
	}

	steck1.push(123);
	std::cout << "MAX elem of steck1 is " << steck1.maxelem() << std::endl;
	steck1.push(123);
	std::cout << steck1 << std::endl;
	std::cout << "MAX elem of steck1 is " << steck1.maxelem() << std::endl;
	//st.print();
	steck1.push(123);
	std::cout << "MAX elem of steck1 is " << steck1.maxelem() << std::endl;
	std::cout << steck1 << std::endl;

	steck2 = steck1;
	steck1.pop();
	std::cout << steck2;
	std::cout << "MAX elem of steck2 is " << steck2.maxelem() << std::endl;
	return 0;
}
