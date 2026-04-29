#include <iostream>
#include <string>  


void FailureFunction(std::string x);

int main(){
    FailureFunction("ababaaa");
    return 0;
}

void FailureFunction(std::string keyword) {
    int n = keyword.size();
    int f[n+1];  
    
    int t = 0;
    f[1] = 0;  
    
    for (int s = 1; s < n; s++) {  // línea 3
        // aquí va el while de la línea 4
        while (t > 0 && keyword[s] != keyword[t]){
            t = f[t];
        }
        
        if (keyword[s] == keyword[t]){
            t = t + 1;
            f[s+1] = t;
        }else{
            f[s+1] = 0;
            t = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << f[i] << " ";
    }
    std::cout << std::endl;
}