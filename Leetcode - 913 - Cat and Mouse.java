import java.util.*;

class Solution {
    private int numNode;
    private int[][][] gameState;
    private int[][][] degree;

    private static final int mouseMove = 0;
    private static final int catMove = 1;
    private static final int win = 1;
    private static final int loss = 0;
    private static final int draw = 2;

    public class State {
        public int mouseNode;
        public int catNode;
        public int sideNode;
        public int stateNode;

        public State(int mouse, int cat, int side, int state) {
            this.mouseNode = mouse;
            this.catNode = cat;
            this.sideNode = side;
            this.stateNode = state;
        }
    }

    public int catMouseGame(int[][] graph) {
        numNode = graph.length;
        gameState = new int[numNode][numNode][2];
        degree = new int[numNode][numNode][2];
        Queue<State> queue = new LinkedList<>();

        for (int i = 0; i < numNode; i++) {
            for (int j = 0; j < numNode; j++) {
                gameState[i][j][0] = draw;
                gameState[i][j][1] = draw;
            }
        }

        for (int m = 0; m < numNode; m++) {
            for (int c = 0; c < numNode; c++) {
                degree[m][c][mouseMove] = graph[m].length;
                int d = 0;
                for (int v : graph[c]) {
                    if (v != 0) d++;
                }
                degree[m][c][catMove] = d;
            }
        }

        for (int node = 1; node < numNode; node++) {
            gameState[node][node][catMove] = win;
            queue.add(new State(node, node, catMove, win));

            gameState[node][node][mouseMove] = loss;
            queue.add(new State(node, node, mouseMove, loss));

            gameState[0][node][catMove] = loss;
            queue.add(new State(0, node, catMove, loss));

            gameState[0][node][mouseMove] = win;
            queue.add(new State(0, node, mouseMove, win));
        }

        while (!queue.isEmpty()) {
            State cur = queue.poll();

            int mouse = cur.mouseNode;
            int cat = cur.catNode;
            int turn = cur.sideNode;
            int state = cur.stateNode;

            int prevTurn = 1 - turn;
            if (prevTurn == catMove) {
                for (int prevCat : graph[cat]) {
                    if (prevCat == 0) continue;
                    if (gameState[mouse][prevCat][prevTurn] != draw) continue;
                    if (state == loss) {
                        gameState[mouse][prevCat][prevTurn] = win;
                        queue.add(new State(mouse, prevCat, prevTurn, win));
                    } else {
                        degree[mouse][prevCat][prevTurn]--;
                        if (degree[mouse][prevCat][prevTurn] == 0) {
                            gameState[mouse][prevCat][prevTurn] = loss;
                            queue.add(new State(mouse, prevCat, prevTurn, loss));
                        }
                    }
                }
            } else {
                for (int prevMouse : graph[mouse]) {
                    if (gameState[prevMouse][cat][prevTurn] != draw) continue;
                    if (state == loss) { 
                        gameState[prevMouse][cat][prevTurn] = win;
                        queue.add(new State(prevMouse, cat, prevTurn, win));
                    } else {
                        degree[prevMouse][cat][prevTurn]--;
                        if (degree[prevMouse][cat][prevTurn] == 0) {
                            gameState[prevMouse][cat][prevTurn] = loss;
                            queue.add(new State(prevMouse, cat, prevTurn, loss));
                        }
                    }
                }
            }
        }
        if (gameState[1][2][mouseMove] == win) return 1;
        if (gameState[1][2][mouseMove] == loss) return 2;
        return 0;
    }
}
