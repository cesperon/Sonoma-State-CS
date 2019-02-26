# Brandon Adamson-Rakidzich
# Christian Esperon

Just run main.py to run tasks 1-3.
task4.py can be run to reproduce the graph included. (Requires all test data 0-7 to be in the same folder)

Task 4 Analysis:

	As the included graph (task4graph.png) shows, the dynamic programming approach (blue) is significantly slower than the greedy approach (red) at high numbers of items (and also at high capacities). This is because the dynamic programming approach creates an nxm graph (n is the number of items, m is the max capacity), and so is expontential in runtime. As the number of items or total capacity increases, the runtime of the dynamic programming approach increases dramaticaly. 

The greedy approach just goes through all the items once to create the value/weight list, then sorts and picks from them until it runs out of capacity. 

So dynamic programming is n^2, and the greedy approach is nlogn. 