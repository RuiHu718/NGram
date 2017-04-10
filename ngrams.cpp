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

void buildMap(int n, ifstream &infile, Map<Queue<string>, Vector<string> > &nmap);

int main() {
  Map<Queue<string>, Vector<string> > nmap;
  ifstream infile;
  infile.open("test.txt");

  buildMap(3, infile, nmap);

  cout << "Exiting." << endl;
  return 0;
}


/* Function: buildMap
 * Usage:    buildMap(n, infile, nmap)
 * -----------------------------------
 * See assignment handout for detailed information
 * Precondition
 * Postcondition
 */
void buildMap(int n, ifstream &infile, Map<Queue<string>, Vector<string> > &nmap) {
  Queue<string> window;

  TokenScanner scanner(infile);
  scanner.ignoreWhitespace();
  //need to add more punctuations here
  scanner.addWordCharacters(",");  

  int i = 1;
  while (scanner.hasMoreTokens()) {
    string token = scanner.nextToken();
    if (i < n) {
      window.enqueue(token);
      i++;
      continue;
    }
    if (!nmap.containsKey(window)) {
      Vector<string> suffixes;
      suffixes.add(token);
      nmap.put(window, suffixes);
    } else {
      // cout << "the original vector: " << endl;
      // cout << nmap.get(window).toString() << endl;
      // cout << "the token is: " << token << endl;
      // cout << "adding to vector" << endl;

      //why is the below syntax not working?
      //test.get(window).add(token);
      Vector<string> t = nmap.get(window);
      t.add(token);
      nmap[window] = t;
      //cout << nmap.get(window).toString() << endl;
    }

    string temp = window.dequeue(); // temp value is not used
    window.enqueue(token);
    //cout << token << endl;
  }  

  //print things out for testing
  //cout << test.toString() << endl;
  for (Queue<string> k : nmap) {
    cout << k.toString() << "   ";
    cout << nmap[k].toString() << endl;
  }
}
