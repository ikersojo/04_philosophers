# 04_philosophers

# Introduction
In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.
The project is focused on introducing the concept of shared computer resources by multiple processes running at the same time (concurrent or parallel programming). The aim is to make the best possible use of the existing shared resources, to allow the processes to co-exist as long as possible.

The mandatory part of the project will make the philosophers share the resources (forks), using threads and [mutex](https://en.wikipedia.org/wiki/Mutual_exclusion) (Mutual exclusion). The bonus part of the philosophers project replicates the same output but using processes (as in Pipex prject) and semaphores.

---
# Explanation of the Subject
The subject can be found [here](https://github.com/ikersojo/04_philosophers/blob/main/doc/es.subject.pdf) (in Spanish).

## Context
One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table. Serving and eating spaghetti with a single fork is very inconvenient, so **the philosophers will eat with two forks, one for each hand.**
- Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
- Every philosopher needs to eat and they should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- No need to say that philosophers should avoid dying!

## Goal of the project
The goal of the project is to write a program with a sequencing logic, so that the philosophers optimize their eating turns, to avoid the death of any of them. Note that the philosophers cannot communicate between them.

## User input arguments
```
./philo arg1 arg2 arg3 arg4 (arg5)
```

- number_of_philosophers: is the number of philosophers and also the number of forks.
- time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after **starting their last meal or the beginning of the simulation**, it dies.
- time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
- time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
- (optional) number_of_times_each_philosopher_must_eat: if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

Note that the time to think is not specified, so it is assumed that they will tink only until they can eat.

## Output log
Each time a philosopher takes an action, our program must print a message formatted this way:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
## New alowed functions
- printf is now allowed, ue to the use of long printing with %ld (included in stdio.h).
- usleep and gettimeofday to manage time (included in sys/time.h).
- pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock and pthread_mutex_unlock to manage threads (included in pthread.h).

See last sections of this page for details in new 2 key concpets for this project.

---
# Program layout and steps

## 00_main

Launch all main functions listed below and wiat for the threads/processes to end.

## 01_input_check

Check that the input introduced by the user is correct.

## 02_init_data

Allocate memory and initialize data struct (and its components).
Note that all the variables of the program are contained in the data struct (see the *.h files to see the content).

## 03_setup_threads

Prepare all the conditions before launching the simulations

## 04_launch_threads

Start the simulation.

## 05_actions

The main actions a philosopher has to carry out: attempt to pick the forks, eat, sleep and think.
Also, die.

## AUX
### 06_time



### 99_libft_extract

This project does not allow Libft, so the required functions have been extracted.
Since exit() is not allowed in mandatory part, the function ft_exit_w_error() has been replaced by ft_print_error().

---
# Bonus

The bonus achieves the same result, but instead of using threads, child porcesses are launched (note that child processes do not need to be joined, since exit function can be used). Instead of mutexes, semaphores are used. Note that to check if a philosopher has died while waiting for a fork, since the sem_wait will stop the simulation form stoping, this function is launched in a different thread, while the main thread on each process is checkng ot has died while the sempahore is blocking the auxiliary thread.

---
# Score
TBD...

---
# New concept: Concurrent programming and threads

## Concurrent / Parallel Programming

Concurrent programming allows the same program to carry out instructions simultaneously, without working in sequence (as we have seen so far). Of course, several set of insturctions will be conducted in sequence, but multiple sets of such different instructions could be performed at the same time. The key advantage is that the programs can execute instructions much faster, and th emain drawback is the management required to avoid issues related to the nature of the concurrency itself, where the same resources (e.g. defined variables) might be required at the same time. This is the key aspect to be managed by the project using mutex.

## Threads
A thread is a basic unit of CPU utilization. It is a set of instructions inside a process. A traditional sequential process is equal to a task with one thread (single-threaded).
A single process can have multiple threads, sharing the code, the heap and file descriptors, while keeping dedicated thread ID, stack, cpu registry and instruction pointer. This allows for a faster communication and execution times between them than in-between processes.
The OS supports the multiple processes, and the multiple threads on each process, managinf the shared resources.

<img width="700" src="./doc/imgs/threads_example.png\?raw\=true">

In C **pthread.h** library needs to be included to manage threads. Also, in order to compile a program using this library, and additional option is required:

```
gcc -pthread main.c
```

### pthread_create
```c
int	pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

	<pthread_t *thread>  ID of the thread
	<const pthread_attr_t *attr>  NULL (default attributes)
	<void *(*start_routine)(void *)>  the function where the thread will start its execution.
	<void *arg>  only argument to pass to start_routine function

DESCRIPTION
The pthread_create() function is used to create a new thread, with attributes specified by attr,
within a process. If attr is NULL, the default attributes are used.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
NOTE: the thread id is contained within the pthread_t data type (struct), not in the return.
```
The start_routine function is prototyped as:
```c
void	*function_name(void *arg)
```

### pthread_join
```c
int	pthread_join(pthread_t thread, void **value_ptr);

	<pthread_t thread>  ID of the thread
	<void **value_ptr>  NULL (the function pthread_exit() is not allowed by the subject)

DESCRIPTION
The pthread_join() function suspends execution of the calling thread until the target thread
terminates unless the target thread has already terminated.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

### pthread_detach

Rather than waiting for the thread to finish and joining the main thread, this function tell
the OS to reclaim all resources by this thread just after it finishes execution.

```c
int	pthread_detach(pthread_t thread);

DESCRIPTION
The pthread_detach() function is used to indicate to the implementation that storage for the thread
thread can be reclaimed when the thread terminates.  If thread has not terminated, pthread_detach()
will not cause it to terminate.  The effect of multiple pthread_detach() calls on the same target
thread is unspecified.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

## Data Race (main issue to manage in concurrent programming)

A [race condition](https://en.wikipedia.org/wiki/Race_condition) can arise in software when a computer program has multiple code paths that are executing at the same time. If the multiple code paths take a different amount of time than expected, they can finish in a different order than expected, which can cause software bugs due to unanticipated behavior.

The data race it refers to a situation where a memory operation in one thread could potentially attempt to access a memory location at the same time that a memory operation in another thread is writing to that memory location: if two threads write to a memory location at the same time, it may be possible for the memory location to end up holding a value that is meaningless, and this providing wrong results.

## Mutex
A mutex (short for “mutual exclusion”) is essentially a lock that allows to manage access to data and prevent shared resources being used at the same time.

Mutexes are the means to avoid data races, by setting locks on resources, only allowing threads to access them when they are not lock by another thread. Note that they waste CPU time because a mutex lock sits testing the mutex.

A mutex must be initialized and destroyed, and will be used to check the access condition of the memory.

### pthread_mutex_init and pthread_mutex_destroy

```c
int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

	<pthread_mutex_t *mutex>  the pointer to a variable of pthread_mutex_t type.
	<const pthread_mutexattr_t *attr> NULL (default attributes)

DESCRIPTION
The function creates a new mutex, with attributes specified with attr.
If attr is NULL the default attributes are used.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

```c
int		pthread_mutex_destroy(pthread_mutex_t *mutex);

DESCRIPTION
The function frees the resources allocated for mutex.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

### pthread_mutex_lock and pthread_mutex_unlock

```c
int		pthread_mutex_lock(pthread_mutex_t *mutex);

DESCRIPTION
The function locks mutex. If the mutex is already locked, the calling thread will block
until the mutex becomes available.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

```c
int	pthread_mutex_unlock(pthread_mutex_t *mutex);

DESCRIPTION
If the current thread holds the lock on mutex, then the pthread_mutex_unlock() function
unlocks mutex. Calling pthread_mutex_unlock() with a mutex that the calling thread does
not hold will result in undefined behavior.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

## Deadlocks

Beware that mutexes can generate deadlocks, in which each thread waits for a resource held by another thread concurrenlty. One of the main challenges of the project is to avoid deadlocks waiting for several resource that might be own by other threads.

---
# New concept: Sempahores

Semaphores are opened as a file descriptor, and can be acceses form all processes / threads. The main advantage is that it can have a counter to dinamically wait/post their value, simplifing problem where the total amount of resources are shared by a porportional amount, to a defined number of porcesses/threads. The main disadvantage on this porject, is that sem_trywait cannot be used, the process will be always blocked.

```c
#include <semaphore.h>
sem_t	*sem_open(const char *name, int oflag, ...);
int	sem_close(sem_t *sem);
int	sem_unlink(const char *name);

DESCRIPTION
The named semaphore named name is initialized and opened as specified by the argument oflag and a
semaphore descriptor is returned to the calling process.

The value of oflag is formed by oring the following values:

	O_CREAT         create the semaphore if it does not exist
	O_EXCL          error if create and semaphore exists

If O_CREAT is specified, sem_open() requires an additional two arguments.  mode specifies the
permissions for the semaphore as described in chmod(2) and modified by the process umask value (see
umask(2)).  The semaphore is created with an initial value, which must be less than or equal to
SEM_VALUE_MAX.

If O_EXCL is specified and the semaphore exists, sem_open() fails.  The check for the existence of the
semaphore and the creation of the semaphore are atomic with respect to all processes calling sem_open()
with O_CREAT and O_EXCL set.

When a new semaphore is created, it is given the user ID and group ID which correspond to the effective
user and group IDs of the calling process. There is no visible entry in the file system for the created
object in this implementation.

The returned semaphore descriptor is available to the calling process until it is closed with
sem_close(), or until the caller exits or execs.

If a process makes repeated calls to sem_open(), with the same name argument, the same descriptor is
returned for each successful call, unless sem_unlink() has been called on the semaphore in the interim.
With sem_unlink() the named semaphore named name is removed.  If the semaphore is in use by other processes,
then name is immediately disassociated with the semaphore, but the semaphore itself will not be removed until
all references to it have been closed.  Subsequent calls to sem_open() using name will refer to or create a
new semaphore named name.

If sem_open() fails for any reason, it will return a value of SEM_FAILED and sets errno.  On success,
it returns a semaphore descriptor.
```

```c
#include <semaphore.h>
int	sem_wait(sem_t *sem);

DESCRIPTION:
The semaphore referenced by sem is locked.  When calling sem_wait(), if the semaphore value is zero,
the calling thread will block until the lock is acquired or until the call is interrupted by a signal.
Alternatively, the sem_trywait() function will fail if the semaphore is already locked, rather than
blocking on the semaphore.

If successful (the lock was acquired), sem_wait() and sem_trywait() will return 0.  Otherwise, -1 is
returned and errno is set, and the state of the semaphore is unchanged.
```

```c
#include <semaphore.h>
int	sem_post(sem_t *sem);

DESCRIPTION
The semaphore referenced by sem is unlocked, the value of the semaphore is incremented, and all threads
which are waiting on the semaphore are awakened.
sem_post() is reentrant with respect to signals and may be called from within a signal hanlder.
If successful, sem_post() will return 0.  Otherwise, -1 is returned and errno is set.
```

---
# New concept: Manage System Time

Management of the current time needs to be managed. In C, **sys/time.h** library needs to be included to manage time. In order to operate with waiting times, the **unistd.h** library is requried.

```c
int	gettimeofday(struct timeval *restrict tp, void *restrict tzp);

DESCRIPTION
The system notion of the current Greenwich time and the current time zone is obtained with
the gettimeofday() call. The time is expressed in seconds + microseconds 
since 00:00, January 1, 1970, defined as:

struct	timeval {
	time_t   	tv_sec;   /* seconds since Jan. 1, 1970 */
	suseconds_t	tv_usec;  /* and microseconds */
};

For timezone (*tzp), it is not in use anymore, so just use NULL.
The timeval structure specifies a time value in seconds and microseconds.
```
Note that the time needs to be managed in miliseconds, so a function to request the time in miliseconds since January 1 1970, is required to operate with time intervals.

```c
int	usleep(useconds_t microseconds);

DESCRIPTION
The usleep() function suspends execution of the calling thread until either
"microseconds" microseconds have elapsed.

RETURN VALUES
If successful, the function will return zero.
Otherwise an error number will be returned to indicate the error.
```

---
# Resources / further info

https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/

https://www.cs.miami.edu/home/visser/Courses/CSC322-09S/Content/UNIXProgramming/UNIXThreads.shtml