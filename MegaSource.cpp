
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>
#include <limits>
#include <chrono>
#include <cmath>

#include "Side.h"
#include "Mega.h"

using namespace std;
using namespace std::chrono;

//Class for holding my configuration values of astar as well 
//as a few result values for sanity check and time check
template<class T>
struct result {
	unsigned int node_limit;

	unsigned int cost_limit;

	unsigned int result_nodes_examined;

	unsigned int result_nodes_opened;

	unsigned int route_length;

	unsigned int route_cost;

	T mega;

	result() :
		node_limit(numeric_limits<unsigned int>::max()),
		cost_limit(numeric_limits<unsigned int>::max()),
		result_nodes_opened(0),
		result_nodes_examined(0),
		route_length(0),
		route_cost(0)
	{ }

};

//Class for my nodes which stores the data of each node and is used to 
//clear up code
//Holds H value = manhatten distance, G = depth, and the Megaminx itself
template<class T>
class linkNode {
public:
	T myNode;
	unsigned int nodeG, nodeF;
	double nodeH;
	linkNode() {};

	linkNode(T n, double h, unsigned int g) {
		this->myNode = n;
		this->nodeH = h;
		this->nodeG = g;
		this->nodeF= g + h;
	}

	inline void operator=( linkNode<T> b) {
		this->myNode = b.myNode;
		this->nodeG = b.nodeG;
		this->nodeH = b.nodeH;
		this->nodeF = b.nodeG + b.nodeH;
	}

	inline bool operator>(const linkNode<T> &b)const {
		return (nodeG + nodeH > b.nodeG + b.nodeH);
	}
	inline bool operator<(const linkNode<T> &b)const {
		return (nodeG + nodeH < b.nodeG + b.nodeH);
	}

	~linkNode() {
	}
};

//Functor for use in my push_heap and pop_heap
bool bin(const linkNode<Mega>& a, const  linkNode<Mega>& b){
	return a > b;
}

