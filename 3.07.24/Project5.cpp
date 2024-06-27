#include <iostream>



#pragma region Stack
template <typename T>

class Stack {
	T* arr = new T;
	int length = 0;
	int counter = -1;

public:
	Stack() {}

	Stack(int length) {
		this->length = length;
		arr = new T[this->length];
	}

	Stack(int length, T arr[], int otherLength) {
		this->length = length;
		this->arr = new T[this->length];
		otherLength = (sizeof(arr) / sizeof(arr[0]));
		for (int i = 0; i < otherLength; i++) {
			this->arr[i] = arr[i];
			this->counter = otherLength - 1;
		}
	}
	void show() {
		for (int i = 0; i < this->counter + 1; i++) { 
			std::cout << this->arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void push_back(T val) {
		this->length++;
		this->counter++;
		T* tmp = new T(this->length);
		for (int i = 0; i < this->length-1;i++) {
			tmp[i] = arr[i];
		}
		tmp[this->counter] = val;
		arr = tmp;
		delete[]arr;

	}


	T pop() {
		T val = this->arr[this->counter];
		this->length--;
		this->counter--;
		T* tmp = new T(this->length);
		for (int i = 0; i < this->counter + 1;i++) {
			tmp[i] = arr[i];
		}
		arr = tmp;
		delete[]arr;
		return val;
	}
};
#pragma endregion


#pragma region Queue
template <typename T>

class Queue {
	T* arr = new T;
	int length = 0;
	int counter = -1;

public:
	Queue() {}

	Queue(int length) {
		this->length = length;
		arr = new T[this->length];
	}

	Queue(int length, T arr[], int otherLength) {
		this->length = length;
		this->arr = new T[this->length];
		otherLength = (sizeof(arr) / sizeof(arr[0]));
		for (int i = 0; i < otherLength; i++) {
			this->arr[i] = arr[i];
			this->counter = otherLength - 1;
		}
	}
	void show() {
		for (int i = 0; i < this->counter + 1; i++) { 
			std::cout << this->arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void push_back(T val) {
		this->length++;
		this->counter++;
		T* tmp = new T(this->length);
		for (int i = 0; i < this->length;i++) {
			tmp[i] = arr[i];
		}
		tmp[this->counter] = val;
		arr = tmp;
		delete[]arr;

	}


	T pop() {
		T val = this->arr[0];
		this->length--;
		this->counter--;
		T* tmp = new T(this->length);
		for (int i = 1; i < this->counter + 2;i++) {
			tmp[i - 1] = arr[i];
		}
		delete[]arr;
		arr = tmp;
		return val;
	}

};
#pragma endregion


#pragma region LinkedList

template <typename T>
class LinkedList {
public:
	struct Node {
		T val;
		std::shared_ptr<Node> next;
		Node(T val, Node* next) : val(val), next(nullptr) {}
	};

	std::shared_ptr<Node> head = nullptr;

	LinkedList() : head(nullptr) {}

	void show() {
		std::shared_ptr<Node> current = this->head;
		while (current != nullptr) {
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	void add(T val) {
		std::shared_ptr<Node> newNode = std::make_shared<Node>(val, nullptr);
		if (this->head == nullptr) {
			this->head = newNode;
		}
		else {
			std::shared_ptr<Node> current = this->head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void remove(T val) {
		if (this->head == nullptr) {
			return;
		}

		if (this->head->val == val) {
			this->head = this->head->next;
			return;
		}

		std::shared_ptr<Node> cur = this->head;
		std::shared_ptr<Node> prev = nullptr;

		while (cur != nullptr && cur->val != val) {
			prev = cur;
			cur = cur->next;
		}

		if (cur != nullptr) {
			prev->next = cur->next;
		}
	}
};

#pragma endregion


int main() {
	int array[10];

	std::cout << "Stack:" << std::endl;
	Stack<int>a(10, array, 3);
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(50);
	a.show();
	a.pop();
	a.pop();
	a.show();

	std::cout << "Queue:" << std::endl;
	Queue<int>b(10, array, 3);
	b.show();
	b.push_back(100);
	b.push_back(200);
	b.push_back(300);
	b.show();
	b.pop();
	b.show();

	std::cout << "LinkedList:" << std::endl;
	LinkedList <int> c;
	c.add(10);
	c.add(20);
	c.add(30);
	c.add(40);
	c.add(50);
	c.show();
	c.remove(20);
	c.show();

}