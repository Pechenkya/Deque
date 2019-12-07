#pragma once

template<typename T, int max_size = 10>
class LimVec
{
	T* arr[max_size] = { nullptr };
	int size;

	void swap(int a, int b);
public:

	bool is_empty();
	bool is_filled();
	int get_size();

	void push_back(T elem);
	void push_pointer_front(T* elem);
	void push_front(T elem);

	template<typename... Args>
	void emplace_back(Args&&... args);
	template<typename... Args>
	void emplace_front(Args&&... args);
	template<typename... Args>
	void emplace(int pos, Args&&... args);

	T& operator[](int pos);
	T& at(int pos);

	T& front();
	T& back();
	void nullout_last();

	void insert_before(T elem, int pos);
	void remove_at(int pos);

	void pop_front();
	void pop_back();

	LimVec();
	~LimVec();
};

template<typename T, int max_size>
void LimVec<T, max_size>::swap(int a, int b)
{
	T* temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

template<typename T, int max_size>
bool LimVec<T, max_size>::is_empty()
{
	return size == 0;
}

template<typename T, int max_size>
bool LimVec<T, max_size>::is_filled()
{
	return size == max_size;
}

template<typename T, int max_size>
int LimVec<T, max_size>::get_size()
{
	return this->size;
}

template<typename T, int max_size>
void LimVec<T, max_size>::push_back(T elem)
{
	if(size < max_size)
		arr[++size - 1] = new T(elem);
}

template<typename T, int max_size>
void LimVec<T, max_size>::push_pointer_front(T * elem)
{
	if (size < max_size)
	{
		size++;
		for (int k = size - 1; k > 0; k--)
		{
			swap(k, k - 1);
		}
		arr[0] = elem;
	}
}

template<typename T, int max_size>
void LimVec<T, max_size>::push_front(T elem)
{
	if (size < max_size)
	{
		size++;
		for (int k = size - 1; k > 0; k--)
		{
			swap(k, k - 1);
		}
		arr[0] = new T(elem);
	}
}

template<typename T, int max_size>
T & LimVec<T, max_size>::operator[](int pos)
{
	if(pos < size)
		return *(arr[pos]);
}

template<typename T, int max_size>
T & LimVec<T, max_size>::at(int pos)
{
	if (pos < size)
		return *(arr[pos]);
}

template<typename T, int max_size>
T & LimVec<T, max_size>::front()
{
	return *arr[0];
}

template<typename T, int max_size>
T & LimVec<T, max_size>::back()
{
	return *arr[size - 1];
}

template<typename T, int max_size>
void LimVec<T, max_size>::nullout_last()
{
	arr[--size] = nullptr;
}

template<typename T, int max_size>
void LimVec<T, max_size>::insert_before(T elem, int pos)
{
	if (size < max_size)
	{
		size++;
		for (int k = size - 1; k != pos; k--)
			arr[k] = arr[k - 1];
		arr[pos] = new T(elem);
	}
}

template<typename T, int max_size>
void LimVec<T, max_size>::remove_at(int pos)
{
	if (pos < size)
	{
		delete arr[pos];
		arr[pos] = nullptr;
		size--;
		for (int k = pos; k < size - 1; k++)
			swap(k, k + 1);
	}
}

template<typename T, int max_size>
void LimVec<T, max_size>::pop_front()
{
	delete arr[0];
	arr[0] = nullptr;
	for (int k = 0; k < size; k++)
		swap(k, k + 1);
	--size;
}

template<typename T, int max_size>
void LimVec<T, max_size>::pop_back()
{
	delete arr[--size];
	arr[size] = nullptr;
}

template<typename T, int max_size>
LimVec<T, max_size>::LimVec()
{
	size = 0;
}

template<typename T, int max_size>
LimVec<T, max_size>::~LimVec()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
}

template<typename T, int max_size>
template<typename ...Args>
void LimVec<T, max_size>::emplace_back(Args && ...args)
{
	if (size < max_size)
		arr[++size - 1] = new T(std::forward<Args>(args)...);
}

template<typename T, int max_size>
template<typename ...Args>
void LimVec<T, max_size>::emplace_front(Args && ...args)
{
	if (size < max_size)
	{
		size++;
		for (int k = size - 1; k > 0; k--)
		{
			swap(k, k - 1);
		}
		arr[0] = new T(std::forward<Args>(args)...);
	}
}

template<typename T, int max_size>
template<typename ...Args>
void LimVec<T, max_size>::emplace(int pos, Args && ...args)
{
	if (size < max_size)
	{
		size++;
		for (int k = size - 1; k != pos; k--)
			arr[k] = arr[k - 1];
		arr[pos] = new T(std::forward<Args>(args)...);
	}
}
