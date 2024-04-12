# Langford-Pairing
A Langford pairing is a way of arranging numbers in a sequence such that each pair of identical numbers is exactly a certain distance apart. 
![image](https://github.com/Cbwww666/Langford-Pairing/assets/67548133/d52e4113-696d-4453-b07c-429ca4b49a47)
## Description
The tool that you will build has two modes:

1. Check mode: check whether a sequence is a valid Langford pairing.
2. Create mode: generate a Langford pairing given n.
To check whether a sequence is a Langford pairing, simply enter the sequence as command line arguments with no options, e.g.:

```
$ ./langford 2 10 1 2 1 9 12 14 11 7 15 16 10 13 3 9 6 7 3 12 11 8 14 6 4 5 15 13 16 4 8 5
Your sequence: [2, 10, 1, 2, 1, 9, 12, 14, 11, 7, 15, 16, 10, 13, 3, 9, 6, 7, 3, 12, 11, 8, 14, 6, 4, 5, 15, 13, 16, 4, 8, 5]
It is a langford pairing!

$ ./langford 8 4 1 2 6 11 9 6 5 9 5 11 7 3 8 10 4 3 1 7 10 2
Your sequence: [8, 4, 1, 2, 6, 11, 9, 6, 5, 9, 5, 11, 7, 3, 8, 10, 4, 3, 1, 7, 10, 2]
It is NOT a langford pairing.
```

To generate a new Langford pairing, use the -c option and specify n, e.g.:
```
$ ./langford -c 16
Creating a langford pairing with n=16
[2, 10, 1, 2, 1, 9, 12, 14, 11, 7, 15, 16, 10, 13, 3, 9, 6, 7, 3, 12, 11, 8, 14, 6, 4, 5, 15, 13, 16, 4, 8, 5]

$ ./langford -c 9
Creating a langford pairing with n=9
No results found.
```
## Setup
We will use the following command on teach.cs to compile your source code:

```
gcc -Wall -g -std=gnu99 -o langford langford.c
```
