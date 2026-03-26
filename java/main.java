import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    public static List<int[]> twonum(int[] nums, int target) {
        List<int[]> res = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    res.add(new int[]{nums[i], nums[j]});
                }
            }
        }
        return res;
    }


    public static void main(String[] args) {
        int nums[] =  { 4, 10, 7, 4, 2, 3, 6, 1, 8 };
        int target = 9;
        int pairCount = 0;

        List<int[]> res = twonum(nums, target);
            
        System.out.println("nums: " + Arrays.toString(nums));
        System.out.println("target: " + target);
        
        System.out.print("pairs found: [");
        for (int i = 0; i < res.size(); i++) {
            System.out.print(Arrays.toString(res.get(i)));
            if (i < res.size() - 1)
                System.out.print(", ");
        }
        System.out.print("]");
    }
}

