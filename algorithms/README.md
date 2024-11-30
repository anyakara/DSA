# Solving Problems by Searching (Notes) -- General Outlook

## Well-defined Problems and Solutions
Applications to route-finding algorithms, which can be used in topics like computer network routing, military operations planning, airline travel planning systems.
A problem can be defined formally by four components:
### The initial state
The agent starts in this state. For pathfinding problem, this could be starting in the country Romania. 
### A sucessor function
Or the function that describes the possible actions available to the agent. Given a particular state, x Successor-FN(x), it returns a set of <action, successor> ordered pairs, where each action is one fo the actions in state x and each successor is a state that can be reached from x by applying the action. From state In(Arad), the successor function for the Romania would return the following: {<Go(Sibiu),In(Sibiu), <Go(Timisoara), In(Timisoara)>, <Go(Zerind), In(Zerind>>} (e.g. returns states resulting from taing any scheduled flight leaving later than current time + within airport transit time, from current airport to another as a list).
### A state space
The initial state and the successor function implicitly define the state space -- the set of all states reachable from the initial state. The state space forms a graph in which the nodes are states and the arcs between the nodes are actions. A path in the state space is a sequence of states connected by the sequence of actions. All possible states the agent can be in/on. Includes location and time.
### Goal test
Determines whether a given state is a goal state. Sometimes it is an explicit set of possible goal states, and test simply checks whether the given state is one of them. This could be  discrete value it could be searching for, or it could be an abstract property, such as in chess to "checkmate" --> check if the opponent's kingis under attack and can't escape. (goal location at goal time).
### Path cost
Is a function that assigns a numeric cost to each path. Problem-solving agent chooses a cost function that reflects its own performance measure. Cost of the path might be its length in kilometers. We can assume the cost of the path to be described as the sum of the costs of the invidual actions along the path. Depends on monetary cost, wiating time, flight time, customs and immigration procedures, seat quality, time of day, type of airplane, frequent-flyer mileage awards, etc.
### Step cost
Includes taking such actions would be to go from state x to y through a as c(x, a, y). This is inputted to a problem-solving algorithm. The solution to the problem would be a path to from initial state to goal state and optimal solution has the lowest path cost among the solutions described.
