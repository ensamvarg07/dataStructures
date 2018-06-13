NOTE:
=====
"graph_info.txt" contains the graph structure.
You can modify the graph without any restrictions using the file "graph_info.txt".
-first line should be the number of nodes of the graph
-"A B D E" indicates Node A is connected to nodes B,D and E.

Instructions to run the program:
================================
[1] make
		-This step will compile main.c and generate the executable "main"

[2] ./main A 5
		-First  argument -> A : Start node
		-Second argument -> 5 : length to traverse

[3] ./main A 5 v
		-'v' is an optional third argument to print the execution time of the total search in microseconds

[4] make clean 
		-Removes "main"

Required Files:
===============
[1] main.c
[2] graphStruct.h   - graph implementation data structure
[3] graph_info.txt  - graph contents
[4] fetch.c         - definitions for fetchline() and fetchword()
[5] Makefile

Implementation:
===============
lines 93-158:
function possiblePaths() and traverse()

[1] Visit a node
[2] Mark it as visited to avoid a cycle
[3] Store the node in an array and increment the array index
[4] Check all its adjacent nodes
[5] If a node is univisited, recursively call the function - This will mark the new node as visited
	and will perform a check whether it's adjacent nodes are visited and so on
[6] Once the control reaches the required length, print the array
[7] Mark the latest node as univisited 
[8] Decrement the array index 

