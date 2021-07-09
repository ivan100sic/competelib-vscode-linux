#include <bits/stdc++.h>
using namespace std;

const size_t indent_size = 4;

string esc(string s) {
  string r = "\"";

  size_t i = 0;
  while (i + indent_size - 1 < s.size()) {
    if (count(s.begin() + i, s.begin() + i + indent_size, ' ') == indent_size) {
      // indent
      r += "\\t";
      i += indent_size;
    } else {
      break;
    }
  }

  s = s.substr(i);

  for (char c : s) {
    if (c == '\\') {
      r += "\\\\";
    } else if (c == '"') {
      r += "\\\"";
    } else if (c == '\t') {
      r += "\\t";
    } else {
      r += c;
    }
  }

  r += '"';
  return r;
}

int main() {
  vector<string> v;
  string s;
  while (getline(cin, s)) {
    v.push_back(s);
  }

  if (v.size() == 1) {
    cout << esc(v[0]);
  } else {
    cout << "[\n";
    for (size_t i = 0; i < v.size(); i++) {
      cout << "\t" << esc(v[i]);
      if (i + 1 < v.size()) {
        cout << ",";
      }
      cout << '\n';
    }
    cout << "]\n";
  }
}
