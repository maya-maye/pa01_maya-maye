#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
  ofstream MyFile("output.txt");
  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
IntBST a, b;
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
      //cout<<line.substr(0,1)<<" ";
      //cout<<line.substr(2, line.length()-2)<<endl;
      int add=0;
      char temp=line[0];
      if (line[3]){
        add=9;
      }
      char t=line[2];
      cards n (temp, t);
      a.insert(n.getValue()+add);
      //MyFile<<line.substr(2, line.length()-2)<<endl;
  }
  cardFile1.close();
//MyFile.close();
  while (getline (cardFile2, line) && (line.length() > 0)){
      //cout<<line.substr(0,1)<<" ";
      //cout<<line.substr(2, line.length()-2)<<endl;
      int add=0;
      char temp=line[0];
      if (line[3]){
        add=9;
      }
      char t=line[2];
      cards n (temp, t);
      b.insert(n.getValue()+add);
  }
  cardFile2.close();

//game!
bool bo=true;
bool first=true;
bool alice=true;
bool bob=true;
int amin=a.min();
int bmax=b.max();
while (bo){
  while (first&&alice){
    if(b.contains(amin)){
      cout<<"Alice picked matching card ";
      printCard(amin);
      int t=a.getSuccessor(amin);
      // if (bmax==amin){
      //   bmax=b.getPredecessor(bmax);
      // }
      a.remove(amin);
      b.remove(amin);
      amin=t;
      if (amin==0) alice=false;
      first=false;
    }
    else{
      amin=a.getSuccessor(amin);
      if (amin==0){
        bo=false;
        break;
      }
    }
  }
  while (!first&&bob){
    if(a.contains(bmax)){
      cout<<"Bob picked matching card ";
      printCard(bmax);
      int temp=b.getPredecessor(bmax);
      // if (bmax==amin){
      //   amin=a.getSuccessor(amin);
      // }
      a.remove(bmax);
      b.remove(bmax);
      bmax=temp;
      if (bmax==0) bob=false;
      first=true;
    }
    else{
      bmax=b.getPredecessor(bmax);
      if (bmax==0){
        bo=false;
        break;
      }
    }
  }
}
cout<<endl;
cout<<"Alice's cards:"<<endl;
a.printInOrder();
cout<<endl;
cout<<"Bob's cards:"<<endl;
b.printInOrder();
return 0;
}
