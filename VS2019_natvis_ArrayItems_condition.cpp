#include <stdio.h>
#include <vector>

template<class T>
struct Array1 {
	const size_t n = 0;
	T* const p = nullptr;

	explicit Array1(std::initializer_list<T> items) :n(items.size()), p(new T[this->n]) {
		const T* src = items.begin();
		for (size_t i = 0; i < this->n; ++i) this->p[i] = src[i];
	}

	~Array1() { delete[] this->p; }
};

template<class T>
struct Array2 {
	const size_t n = 0;
	T* const p = nullptr;

	explicit Array2(std::initializer_list<T> items) :n(items.size()), p(new T[this->n]) {
		const T* src = items.begin();
		for (size_t i = 0; i < this->n; ++i) this->p[i] = src[i];
	}

	~Array2() { delete[] this->p; }
};

int main() {
	std::vector<int> test_vec{ 1, 2, 3, 4, 5, 6, 7, 8 };
	Array1<int> test_array1{ 1, 2, 3, 4, 5, 6, 7, 8 };
	Array2<int> test_array2{ 1, 2, 3, 4, 5, 6, 7, 8 };

	printf("breakpoint this line\n");
}
