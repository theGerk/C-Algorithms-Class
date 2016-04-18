template<typename arrayType FUNCTION_IN_TEMPLATE>
static arrayType& InsertionSort(arrayType& arg, size_t argLength FUNCTION_IN_SIGNATURE)
{
	for (size_t i = 1; i < argLength; i++)
	{
		auto val = arg[i];
		size_t j;

		for (j = i; j > 0 && LESS_THAN(val, arg[j - 1]); j--)
		{
			arg[j] = arg[j - 1];
		}
		arg[j] = val;
	}

	return arg;
}