# Megaminx
**First! You need to initially use make on the command line. This is compiled with optimization O3, but you can type make O2 and make O1 to optimize lower.
After that you can run it by the command "./Megaminx k" where k is the amount of rotations you want to test on it. When run, the implementation of my astar algorithm is able to find the correct path within a reasonable amount of time up until k = 12. After that it begins to run in to a few errors, mostly due to it having to iterate through a long container of nodes and taking too much time/memory for my pc.

-Side Class-
Building off of what I had for the first program, I implemented a class for the Side of the cube. Having a class helps to encapsulate my data stored within each side of the megaminx. My side header file shows all the functions that I've implement in the cpp file, this including two new functions that i didnt have previously. These functions turn the face of the face being turned so there isn't error on the top face being tunred. The functions within this class are fairly trivial.

-Mega Class- 
This Class has a few weird aspects that were derived from an incorrect first project, but taking them out would have been a tedious task so I kept them in. To start the class contains the private variables for the stored megaminx. Edgestickers and cornerstickers are the variables used to get the h-value for the megaminx. Using these and the function retval, we can look for the pieces out of place and find the distance each sticker needs to be in the right place. I discovered this way from Adrian, a fellow student, that posted on the discussion board. The turn functions are the same from my first project, but I only use a few of the turn variations in this project. The randomizer is also the same from the previous project, but now it takes a value that is retrieved from the unix command line. This value is the number of turns that need to be executed. In this class we also have new operators to easily alter and create new megaminx structures.

-MegaSource File-
This is where the bulk of the program is located. First we have a simple result template to hold needed values that will be used to stop the program or tell nodes opened/expanded. Next we have the linkNode class, which is where my node data is held. It stores the megaminx version, nodes G and H values, and the heuristic result for those. The class also contains the operators needed to work with my double ended queue of nodes.

-Astar- 
-This starts my implementation of astar and working with expanding nodes. I use a container deque, which is a double ended queue. This along with push_heap, pop_heap, and a comparator functor are used to keep the queue organized and have the lowest f value object first. I have a container of nodes and a container of done which is the nodes I've already visited. 
-To start we create the first node from the randomized megaminx and start the do while loop for solving the puzzle. Initially we pop the current node from the queue, and check the completeness, this being the H value (Total sticker distance/manhatten distance). 
-Next I check if the current node F value is too high, if so I return not found. Finally, if this isn't the node I'm looking for, then I create the variations of the node. To do this I create a deque of mega structs with each struct being a movement. The movements are both counterclockwise  and clockwise to solve but the mix up function in mega class only uses clockwise turns. 
-The reason I chose to use both instead of only counter is because there is a case where if a side is moved 3 times in a row, it is faster to just turn the node twice. It also gives the program more options even though it doubles the growth. 
-After creating these variations we have to sequentially add them to the queue, sorting them in each time. I have also made it possible to not recreate nodes that weve already visited by checking if the node is already in the queue, if so I add it to done. If it isnt already in the queue I check if its in done, if not its added and we move on to the next node. This isn't too memory intrusive because of the no-copy case, but it still is storing whole megaminx structs so that can take some time/memory.

-Main-
This is just a simple main where we take input from user and output the result of solution, time it took, nodes opened/expanded, and if the input is invalid it throws errors. 

-Learned-
From this assignment I have learned to find and implement a working heuristic with object oriented programming and a search algorithm such as A*, as well as improving my c++ skills quite a bit with using classes and templates. 

-Heuristic-
My heuristic used is based on using a priority queue and computing the F = H + G val at each node. Each time we add a node, we sort and place the node in the correct place in the queue. This is used to find the shortest possible path from the start node to the finish node.
