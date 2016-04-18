
namespace HeapSortHelper
{
#ifndef _SORTS_HEAPSORT_
#define _SORTS_HEAPSORT_
	static inline size_t parent(size_t index)
	{
		return (index - 1) / 2;
	}

	static inline size_t child(size_t index)
	{
		return index * 2 + 1;
	}
#endif

	template<typename arrayType FUNCTION_IN_TEMPLATE>
	static inline void siftUp(arrayType& input, size_t indexAddedIn FUNCTION_IN_SIGNATURE)
	{
		for (size_t p; LESS_THAN(input[p = parent(indexAddedIn)], input[indexAddedIn]); indexAddedIn = p)
			std::swap(input[p], input[indexAddedIn]);
	}

	template<typename arrayType FUNCTION_IN_TEMPLATE>
	static inline void siftDown(arrayType& input, size_t index FUNCTION_IN_SIGNATURE)
	{
		std::swap(input[0], input[index]);

		for (size_t i = 0, c; (c = child(i)) < index; i = c) {
			if (c + 1 < index)
			{
				if (LESS_THAN(input[c + 1], input[c]))
				{
					if (LESS_THAN(input[i], input[c + 1]) || LESS_THAN(input[c], input[i]))
					{
						std::swap(input[i], input[c]);
					}
					else
					{
						break;
					}
				}
				else
				{
					if (LESS_THAN(input[i], input[c]) || LESS_THAN(input[i], input[c + 1]))
					{
						std::swap(input[i], input[++c]);
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				if (LESS_THAN(input[i], input[c]))
				{
					std::swap(input[i], input[c]);
				}
				break;
			}
		}
	}
}

template<typename arrayType FUNCTION_IN_TEMPLATE>
static arrayType& HeapSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	for (size_t firstIndexOutOfHeap = 1; firstIndexOutOfHeap < argLength; firstIndexOutOfHeap++)
		HeapSortHelper::siftUp(arg, firstIndexOutOfHeap PASS_LESS_THAN);

	for (size_t firstIndexOutOfHeap = argLength - 1; firstIndexOutOfHeap > 0; firstIndexOutOfHeap--)
		HeapSortHelper::siftDown(arg, firstIndexOutOfHeap PASS_LESS_THAN);

	return arg;
}

