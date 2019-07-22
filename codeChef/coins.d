import std.stdio;
import std.conv;

static int[1000000] arr;

long solve(int n) {
   return n < 1000000 ? arr[n] : solve(n / 2) + solve(n / 3) + solve(n / 4);
}

void main() {
   for(static int i = 0; i < 1000000; i++) {
      arr[i] = i < 12 ? i : arr[i / 2] + arr[i / 3] + arr[i / 4];
   }
   string line;
   int num;
   while((line = readln()) !is null) {
      num = to!int(line[0..(line.length - 1)]);
      writeln(solve(num));
   }
}