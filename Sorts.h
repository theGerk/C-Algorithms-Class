#ifndef _SORTS_
namespace Sort 
{
#define PASS_LESS_THAN , lessThan
#define LESS_THAN(A, B) (lessThan((A), (B)))
#define FUNCTION_IN_TEMPLATE ,typename funcType
#define FUNCTION_IN_SIGNATURE ,const funcType& lessThan
#include "Sorts\BubbleSort.h"
#include "Sorts\HeapSort.h"
#include "Sorts\InsertionSort.h"
#include "Sorts\MergeSort.h"
#include "Sorts\QuickSort.h"
#include "Sorts\SelectionSort.h"
#undef PASS_LESS_THAN
#undef LESS_THAN
#undef FUNCTION_IN_TEMPLATE
#undef FUNCTION_IN_SIGNATURE
#define PASS_LESS_THAN
#define LESS_THAN(A, B) ((A) < (B))
#define FUNCTION_IN_TEMPLATE
#define FUNCTION_IN_SIGNATURE
#include "Sorts\BubbleSort.h"
#include "Sorts\HeapSort.h"
#include "Sorts\InsertionSort.h"
#include "Sorts\MergeSort.h"
#include "Sorts\QuickSort.h"
#include "Sorts\SelectionSort.h"
#undef PASS_LESS_THAN
#undef LESS_THAN
#undef FUNCTION_IN_TEMPLATE
#undef FUNCTION_IN_SIGNATURE
}
#define _SORTS_
#endif