bool aStar(Mega a, Mega b, result<Mega> &rs) {
	//Defining type for node structure and queue structure.
	typedef linkNode<Mega> node;
	typedef deque<node> queue;
	//Create node structure, done structure, and iterators for moving through the queues.
	queue nodes;
	queue done;
	queue::iterator j;
	queue::const_iterator k;
	//Bool complete is trivial, current is the current popped off node, ended is the node 
	//that we finished on, and Mega is the container used when adding for turns made.
	bool complete = false;
	node current;
	node ended;
	Mega after;
	nodes.push_back(node(a, a.retHval(), 0));
	unsigned int depth;

	//Start astar do while loop
	do {

		//For this we are popping off queue, checking for complete, then adding moves to the queue if not complete. 
		//Readme has more detail on steps.
		current = nodes.front();
		depth = current.nodeG;

		pop_heap(nodes.begin(), nodes.end(), bin);
		nodes.pop_back();
		done.push_back(current);
		rs.result_nodes_examined++;

		complete = current.nodeH == 0;
		if (complete) {
			ended = current;
			break;
		}
		//Node limit reached and need to stop
		if (current.nodeG + current.nodeH > rs.cost_limit) {
			break;
		}
		//queue of new orientations
		deque<Mega> choices;
		for (int n = 23; n >= 0; n--) {
			Mega c = current.myNode;
			if (n == 23) {
				c.TurnTopCountClock(7);
				choices.push_back(c);
			}
			if (n == 22) {
				c.TurnTopRightCountClock(12);
				choices.push_back(c);
			}
			if (n == 21) {
				c.TurnBotRightCountClock(12);
				choices.push_back(c);
			}
			if (n == 20) {
				c.TurnBotLeftCountClock(12);
				choices.push_back(c);
			}
			if (n == 19) {
				c.TurnTopLeftCountClock(12);
				choices.push_back(c);
			}
			if (n == 18) {
				c.TurnTopCountClock(12);
				choices.push_back(c);
			}
			if (n == 17) {
				c.TurnTopCountClock(2);
				choices.push_back(c);
			}
			if (n == 16) {
				c.TurnTopRightCountClock(1);
				choices.push_back(c);
			}
			if (n == 15) {
				c.TurnBotRightCountClock(1);
				choices.push_back(c);
			}
			if (n == 14) {
				c.TurnBotLeftCountClock(1);
				choices.push_back(c);
			}
			if (n == 13) {
				c.TurnTopLeftCountClock(1);
				choices.push_back(c);
			}
			if (n == 12) {
				c.TurnTopCountClock(1);
				choices.push_back(c);
			}
			if (n == 11) {
				c.TurnTopClock(7);
				choices.push_back(c);
			}
			if (n == 10) {
				c.TurnTopRightClock(12);
				choices.push_back(c);
			}
			if (n == 9) {
				c.TurnBotRightClock(12);
				choices.push_back(c);
			}
			if (n == 8) {
				c.TurnBotLeftClock(12);
				choices.push_back(c);
			}
			if (n == 7) {
				c.TurnTopLeftClock(12);
				choices.push_back(c);
			}
			if (n == 6) {
				c.TurnTopClock(12);
				choices.push_back(c);
			}
			if (n == 5) {
				c.TurnTopClock(2);
				choices.push_back(c);
			}
			if (n == 4) {
				c.TurnTopRightClock(1);
				choices.push_back(c); 
			}
			if (n == 3) {
				c.TurnBotRightClock(1);
				choices.push_back(c);
			}
			if (n == 2) {
				c.TurnBotLeftClock(1);
				choices.push_back(c);
			}
			if (n == 1) {
				c.TurnTopLeftClock(1);
				choices.push_back(c);
			}
			if (n == 0) {
				c.TurnTopClock(1);
				choices.push_back(c);
			}
			//cout << c.retHval() << "\t" << n << "\n";
		}
		deque<Mega>::iterator i = choices.begin();
		deque<Mega>::iterator end = choices.end();
		depth++;

		for (; i != end; ++i) {
			after = *i;

			j = nodes.begin();
			k = nodes.end();
			for (; j != k; ++j) {
				if (j->myNode == after) {
					break;
				}
			}
			if (j == k) {
				j = done.begin();
				k = done.end();
				for (; j != k; ++j) {
					if (j->myNode == after) {
						break;
					}
				}
				if (j == k) {
					nodes.push_back(node(after, after.retHval(), depth));
					push_heap(nodes.begin(), nodes.end(), bin);
				}
			}
			else {
				if (depth < j->nodeG) {
					done.push_back(node(after, after.retHval(), depth));
					push_heap(done.begin(), done.end(), bin);
				}
			}
		}
	} while (nodes.size() < rs.node_limit);


	//Data used for printing in main
	rs.route_cost = current.nodeG + current.nodeH;
	++rs.route_length;
	rs.mega = ended.myNode;
	rs.result_nodes_opened = nodes.size() + done.size();
	rs.result_nodes_examined = done.size();
	rs.result_nodes_examined--;
	return complete;
}

bool isNumber(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

int main(int argc, char *argv[]) {
	Mega megaminx;
	Mega End;
	megaminx.ResetMegaColors();
	End.ResetMegaColors();
	result<Mega> cfg;
	bool run;
	string arg = argv[1];
	int x = 0;
	if (argc == 1) {
		cout << "No arguments were passed...\n\n";
	}
	else {
		if (isNumber(arg)) {
			x = stoi(arg);
			if (x <= 15 && x > 0) {
				for (int j = 0; j < 5; j++) {
					int mins;
					int secs;
					megaminx = End;
					megaminx.RotationRandomizer(x);
					clock_t begin = clock();
					run = aStar(megaminx, End, cfg);
					clock_t end = clock();
					double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
					double elapsed_milli = elapsed_secs * 1000;
					if (run == true) {
						cout << "Nodes examined: " << cfg.result_nodes_examined << endl;
						cout << "Nodes opened: " << cfg.result_nodes_opened << endl;
						if (elapsed_secs > 60) {
							mins = int(elapsed_secs) / 60;
							secs = int(elapsed_secs) % 60;
							cout << "Time: " << mins << " minutes and " << secs << " Seconds\n\n";
						}
						else if (elapsed_secs >= 1) {
							cout << "Time: " << ceil(elapsed_secs) << " Seconds\n\n";
						}
						else cout << "Time: " << ceil(elapsed_milli) << " Milliseconds\n\n";
					}
					else cout << "Not found...\n\n";
				}
			}	//I was told that 15 was high enough for randomizations
			else cout << "Error on input, above 15 or below 3! Please try again...\n\n";		
		}
		else {
			cout << "Error on input, not an integer...\n";
		}
	}
	return 0;
}