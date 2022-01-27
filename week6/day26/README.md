## any_of case complexities
For the any_of algorithm, the worst case would be having to search the entire array and spawning too many threads. This happens most when the algorithm 
returns false. In this case, none of the elements would satisfy the predicate after checking the entire array. 


The best case would be if the algorithm returns true. This happens when the algorithm encounters an element that satisfies the predicate right away and 
exits the program early. This way, we wouldn't have to search the entire array. 



## none_of case complexities

For the none_of algorithm, the worst case would be having to search the entire array. This is usually the case for when the algorithm returns true, 
as you need to search the entire array in order to determine if none of the elements fit the criteria of the predicate. As with both any_of and 
none_of, the times complexities get worse as N (the number of elements) increases.


The best case would be if the algorithm returns false after finding an element that does satisfies the predicate and exits early. In this case, we 
wouldn't have to scan the entire array. 