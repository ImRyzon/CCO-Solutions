import java.io.*;
import java.util.*;
public class AllRoadsLeadWhere {
    static FastIO r = new FastIO();
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static List<Integer> adj[], path;
    static int pred[];
    static boolean vis[];

    public static void main(String[] args) throws Exception {
        int m = r.readInt(), n = r.readInt(), citiesCount = 0;
        adj = new ArrayList[m*2+1];
        List<String> cities = new ArrayList<>(); cities.add("");
        for (int i = 0;  i< adj.length; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String a = String.valueOf(r.next().charAt(0)), b = String.valueOf(r.next().charAt(0));
            if (!cities.contains(a)) {cities.add(a); citiesCount++;}
            if (!cities.contains(b)) {cities.add(b); citiesCount++;}
            adj[cities.indexOf(a)].add(cities.indexOf(b));
            adj[cities.indexOf(b)].add(cities.indexOf(a));
        }
        for (int i = 0; i < n; i++) {
            int start = cities.indexOf(String.valueOf(r.next().charAt(0)));
            int dest = cities.indexOf(String.valueOf(r.next().charAt(0)));
            String output = "";
            path = new ArrayList<>();
            vis = new boolean[citiesCount + 1]; pred = new int[citiesCount + 1];
            bfs(start, dest);
            path.add(dest);
            int index = 0;
            while (path.get(index) != -1) {
                path.add(pred[dest]);
                dest = pred[dest];
                index++;
            }
            for (int j = path.size()-2; j >= 0; j--) output += cities.get(path.get(j));
            pr.println(output); pr.flush();
        }
    }

    static void bfs(int st, int ed) {
        LinkedList<Integer> q = new LinkedList<>();
        vis[st] = true; q.add(st); pred[st] = -1;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u]) {
                if (!vis[v]) {q.add(v);vis[v] = true; pred[v] = u;}
            }
            if (vis[ed]) return;
        }
    }

    static class FastIO extends PrintWriter {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar, numChars;
        public FastIO() {this(System.in, System.out);}
        public FastIO(InputStream i, OutputStream o) {super(o);stream = i;}
        public FastIO(String i, String o) throws IOException {
            super(new FileWriter(o)); stream = new FileInputStream(i);
        }
        private int readByte() {
            if (numChars == -1) {throw new InputMismatchException();}
            if (curChar >= numChars) {
                curChar = 0;
                try {numChars = stream.read(buf);
                }catch(Exception e){throw new InputMismatchException();}
                if (numChars == -1) {return -1;}
            }
            return buf[curChar++];
        }
        public String next() {
            int c; do {c = readByte();} while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c > ' ');
            return res.toString();
        }
        public String readLine() {
            int c; do {c = readByte();} while (isEndLine(c));
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c >= ' ');
            return res.toString();
        }
        public int readInt() {
            int c, sgn = 1, res = 0;
            do {c = readByte();} while (c <= ' ');
            if (c == '-') {sgn = -1;c = readByte();}
            do {
                if (c < '0' || c > '9') {throw new InputMismatchException();}
                res = 10 * res + c - '0';c = readByte();
            } while (c > ' ');
            return res * sgn;
        }
        public double readDouble() {return Double.parseDouble(next());}
        public long readLong() {return Long.parseLong(next());}
        boolean isEndLine(int c) {return c == '\n' || c == '\r' || c == -1;}
    }
}
