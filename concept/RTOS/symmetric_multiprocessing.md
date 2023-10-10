# Symmetric Multiprocessing

SMP (Symmetric Multiprocessing) is a computing architecture where two or more identical CPUs (cores) are connected to a single shared main memory and controlled by a single operating system. In general, an SMP system…

has multiple cores running independently. Each core has its own register file, interrupts, and interrupt handling.

presents an identical view of memory to each core. Thus a piece of code that accesses a particular memory address has the same effect regardless of which core it runs on.


## Advantage
The main advantages of an SMP system compared to single core or Asymmetric Multiprocessing systems are that…

- the presence of multiple CPUs allows for multiple hardware threads, thus increases overall processing throughput.

- having symmetric memory means that threads can switch cores during execution. This in general can lead to better CPU utilization.

Although an SMP system allows threads to switch cores, there are scenarios where a thread must/should only run on a particular core. Therefore, threads in an SMP system also have a core affinity that specifies which particular core the thread is allowed to run on.

A thread that is pinned to a particular core is only be able to run on that core

A thread that is unpinned will be allowed to switch between cores during execution instead of being pinned to a particular core.