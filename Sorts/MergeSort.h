namespace MergeSortHelper
{
	//do some debuging to make sure this function works...

	template <typename arrayType FUNCTION_IN_TEMPLATE>
	static arrayType& parse(arrayType& _array, const size_t startA, const size_t startB, const size_t SIZE FUNCTION_IN_SIGNATURE)
	{
#define end (startA + SIZE)
		size_t a = startA;
		size_t outputIndex = 0;
		size_t b = startB;
		size_t* output = new size_t[SIZE];

		while(true)
		{
			if (a == startB)
			{
				while (b < end)
					output[outputIndex++] = b++;
				break;
			}
			else if (b == end)
			{
				while (a < startB)
					output[outputIndex++] = a++;
				break;
			}
			else
			{
				if (LESS_THAN(_array[a], _array[b]))
					output[outputIndex++] = a++;
				else
					output[outputIndex++] = b++;
			}
		}


		//probably could optimize this
		for (outputIndex = 0; outputIndex < SIZE; outputIndex++)
		{
			std::swap(_array[startA + outputIndex], _array[output[outputIndex]]);
			std::swap(output[outputIndex], output[output[outputIndex] - startA]);
		}

		delete[] output;

		return _array;
#undef end
	}

	template<typename arrayType FUNCTION_IN_TEMPLATE>
	static arrayType& split(arrayType& _array, size_t start, size_t length FUNCTION_IN_SIGNATURE)
	{
		size_t halfway = length / 2;
		if (halfway > 1)
			split(_array, start, halfway PASS_LESS_THAN);
		if (length - halfway > 1)
			split(_array, start + halfway, length - halfway PASS_LESS_THAN);
		return parse(_array, start, start + halfway, length PASS_LESS_THAN);
	}
}


template <typename arrayType FUNCTION_IN_TEMPLATE>
static inline arrayType& MergeSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	return MergeSortHelper::split(arg, 0, argLength PASS_LESS_THAN);
}