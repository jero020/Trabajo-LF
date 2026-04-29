#include <iostream>
#include <string>
#include <vector>

std::vector<int> f;

void FailureFunction(std::string keyword) {
    int n = keyword.size();
    f.assign(n + 1, 0);

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
}

std::string KMP(std::string chain, std::string keyword) {
    int n = keyword.size();
    int m = chain.size();
    FailureFunction(keyword);

    int s = 0;

    for (int i = 1; i <= m; i++) {
        while (s > 0 && chain[i-1] != keyword[s])
            s = f[s];
        if (chain[i-1] == keyword[s])
            s = s + 1;
        if (s == n)
            return "yes";
    }
    return "no";
}

int main(){
    std::cout <<"Execution with 'abababaab' as string and 'ababaa' as keyword" << std::endl;
    std::cout <<KMP("abababaab","ababaa") << std::endl;
    std::cout <<"Execution with 'abababbaa' as string and 'ababaa' as keyword" << std::endl;
    std::cout <<KMP("abababbaa","ababaa") << std::endl;
    return 0;
}