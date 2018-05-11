%*

{- |

Name: Ricky Hempel

Date: 3/30/2018

Module: dijkstra.lp

Description: Dijkstra's Algorithm implemented in ASP

Stability   :  Stable

Portability :  non-portable

In order to run this program, the start and end node must be declared in the command line.

For example: run with command line: ./clingo dijkstra.lp -c start=a -c end=i

This will return the nodes included in the shortest path between the start and end nodes,
the weight of their edges, and the weight of the path.
-}

*%

% Node declaration by name.

node(a).

node(b).

node(c).

node(d).

node(e).

node(f).

node(g).

node(h).

node(i).

%Edges between two nodes in form (Node1,Node2,Weight).

edge(a,b,4).

edge(a,h,10).

edge(b,c,8).

edge(b,h,11).

edge(c,i,2).

edge(c,f,4).

edge(c,d,7).

edge(d,f,14).

edge(d,e,9).

edge(e,f,10).

edge(f,g,2).

edge(g,h,1).

edge(g,i,6).

edge(i,h,7).

%%% Problems Encoding

%Turns the graph declaration above into a undirected graph.
edge(Y,X,W):- edge(X,Y,W).

%For each edge a path my exits.
{path(X, Y, W) : edge(X, Y, W)}.

% Define a general notion of reachability to
% weed out non-path candidate models
reach(Y) :- path(start,Y,W).
reach(Y) :- reach(X),path(X,Y,W).

%Weed out graphs in which the end node is not reachable
:- node(X), not reach(end).

%Finds the minimum weight of the path.
#minimize { W, X, Y : path(X, Y,W), edge(X, Y, W) }.

%Print relevant paths.
#show path/3.