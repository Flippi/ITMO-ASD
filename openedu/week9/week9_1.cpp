#include <string>
#include "edx-io.hpp"

using namespace std;


int main() {
    string p;
    string t;

    int count = 0;

    io >> p >> t;
    int* arr = new int[t.length()];
    if(t.length() >= p.length()){
    for (int i = 0; i < t.length()-p.length()+1; ++i) {
        if (p[0] == t[i]){
            bool ok = true;
            for(int j = 0; j < p.length(); ++j){
                if(p[j] != t[i+j]){
                    ok = false;
                    break;
                } 
            }
            if(ok){
                arr[count] =  i+1;             
                count++;
            }
        }
    }
    }
   io << count << '\n';
    for (int i = 0; i < count; i++)
    {
            io << arr[i] << " ";    
        }
    return 0;
}