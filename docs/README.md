# Project Setup:
Take a look at our [Getting Started](https://github.com/R2steven/cmpsci236Game/blob/master/docs/GettingStarted.md) page for downloading and installing the tools we will be using for this project!

# Data Structures
we plan on using two data structures for different uses in this Project: A Linked List and a Binary Search Tree

![Data Structures Design](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/r2steven/cmpsci236Game/master/docs/Data_Structures_Design/Data_Structures_Design.iuml)

## Linked List
  The Linked list will be utilized as a deck of cards. Students should understand how to: 
  - create and maintain a doubly linked list
  - swap entries in the list
  - rotate through the list
  - students may implement a circular Linked List

## Binary Search Tree
  The Binary Search Tree will be utilized as an inventory system Students should understand how to:
  - create and maintain a BST
  - find a given node of the BST
  - find graph based attributes of a node in the BST such as depth


# Object Oriented Programming, C++
Students should understand the concepts of OOP in modern C++, including but not limited to:
- classes
- objects
- inheretance
- polymorphism and dynamic binding
- interface and Abstract classes
- Design Patterns (strategy)

# crafting a story
we model the game board as a directed graph shown below. You can map out an individual Story path by placing a finger on the start node, and navigating either the left or right path and completing encounters at each node.
![Game Story](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/R2steven/cmpsci236Game/master/docs/Game_Mechanics/Game_Story.iuml)

When designing our map we have a few decisions to make. Firstly, we must keep in mind the exponential nature of a graph. If we split one story node into two at each step down, the number of story nodes we have to support at each level increases by 2^d each time. This means that, for a 5-level game, we would have to create 2^5=32 different endings! To fix this we must put limits on the number of story nodes in each level and decide on how many endings we will support. For simplicity, we will have one beginning, one ending, and five levels. 

Next, we must consider the illusion of choice. We want our players to be able to navigate If we are constrained to begin in one place, and end in another,

# Student Party and Character

![Party Design](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/R2steven/cmpsci236Game/master/docs/Party_Design/Party_Design.iuml)

![Character Design](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/R2steven/cmpsci236Game/master/docs/Party_Design/Character_Design.iuml)

![Party Event Sequence Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/R2steven/cmpsci236Game/master/docs/Student_Sequence/Party_Event_seq.iuml)
