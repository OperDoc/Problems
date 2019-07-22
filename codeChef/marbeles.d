import std.stdio;
import std.conv;
import std.uni;

import std.array;
import std.string;
import std.algorithm;

long C(int n, int k) {
   long ans = 1;
   if(k != 1) foreach(i; 1..min(n - k + 1, k)) {
      ans = ans * (n - i) / i;
   }
   return ans;
}

void main() {
   auto s = readln().split!isWhite;
   int t = to!int(s[0]);
   while(t--) {
      s = readln().split!isWhite;
      int n = to!int(s[0]), k = to!int(s[1]);
      writeln(C(n, k));
   }
}