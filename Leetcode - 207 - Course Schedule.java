class Solution {
    private ArrayList<Integer>[] adjlist;
    private int[] indegree; 
    private Queue<Integer> queue;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        adjlist = new ArrayList[numCourses + 1];
        indegree = new int[numCourses + 1];
        int numRelation = prerequisites.length;
        queue = new LinkedList<Integer>();
        int remain = numCourses;

        for (int index = 0; index < numCourses; index++) {
            adjlist[index] = new ArrayList<Integer>();
        }

        for (int index = 0; index < numRelation; index++) {
            int course = prerequisites[index][0];
            int conditionCourse = prerequisites[index][1];

            adjlist[conditionCourse].add(course);
            indegree[course] += 1;
        }

        for (int index = 0; index < numCourses; index++) {
            if (indegree[index] == 0) {
                queue.add(index);
                remain -= 1;
            }
        }

        while (queue.isEmpty() == false) {
            int current = queue.poll();
            for (int v : adjlist[current]) {
                indegree[v] -= 1;
                if (indegree[v] == 0) {
                    queue.add(v);
                    remain -= 1;
                }
            }
        }
        return remain == 0;
    }
}
