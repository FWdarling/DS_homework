#include"../Lab/tree.h"


using std::cout;
using std::endl;
using std::string;

int main(){
    Tree<string> zupu;
    string s1 = "mlj";
    string s2 = "jjf";
    string s3 = "jjf2";
    zupu.build(s1);
    zupu.Add(s1, s2);
    zupu.Add(s1, s3);
    zupu.Delete(zupu.find(s2));
 
    zupu.find(s2);
    //zupu.Delete(zupu.find(2));
    zupu.clear();
    return 0;
}