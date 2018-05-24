/**
 * This is the comparator class that the priority
 * queue uses to determine which path to poll next.
 *
 * @author  Ricky Hempel
 * @version 1.0
 * @since   2018-04-13
 */
import java.util.Comparator;
import java.util.Map;

public class Comparison implements Comparator<Map.Entry<String, Integer>> {
    @Override
    public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
        return o1.getValue() - o2.getValue();
    }
}
