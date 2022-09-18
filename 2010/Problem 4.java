import java.io.*;
import java.util.*;
public class Main {
    static FastIO r = new FastIO();
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) throws Exception {
        int T = r.readInt(), N = r.readInt();
        List<int[]> list[] = new ArrayList[T+1];
        for(int i=1; i<=T; i++) list[i] = new ArrayList<>();
        for(int i=1; i<=N; i++) {
            int c = r.readInt(), v = r.readInt(), t = r.readInt();
            list[t].add(new int[] {c, v});
        }
        int B = r.readInt(), dp[][] = new int[T+1][B+1];
        Arrays.fill(dp[0], (int)-1e9);  dp[0][0] = 0;
        for(int i=1; i<=T; i++) {
            Arrays.fill(dp[i], (int)-1e9);
            for(int [] a : list[i]) {
                int cost = a[0], val = a[1];
                for(int j=cost; j<=B; j++)
                    dp[i][j] = Math.max(dp[i][j], Math.max(dp[i-1][j], dp[i-1][j-cost] + val));
            }
        }
        int ans = -1;
        for(int i=0; i<=B; i++) ans = Math.max(ans, dp[T][i]);
        pr.println(ans); pr.close();
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
