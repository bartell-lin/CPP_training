After running experiments varying M from 1 to 8, I found that in this particular case, I was better off without threads. The more threads I used, the more
time it took for the program to run. The increase seemed to be linear as the more threads I had, the more time it took. My computer has 2 cores, so I can 
run 2 threads comfortably. This is shown in the outcome as running the experiment with 1 or 2 threads has similar times, with 2 threads taking a bit longer.
Between 2 threads and 3 threads, the time to complete took a jump from a .2ms difference to a 1.4ms difference. In this particular case, running the 
program without threads is the way to go.