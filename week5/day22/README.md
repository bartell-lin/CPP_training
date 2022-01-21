By running the N body problem with N threads, the result varies depending on how large N is. For smaller N, the overhead of creating threads actually makes
it perform slower than without threads. But for larger N like 2000, we can start to see the threaded approach run faster than without threads.
Running the threaded program on low N values is the worst case as there is too much overhead to justify using threads. On the other hand, larger N values
would be the best case and allow for faster calculations as the overhead would be offset by the number of calculations being done in parallel. Another 
thing to consider it the amount of cores one's computer has. With fewer cores, the large amount of threads will be hindered by the lack of resources 
available for them to perform the calculations. As a result, using N threads will not 
make the code run N times as fast, but there is a faster runtime.