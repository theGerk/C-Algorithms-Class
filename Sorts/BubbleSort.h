
template<typename arrayType FUNCTION_IN_TEMPLATE>
static arrayType& BubbleSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	for (size_t i = 0; i < argLength; i++)
	{
		for (size_t j = argLength - 1; j > i; j--)
		{
			if (LESS_THAN(arg[j], arg[j - 1]))
			{
				std::swap(arg[j], arg[j - 1]);
			}
		}
	}
	return arg;
}