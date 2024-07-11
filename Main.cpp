#include <iostream>

template <typename  ANY>
class Array {
private:
	size_t size;
	ANY* data;
public:
	Array() : size(NULL), data(nullptr) {}

	Array(size_t size) : size(size) {
		if (size == 0) {
			data = nullptr;
			return;
		}
		data = new ANY[size]{};
	}
	
	Array(const std::initializer_list<ANY>& list) {
		size = list.size();
		data = new ANY[size];
		size_t i = 0;
		for (auto p : list)
			data[i++] = p;
	}

	Array(const Array& other) : size(other.size) {
		if (size == 0) {
			data = nullptr;
			return;
		}
		data = new ANY[size];
		for (size_t i{}; i < size; ++i)
			data[i] = other[i];
	}

	Array(Array&& other) : Array() {
		std::swap(size, other.size);
		std::swap(data, other.data);
	}

	~Array() { delete[] data; }

	void print() {
		for (size_t i{}; i < size; ++i)
			std::cout << data[i] << ", ";
		std::cout << std::endl;
	}

	size_t length() { return size; }

	ANY& operator[](size_t index) {
		return *(data + index);
	}

	ANY operator[](size_t index) const {
		return *(data + index);
	}
};

template <typename ANY, size_t size>

class Tuple {
private:
	ANY data[size]{};
public:
	
	size_t length() { return size; }


	ANY& operator[](size_t index) {
		return *(data + index);
	}

	ANY operator[](size_t index) const {
		return *(data + index);
	}
};

int sum(int counter, int first, ...) {
	int result = 0;
	int* firstp = &first;
	/*
	for (size_t i{}; i < counter; ++i)
		result += *(firstp + i);
		*/
	while (counter--) {
		result += *(firstp++);
		++firstp;
	}

	return result;
}


int  main() {
	setlocale(LC_ALL, "russian");

	Array<int> arr1(5);
	arr1.print();
	for (size_t i = arr1.length(); i > 0; --i)
		arr1[arr1.length() - i - 1] = i;
	arr1.print();

	Tuple<double, 5>arr2;
	arr2[1] = 7.2;
	std::cout << "arr2[1] = " << arr2[1] << std::endl;

	std::cout << sum(3, 10 , 15, 8) << std::endl;
	std::cout << sum(6, 5, 7, 9, 1, 1 ,1) << std::endl;

	Array<int> arr3 = {5, 7, 15, 42, 105};
	arr3.print();







	return 0;
}