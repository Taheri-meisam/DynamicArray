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
	bool RemoveElement(int indexOfItem);
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
	expand();
	int arrmax = ArrayMax - 1;
	bool flagInsert = false;
	if (index <0 || index > ArrayMax)
		throw "Out of boundry";
	T* tempArray = new T[ArrayMax];
	size_t i = 0;
	if (index == 0 && flagInsert==false) {
		tempArray[0] = value;
		i++;
		flagInsert = true;
		for (i; i < ArrayMax; i++) {
			tempArray[i] = Arr[i-1];
		}

	}
	if(index != arrmax && flagInsert == false ){
		for (i; i < arrmax; i++) {
			if (i != index && flagInsert == false) {
				tempArray[i] = Arr[i];
			}
			if (i == index && flagInsert == false) {

				tempArray[i] = value;
				i++;
				flagInsert = true;
			}
			if (flagInsert == true) {
				tempArray[i] = Arr[i - 1];
			}
		}
	}
	if (index == arrmax) {
		for (i; i < arrmax; i++) {
			tempArray[i] = Arr[i];
		}
		tempArray[arrmax] = value;

	}
	delete[] Arr;
	Arr = tempArray;


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
bool DArray<T>::RemoveElement(int indexOfItem)
{
	if (indexOfItem < 0 || indexOfItem >= ArrayMax) {
		throw "out of the array boundry";
		return false;
	}
	memmove(Arr + 1, Arr, sizeof(T) * indexOfItem);
	Arr[0] = NULL;
	return true;
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
	try {
		Arr1.RemoveElement(6);
	}
	catch (...) {
		std::cout << "Out of boundry index at RemoveElement function  !!!" << std::endl;
	}

	for (size_t i = 0; i < Arr1.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << Arr1.getAt(i) << std::endl;
	}
	std::cout << "Memmove ------" << std::endl;

	Arr1.instertAt(6, 2000);
	std::cout << "Number of elements :" << Arr1.RetNumOfElements()<< std::endl;



	for (size_t i = 0; i < Arr1.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << Arr1.getAt(i) << std::endl;
	}
	std::cout << "=====@@@@@@@@@@@@@=" << std::endl;

	//Arr1.removeAt(0);
	for (size_t i = 0; i < Arr1.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << Arr1.getAt(i) << std::endl;
	}

	std::cout << "==================================" << std::endl;

	Arr1.instertAt(0, 8);
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

	DArray<float> floatArray;

	for (int i = 0; i < 10; i++) {
		floatArray.addValue(i * 2.2);
	}

	for (size_t i = 0; i < floatArray.RetNumOfElements(); i++) {
		std::cout << "Index  " << i << " -> " << floatArray.getAt(i) << std::endl;
	}

	system("pause");
	return 0;
}
