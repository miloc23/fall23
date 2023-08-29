# Lecture 3: more processes and unicode

Processs: abstraction of a running program

Limited Direct Execution (user-space vs kernel-space)

Restoring state after a mode swtich
    - registers mostly (but address space needs to be restored too)

Multiprogramming/time sharing

P1
P2
---
Kernel

Which process goes next? (scheduler)
    - not all processes are ready

process state

Kernel needs to keep track of process state


time sharing example
Program 1 is executing, when a timer interupt is raised.
    - mode switch from user --> kernel
    - lots of state saving happens in a mode switch

Linux
vdso
vsyscalls
- put some stuff onto a shared memory page instead of having to actually syscall

io_uring

context switches are expensive!
address space change is expensive becuase TLB cache invalidation

do we need a context switch when we do a syscall?
( i.e. from program to kernel)
- not necesarily
    - we can keep kernel address space alongside the user program address space
    - mode switch then access the protected pages
        - permissions check
    - how it was done for a long time

context switch vs mode switch
- context switch switches address space
- mode switch changes from user to kernel

2018 Meltdown Side channel/transient execution
1. user space wants to read something from kernel
2. CPU puts the data into a cache (microarchitectural side channel)
3. Then checks protections
4. Can read back cache information based on timings

This led to KPTI (Kernel Page Table Isolation)
- two address space: user and user/kernel one

Process States


Unicode
What is a character and how do you represent it?

old days ASCII
- 7 bits
- 1 char = 1 byte

Unicde: character = code point
    - 1,114,112 code points
    - need 21 bits to cover all
    
UTF-32 : use 32 bit ints to represent a single character - Python 3, Linux wchar_t, c11 char32_t
- really space inefficient (4x more space than ascii)
+ all code points
+ uniform (indexing over a string S[i])

UTF-16: Java and Javascript -> charSequence.CodePoints
    uses 2 bytes for most, 4 bytes for some
+ saved some space
- S[i] is not always the ith character
    - error-prone 

UTF-8
- variable length encoding
+ space efficient if using common code points (ASCII strings are valid UTF-8)
- indexing is hard

given bytes, can you tell what encoding? NO!
    - can tell if it's invalid
    - use metadata : content-type: text/html;charset=UTF-8



