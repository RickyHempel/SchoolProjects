/**
 * This is the main driver of the program and
 * contains the Dijkstra algorithm using a priority queue.
 *
 * @author  Ricky Hempel
 * @author  Ricky Hempel
 * @version 1.0
 * @since   2018-04-13
 */
import java.util.*;

public class Dijkstra {
    private PriorityQueue<Map.Entry<String, Integer>> testing = new PriorityQueue<Map.Entry<String, Integer>>(new Comparison());
    private Map.Entry<String, Integer> finalPath;


    /**
     * Takes the console arguments and opens a new graph
     * along with finding the shortest path from the two
     * given nodes.
     *
     * @param  arg  The arguments passed in through the console
     */
    public static void main(String arg[]){
        Graph graph = new Graph(arg[0]);
        graph.UndirectGraph(arg[0]);

        Dijkstra dijkstra = new Dijkstra();

        HashMap<String, Integer> begin = new HashMap<String, Integer>();
        begin.put(arg[1], 0);
        dijkstra.DijkstraPathing(arg[1], arg[2], graph, begin.entrySet().iterator().next());

        dijkstra.PrintPath(arg[0]);
    }

    /**
     * This is a recursive method that will find the shortest
     * from start to end and save it inside the finalPath. It will
     * end if the given nodes don't exist or the path doesn't exist.
     *
     * @param  start  This variable will be used to keep track of which node it's on
     * @param  end  This stays the same and is used to determine if the method should end
     * @param  graph  The graph that the method iterates over
     * @param  path  This will be the path that the function iterates through
     */
    public void DijkstraPathing(String start, String end, Graph graph, Map.Entry<String, Integer> path) {
        if(path.getKey().contains(end)) {
            finalPath = path;
            return;
        }
        if(graph.IsNull(start) || graph.IsNull(end)) {
            HashMap<String, Integer> DoesNotExist = new HashMap<String, Integer>();
            DoesNotExist.put("Start or end node does not exist!", -1);
            finalPath = DoesNotExist.entrySet().iterator().next();
            return;
        }
        //Added path.getValue() != 0 to make sure it does occur in the beginning when the queue is empty.
        if(testing.isEmpty() && path.getValue() != 0) {
            HashMap<String, Integer> DoesNotExist = new HashMap<String, Integer>();
            DoesNotExist.put("Path does not exist!", -1);
            finalPath = DoesNotExist.entrySet().iterator().next();
            return;
        }
        else {
            for(Map.Entry<String, Integer> pair : graph.GetEdges(start).entrySet()) {
                String pathKey = path.getKey();
                Integer pathValue = path.getValue();

                HashMap<String, Integer> value = new HashMap<String, Integer>();
                value.put(pathKey + "-" + pair.getKey(), pathValue + pair.getValue());
                testing.add(value.entrySet().iterator().next());
            }

            path = (Map.Entry<String, Integer>)testing.poll();

            //Removing each travelled edge since it's a undirected graph, it will loop forever otherwise.
            graph.RemoveEdges(path.getKey().split("-")[path.getKey().split("-").length - 2],
                    path.getKey().split("-")[path.getKey().split("-").length - 1]);

            DijkstraPathing(path.getKey().substring(path.getKey().length() - 1), end, graph, path);
        }
    }

    /**
     * This method will print out the finalPath and the original graph
     * in lexicographic order.
     *
     * @param  filename The file name to reopen the same graph to print out original
     */
    public void PrintPath(String filename) {
        Graph original = new Graph(filename);
        System.out.println("Graph:");
        original.PrintGraph();
        System.out.println("Shortest Path: " + finalPath.getValue() + " " + finalPath.getKey());
    }
}
