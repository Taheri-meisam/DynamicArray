#include <iostream>

template <class T>
class DArray {
public:
	DArray();
	void instertAt(int index, T value);
	void addValue(const T& value);
	void expand();
	void removeAt(int index);
	int RetNumOfElements() const;
	T getAt(int index);
	void PopBack();
	~DArray();
	T* Arr;
private:
	int ArrayMax;
	int ArraySize;
	int Index;
	int NumOfElements;
};


template<class T>
DArray<T>::DArray()
{
	this->ArrayMax = 1;
	this->NumOfElements = 0;
	Arr = new T[ArrayMax];
}

template<class T>
void DArray<T>::instertAt(int index, T value)
{
}

template<class T>
void DArray<T>::addValue(const T& value)
{
	if (this->ArraySize < this->ArrayMax) {
		this->Arr[this->ArraySize++] = value;
	}
	else {
		std::cout << " Array is full, expanding !!!" << std::endl;
		this->expand();
		this->Arr[this->ArraySize++] = value;
	}
}



template<class T>
void DArray<T>::expand()
{
	ArrayMax += 1;
	T* tempArray = new T[ArrayMax];
	for (size_t i = 0; i < ArraySize; i++) {
		tempArray[i] = Arr[i];
	}
	delete[] Arr;
	Arr = tempArray;

}



template<class T>
void DArray<T>::removeAt(int index)
{
	size_t i = 0;
	bool del = false;
	T* tempRemoveArray = new T[ArrayMax];
	if (index <0 || index > ArrayMax)
		throw "Out of boundry";
	if (index == 0) {
		tempRemoveArray[0] = Arr[1];
		i++;
		del = true;
	}
	for (i; i < ArrayMax; i++) {
		if (i == index && i!=0) {
			tempRemoveArray[i] = Arr[i+1];
			i++;
			del = true;
		}
		else {
			if (del) {
				tempRemoveArray[i - 1] = Arr[i];
			}
			else {
				tempRemoveArray[i] = Arr[i];
			}
			
		}
	}
	ArrayMax--;
	delete[] Arr;
	Arr = tempRemoveArray;

}

template<class T>
int DArray<T>::RetNumOfElements() const
{
	return this->ArrayMax;
}

template<class T>
T DArray<T>::getAt(int index)
{
	if (index < 0 || index >= ArrayMax) 
		throw ("Out of boundry");
	return Arr[index];
}

template<class T>
void DArray<T>::PopBack()
{
	if (ArrayMax > 0) {
		Arr[--ArrayMax] = NULL;
	}
	else {
		std::cout << "array is empty" << std::endl;
	}
}

template<class T>
DArray<T>::~DArray()
{
	delete[] this->Arr;
}



int main() {

	DArray<int> Arr1;
	Arr1.addValue(1);
	Arr1.addValue(2);
	Arr1.addValue(3);
	Arr1.addValue(4);
	Arr1.addValue(5);
	Arr1.addValue(6);
	Arr1.removeAt(0);
	for (size_t i = 0; i < Arr1.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << Arr1.getAt(i) << std::endl;
	}
	Arr1.PopBack();

	Arr1.removeAt(1);
	DArray<char> charArray;
	charArray.addValue('a');
	std::cout << "Size of array :" << Arr1.RetNumOfElements() << std::endl;
	for (size_t i = 0; i < Arr1.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << Arr1.getAt(i) << std::endl;
	}
	for (size_t i = 0; i < charArray.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << charArray.getAt(i) << std::endl;
	}
	system("pause");
	return 0;
}
