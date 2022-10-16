#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

void findMaxElem(std::stack <int> &steck) {
	int tempLenght = steck.size();
	std::cout << "Size of steck is " << tempLenght << std::endl;
	std::stack <int> tempSteak;
	int maxElem{ 0 };
	for (int count = 0; count < tempLenght; count++) {
		if (steck.top() >= maxElem) {
			maxElem = steck.top();
			steck.pop();
			tempSteak.push(maxElem);
		}
		else {
			tempSteak.push(steck.top());
			steck.pop();
		}
	}
	std::cout << "Max elem of steck is " << maxElem << std::endl;
	for (int count = 0; count < tempLenght; count++) {
		steck.push(tempSteak.top());
		tempSteak.pop();
	}
}

void print(std::stack <int> &steck) {
	int lenght = steck.size();
	std::stack <int> tempSteak;
	for (int count = 0; count < lenght; count++) {
		std::cout << steck.top() << "\t";
		tempSteak.push(steck.top());
		steck.pop();
	}
	std::cout << std::endl;
	for (int count = 0; count < lenght; count++) {
		steck.push(tempSteak.top());
		tempSteak.pop();
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(0);

	std::stack <int> steck;

	int lenght{ 0 };

	std::cout << "Введите кол-ов элементов в стэке: ";
	std::cin >> lenght;
	std::cout << "Ввести вручную? (y = ДА, n = НЕТ)" << std::endl;
	std::string temp;
	std::cin >> temp;
	int tempint;
	if (temp == "y") {
		for (int count = 0; count < lenght; count++) {
			std::cin >> tempint;
			steck.push(tempint);
		}
	}
	else if (temp == "n") {
		for (int count = 0; count < lenght; count++) {
			steck.push(rand());
		}
	}
	print(steck);
	findMaxElem(steck);
	print(steck);
	bool quest = true;
	if (steck.size() == 1) {
		return 0;
	}
	while (quest) {
		if (steck.empty()) {
			break;
		}
		char quest2;
		std::cout << "\nВы хотите удалить последний элемент из стэка? (y = ДА, n = НЕТ)" << std::endl;
		std::cin >> quest2;
		if (quest2 == 'y') {
			if (!steck.empty()) {
				steck.pop();
				print(steck);
				findMaxElem(steck);
			}
			else if (steck.empty()) {
				quest = false;
			}
		}
		else if (quest2 == 'n') {
			quest = false;
		}
	}
	return 0;
}
