# OS Project

## Implementation of kernel level threads and scheduling algorithms

### Contributors :

This was done as SE OS Project by Vatsal Soni,Yashodhan Joshi, Yatharth Vyas.

### We are thankful for repo <a href='https://github.com/dthain/basekernel'>Basekernel</a> upon which we have built this project.

### About

We used an open source basic kernel that was available on GitHub : basekernel. It has some basic functions such as Round Robin Scheduling, a basic shell,and some system call such as fork,exec,etc. We then implemented Syscalls in the Kernel to make a new thread and start running given function to it.
We based the thread design after linux kernel-level thread structure, where thread is basically a lightweight process, which shares the page-tables and file descriptors with the process that created them.
We also created function as wrappers for the syscalls, similar to pthread api.

We then implemented various Scheduling policies for the process/thread scheduling in kernel. By default the kernel would use a Round- Robin policy, which we changed with :

<ol>
<li>Priority Scheduling, No preemption. (P with FCFS) With fixed priorities</li>
<li>Priority Scheduling, With Preemption (P with RR) With Fixed priorities</li> 
<li>Priority Scheduling, With Preemption (P with RR) With Dynamically assigned and changing priorities.</li>
</ol>

First two approaches use standard priority scheduling with normal FCFS and RR techniques.
After that we tried to implement an algorithms that can change priority assigned to a process/thread dynamically ( while running) and schedule next process/thread as per the priorities with RR, which can be said to be similar with multi-stage feed back queue type scheduling.
In this,instead of ‘priority’ we designed a penalty system, and the process with lowest penalty is the process of highest priority.

For this we considered two assumption:

<ol>
<li>Any process ideally, must complete as soon as possible, and the more time it takes to complete, it will go on having less and less priority as per the multi-stage feed back queue policy.</li>
<li>Any process making syscall must be given penalty , as it takes time to switch from user level to kernel level to complete the syscall and then to switch back again to user level. The penalty given will depend on the syscall made, as the syscall to exit or yield process actually stops the process’s execution, and thus should be given less penalty and syscall related to user(or in-general) IO can take long time, and should be given more penalty.</li>
</ol>

Thus according to these we give a penalty of some measure, every n<sup>th</sup> time the process is scheduled (as it is rare to complete the work in single allotted time-slice), and for every syscall made, acording to the syscall made, until a saturation level is reached , after which no penalty is applied.

The process with least penalty is scheduled first, and between processes of same penalty level, RR is applied. In case a process makes a syscall with IO request, it is heavily penalized, making it with lower priority wrto others, but if other keep running for a long time , even without a syscall requirement, they will be given penalty and finally be on same level as the one which made the IO request.

Thus this guarantees that within same priority level no starvation will occur, but can occur for lower priority process , i.e. which are making large amount of syscalls , but if not many new processes are incoming, eventually all will be of same priority and thus even that starvation will not occur and eventually all processes will be scheduled with same time slice.

### NOTE : This was done as a learning project for Operating Systems, and may not be (probably is not) the optimal or best or optimized solution.
