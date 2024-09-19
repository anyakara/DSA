# Solving Problems by Searching
## Well-defined Problems and Solutions
A problem can be defined formally by four components:
### The initial state
The agent starts in this state. For pathfinding problem, this could be starting in the country Romania.
### The sucessor function
Or the function that describes the possible actions available to the agent. Given a particular state, x Successor-FN(x), it returns a set of <action, successor> ordered pairs, where each action is one fo the actions in state x and each successor is a state that can be reached from x by applying the action. From state In(Arad), the successor function for the Romania would return the following:
```
{<Go(Sibiu),In(Sibiu), <Go(Timisoara), In(Timisoara)>, <Go(Zerind), In(Zerind>>}
```
