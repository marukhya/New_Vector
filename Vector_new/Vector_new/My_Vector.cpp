#include <iostream>

template <typename T>
class My_Vector
{
private:
	T* arr;
	int capacity;
	int size;
public:
	My_Vector()
	{
		arr = new T[1];
		capacity = 1;
		size = 0;
	}

	void push(T data)
	{
		if (size == capacity)
		{
			T* temp = new T[2 * capacity];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[size] = data;
		size++;
	}

	void push(T data, int index)
	{
		if (index == capacity)
		{
			push(data);
		}
		else
		{
			arr[index] = data;
		}
	}

	T get(int index)
	{
		if (index < size)
		{
			return arr[index];
		}
	}

	void pop()
	{
		size--;
	}

	int size_of()
	{
		return size;
	}

	int capacity_of()
	{
		return capacity;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	My_Vector<int> v_int;
	My_Vector<char> v_char;
	v_int.push(10);
	v_int.push(20);
	v_int.push(30);
	v_int.push(40);
	v_int.push(50);
	v_char.push(71);
	v_char.push(72);
	v_char.push(73);
	v_char.push(74);
	std::cout << "Integer vector size is : " << v_int.size_of() << std::endl;
	std::cout << "Integer vector capacity is : " << v_int.capacity_of() << std::endl;
	std::cout << "Vector Elements : ";
	v_int.print();
	std::cout << "\nAfter updating 1st index" << std::endl;

	std::cout << "Vector elements of type int : " << std::endl;
	v_int.push(100, 1);
	v_int.print();
	std::cout << "Vector elements of type char : " << std::endl;
	v_char.print();
	std::cout << "Element in 1st index(Integer vector)" << v_int.get(1) << std::endl;
	std::cout << "Element in 1st index(Char vector)" << v_char.get(1) << std::endl;
	v_int.pop();
	v_char.pop();

	std::cout << "\nAfter deleting last element" << std::endl;
	std::cout << "Vector size of type int: " << v_int.size_of() << std::endl;
	std::cout << "Vector size of type char: " << v_char.size_of() << std::endl;
	std::cout << "Vector capacity of type int: " << v_int.capacity_of() << std::endl;
	std::cout << "Vector capacity of type char: " << v_char.capacity_of() << std::endl;
	std::cout << "Vector elements of type int: ";
	v_int.print();
	std::cout << "Vector elements of type char: ";
	v_char.print();
}