// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "queue.h"
#include "vector.h"
#include "set.h"
#include "tokenscanner.h"

using namespace std;

int main() {
  Map<Queue<string>, Vector<string> > test;
  Queue<string> window;

  ifstream infile;
  infile.open("test.txt");

  TokenScanner scanner(infile);
  scanner.ignoreWhitespace();
  //need to add more punctuations here
  scanner.addWordCharacters(",");  

  int i = 0;
  while (scanner.hasMoreTokens()) {
    string token = scanner.nextToken();
    if (i < 2) {
      window.enqueue(token);
      i++;
      continue;
    }
    if (!test.containsKey(window)) {
      Vector<string> suffixes;
      suffixes.add(token);
      test.put(window, suffixes);
    } else {
      cout << "the original vector: " << endl;
      cout << test.get(window).toString() << endl;
      cout << "the token is: " << token << endl;
      cout << "adding to vector" << endl;

      //why is the below syntax not working?
      //test.get(window).add(token);
      Vector<string> t = test.get(window);
      t.add(token);
      test[window] = t;
      cout << test.get(window).toString() << endl;
    }

    string temp = window.dequeue();
    window.enqueue(token);
    //cout << token << endl;
  }  

  //print things out for testing
  //cout << test.toString() << endl;
  for (Queue<string> k : test) {
    cout << k.toString() << "   ";
    cout << test[k].toString() << endl;
  }
  
  
  cout << "Exiting." << endl;
  return 0;
}
