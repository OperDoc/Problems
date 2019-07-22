import std.stdio;
import std.conv;
import std.string;
import std.array;
import std.uni;

int[1010] arr;

void main() {
   int n, k, x, ans, t;
   string s = readln();
   n = to!int(s.split!isWhite[0]);
   k = to!int(s.split!isWhite[1]);
   for(int i = 1; i <= k; i++) {
      s = readln();
      if(s[2] == 'I') {
	 x = to!int(s.split!isWhite[1]);
	 arr[x - 1] = arr[x - 1] > t ? t : i;
	 ans += arr[x - 1] > t ? 1 : -1;
      } else {
	 t = i;
	 ans = 0;
      }
      writeln(ans);
   }
}