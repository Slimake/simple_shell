Simple_SHell Project

General
1.Who designed and implemented the original Unix operating system?
2.Who wrote the first version of the UNIX shell?
3.Who invented the B programming language (the direct predecessor to the C programming language)?
4.Who is Ken Thompson?
5.How does a shell work?
6.What is a pid and a ppid?
7.How to manipulate the environment of the current process?
8.What is the difference between a function and a system call?
9.How to create processes?
10.What are the three prototypes of main?
11.How does the shell use the PATH to find the programs?
12.How to execute another program with the execve system call?
13.How to suspend the execution of a process until one of its children terminates?
14.What is EOF / “end-of-file”?

---------------------------

UNIX Operating System:
The original Unix operating system was designed and implemented by a group of developers at AT&T's Bell Labs in the late 1960s and early 1970s. The key figures involved in its creation were Ken Thompson, Dennis Ritchie, Brian Kernighan, and others. They developed Unix as a multitasking, multi-user operating system primarily written in the C programming language. Unix quickly gained popularity and became the foundation for many other operating systems, including Linux.

First version of the UNIX shell:
The first version of the UNIX shell, called the "Thompson shell" or "sh," was written by Ken Thompson in 1971. It provided a command-line interface for interacting with the Unix operating system.

Invention of the B programming language:
The B programming language was created by Ken Thompson in the early 1970s. B was a simplified and typeless version of the BCPL programming language and was used as the predecessor to the C programming language.

Ken Thompson:
Ken Thompson is a computer scientist and one of the key pioneers in the development of the Unix operating system. He played a significant role in the creation of Unix and also co-invented the B programming language, which later led to the development of the C programming language. Thompson's work has had a profound impact on the field of computer science.

How a shell works:
A shell is a command-line interpreter that allows users to interact with the operating system. When you open a terminal or command prompt, you are typically running a shell. The shell reads commands from the user, interprets them, and then executes the corresponding operations. It acts as an intermediary between the user and the operating system, providing an interface to run commands, manipulate files, and manage processes.

PID and PPID:
PID stands for "Process ID," and it is a unique identifier assigned to each running process in an operating system. The PID allows the operating system to keep track of different processes and manage their execution.

PPID stands for "Parent Process ID." It represents the PID of the parent process that created a particular process. When a new process is created, it inherits the PPID of its parent process.

Manipulating the environment of the current process:
In Unix-like systems, you can manipulate the environment of the current process by setting environment variables. Environment variables are used to store configuration settings or information that programs may need. To set an environment variable, you can use the "export" command in the shell.

For example:
--code--
export MY_VARIABLE=value
--------

Difference between a function and a system call:
A function and a system call are two different concepts in programming:

1.Function: In programming, a function is a block of code that performs a specific task and can be called from other parts of the program. Functions are used for code modularity, reusability, and to make the code easier to manage and understand. Functions are typically used within the same process.
2.System Call: A system call is a request made by a program to the operating system's kernel to perform privileged operations, such as reading from or writing to a file, creating a new process, or allocating memory. System calls provide an interface for user-level programs to access the low-level functionality of the operating system.

Creating processes:
In Unix-like operating systems, you can create a new process using the fork system call. The fork system call creates a copy of the current process, known as the child process. The child process inherits the memory image, file descriptors, and environment of the parent process. After forking, the child process can execute a different program using the exec family of system calls.

---
Three prototypes of main:
The three prototypes of the main function in C are:
---
1. int main(void):
   This version of the main function takes no arguments and returns an integer.
2.int main(int argc, char *argv[]):
    This version of the main function takes two arguments.
     "argc" represents the number of command-line arguments, and "argv" is an array of pointers to strings,
     which are the actual command-line arguments.
3.int main(int argc, char *argv[], char *envp[]):
      This version of the main function is used less frequently and is specific to some Unix-like systems.
       It includes an additional argument "envp," which is an array of pointers to strings representing the program's environment     variables.
----

How the shell uses the PATH to find programs:
When you enter a command in the shell, the shell needs to locate the corresponding executable program on the file system. It does this by searching through a list of directories specified in the "PATH" environment variable. The "PATH" variable contains a colon-separated list of directories where executable programs are typically located.

For example, if you type a command like "ls" in the shell, the shell will look for an executable file named "ls" in each directory listed in the "PATH" until it finds it. If the "ls" executable is found, the shell will execute it.

Executing another program with the execve system call:
The "execve" system call is used to execute another program from a C program. It replaces the current process's memory image with a new program specified by the provided file path.

The syntax of the execve system call is as follows:
--code--
#include <unistd.h>

int execve(const char *filename, char *const argv[], char *const envp[]);
-------
Here:

1. "filename": The path to the executable file of the new program to be executed.
2. "argv": An array of strings representing the command-line arguments to the new program. The first element should be the program's name itself.
3. "envp": An array of strings representing the environment variables for the new program.
---------

Suspending the execution of a process until one of its children terminates:
To suspend the execution of a process until one of its children terminates, a process can use the "wait" or "waitpid" system calls. These system calls cause the parent process to block (wait) until one of its child processes terminates. When the child process terminates, the parent can continue its execution.

EOF (end-of-file):
EOF stands for "end-of-file." In C programming and many other programming languages, it is represented as a special value typically defined as "-1." When reading data from a file or standard input, the EOF value is returned by input functions (like "getc" or "fgetc") to indicate that there is no more data to read from the input stream. EOF acts as a sentinel value to signal the end of the file or input.
