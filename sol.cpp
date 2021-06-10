#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		// 'res' will contain the matched characters from 's'
		string res = "";
		// 'cnt' will contain the number of operations
		int cnt = 0;
		// 'buffer' will contain the current value
		int buffer = 0;
		// 'index' will contain the current index of the character being iterated upon
		int index = 0;
		// run a while-loop until string 'res' is equal to 's'
		while (res != s && index < (int) s.size()) {
			// find the place of the letter in the alphabet minus one (zero-based)
			int letter_index = s[index] - 'a';
			if (index == 0) {
				// if the it's the first operation, then set the value of buffer to
				// the index of the current letter (based on problem statement)
				buffer = letter_index;
				// increment 'cnt' because this is also an operation
				cnt++;
			}
			if (buffer == letter_index) {
				// if 'buffer' is equal to the index of the current letter, then
				// concatenate the current letter to the 'res' string
				res += s[index++];
			} else {
				// otherwise, if the value of the 'buffer' is less than or greater than
				// the index of the current letter, then simply increment 'buffer'
				buffer++;
				if (buffer == 26) {
					// if 'buffer' is equal to 26, then reset it back to 0
					buffer = 0;
				}
			}
			// increment 'cnt' for every iteration
			cnt++;
		}
		// check if 'cnt' is less than or equal to the size of the string times 11
		cout << (cnt <= (int) s.size() * 11 ? "YES" : "NO") << '\n';
	}
	return 0;
}
