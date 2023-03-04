## About

Philosophers the main goal was to understand how threads works in language C and use them to solve a logical problem.
The simulation will stop if all philosophers have eaten enough or if one philosopher die.

- There are three different version of the algorithm :
    - Philo_one is about using threads and mutexs
    - Philo_two is about using threads and semaphores
    - Philo_three is about using processes and semaphores

`This project was code for MACOS`

### Building and running the project

1. Download/Clone this repo

        git clone https://github.com/Alex5067/philosophers
2. `cd` into the root directory and run `make`

        cd philosophers
        make

3.  run `./philo_x arg1 arg2 arg3 arg4 (arg5)` from the directory philo_x.
    - arg1 is the number of philosopher
    - arg2 is the time to die in ms
    - arg3 is the time to eat in ms
    - arg4 is the time to sleep in ms
    - arg5 (optional) is the number of time each philosopher needs to eat to end the simulation
    
