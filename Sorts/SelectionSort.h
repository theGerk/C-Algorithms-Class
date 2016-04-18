template <typename arrayType FUNCTION_IN_TEMPLATE>
static arrayType& SelectionSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	for (size_t i = 0; i < argLength; i++)
	{
		size_t least = i;
		for (size_t j = i + 1; j < argLength; j++)
			if (LESS_THAN(arg[j], arg[least]))
				least = j;
		std::swap(arg[least], arg[i]);
	}
	return arg;
}