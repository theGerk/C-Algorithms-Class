namespace QuickSortHelper {
	template<typename arrayType FUNCTION_IN_TEMPLATE>
	static arrayType& QuickSort(arrayType& _array, size_t start, size_t end FUNCTION_IN_SIGNATURE)
	{
		size_t swapPoint = start;
		for (size_t iterator = start + 1; iterator <= end; iterator++)
			if (LESS_THAN(_array[iterator], _array[start]))
				std::swap(_array[++swapPoint], _array[iterator]);
		std::swap(_array[swapPoint], _array[start]);
		if (start < swapPoint - 1)
			QuickSort(_array, start, swapPoint - 1 PASS_LESS_THAN);
		if (swapPoint + 1 < end)
			QuickSort(_array, swapPoint + 1, end PASS_LESS_THAN);
		return _array;
	}
}

template<typename arrayType FUNCTION_IN_TEMPLATE>
inline static arrayType& QuickSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	if (argLength > 1)
		return QuickSortHelper::QuickSort(arg, 0, argLength - 1 PASS_LESS_THAN);
	else
		return arg;
}