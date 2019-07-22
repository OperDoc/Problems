import std.stdio;
import std.conv;
import std.uni;
import std.string;
import std.algorithm;

char[] rev(char[] s) {
   auto ans = s.dup;
   ans.reverse();
   return ans;
}

char inc(char c) {
   return '0' + (c - '0' + 1) % 10;
}

char[] palin(char[] s, ulong n) {
   char[] ans;
   for(int i = 0; i < n; i++) {
      ans ~= s[i];
   }
   ans.reverse();
   return s ~ ans;
}

char[] inc(char[] s, bool isInc = true) {
   foreach(ref i; s.reverse) {
      i = isInc ? inc(i) : i;
      isInc = (i == '0') && isInc;
   }
   s.reverse;
   return s;
}

void solve(char[] s) {
   char[] nine;
   nine.length = s.length;
   nine[] = '9';
   //writeln(nine);
   if(s == nine) {
      char[] ans;
      ans.length = s.length + 1;
      ans[] = '0';
      ans[0] = '1';
      ans[$-1] = '1';
      writeln(ans);
   } else if(s.length % 2 == 0) {
      char[] spl1 = s[0..(s.length / 2)], spl2 = s[(s.length / 2)..(s.length)];
      if(spl2 < rev(spl1)) {
	  writeln(spl1, rev(spl1));
      } else {
	 auto sinc = inc(spl1);
	 writeln(sinc, rev(sinc));
      }
   } else {
      char[] spl1 = s[0..(s.length / 2)], a = s[(s.length / 2)..((s.length + 1) / 2)], spl2 = s[((s.length + 1) / 2)..(s.length)];
      if(spl2 < rev(spl1)) {
	 writeln(spl1, a, rev(spl1)); 
      } else {
	 writeln(palin(inc(spl1 ~ a), spl1.length));
      }
   }
}

void main() {
   auto inp = readln().split!isWhite;
   int t = to!int(inp[0]);
   while(t--) {
      inp = readln().split!isWhite;
      solve(inp[0].dup);     
   }
}