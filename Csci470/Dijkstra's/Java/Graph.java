/**
 * This is where everything that is related to the graph
 * resides. Such as manipulating the graph, reading graph file, etc.
 *
 * @author  Ricky Hempel
 * @version 1.0
 * @since   2018-04-13
 */
import java.io.*;
import java.util.*;

public class Graph {
    private TreeMap<String, HashMap<String, Integer>> adjancency = new TreeMap<>();
    /**
     * This is the constructor of the Graph class, it will read
     * and parse the .graph file and initialize the adjancency Map.
     *
     * @param  filename This is the file name to read from
     */
    public Graph (String filename) {
        File file = new File(filename);
        try (BufferedReader input = new BufferedReader(new FileReader(file))) {
            String line;
            while((line = input.readLine()) != null) {
                String values[] = line.split(" ");

                AddEdge(values[0], values[1], Integer.parseInt(values[2]));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * This method will add the edges to the adjancency list.
     *
     * @param  src The outgoing node
     * @param dest The incoming node
     * @param weight The associated weight between the outgoing and incoming nodes
     */
    private void AddEdge(String src, String dest, Integer weight) {
        HashMap<String, Integer> insert;

        if(adjancency.containsKey(src))
            adjancency.get(src).put(dest, weight);
        else {
            insert = new HashMap<>();
            insert.put(dest, weight);
            adjancency.put(src, insert);
        }
    }

    /**
     * This method will make the graph undirected in nature.
     *
     * @param  filename The file name the will be parsed through
     */
    public void UndirectGraph(String filename) {
        File file = new File(filename);
        try (BufferedReader input = new BufferedReader(new FileReader(file))) {
            String line;
            while((line = input.readLine()) != null) {
                String values[] = line.split(" ");

                AddEdge(values[1], values[0], Integer.parseInt(values[2]));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * This method will print out the entire graph
     * in (node1, node2, weight) format.
     *
     */
    public void PrintGraph() {

        Collection<?> keys = adjancency.keySet();

        for(Object key : keys) {
            for(Map.Entry<String, Integer> pair : adjancency.get(key).entrySet()) {
                System.out.println("(" + key + ", " + pair.getKey() + ", " + pair.getValue() + ")");
            }
        }
    }

    /**
     * This method will determine if HashMap is null (No adjacent edges).
     *
     * @param element The node to check
     * @return boolean
     */
    public boolean IsNull(String element) {
        return adjancency.get(element) == null;
    }

    /**
     * This method will return the associated HashMap (Adjacent edges).
     *
     * @param key The node to check
     * @return HashMap
     */
    public HashMap<String, Integer> GetEdges(String key) {
        return adjancency.get(key);
    }

    /**
     * This method will remove the corresponding edges that contain
     * the outgoing and incoming nodes.
     *
     * @param from The outgoing node
     * @param to The incoming node
     */
    public void RemoveEdges(String from, String to) {
        for(Map.Entry<String, Integer> pair : adjancency.get(from).entrySet()) {
            if(pair.getKey().contains(to)) {
                adjancency.get(from).remove(pair);
            }
        }

        for(Map.Entry<String, Integer> pair : adjancency.get(to).entrySet()) {
            if(pair.getKey().contains(from)) {
                adjancency.get(to).remove(pair);
            }
        }
    }
}
