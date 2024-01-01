#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const double eps = 1e-4;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    //judge input
    FILE *input;
    input = fopen("input.txt", "r");
    if (!input) {
        printf("1\n");
        return 0; // Exit with an error code
    }

    //participants output
    FILE *output;
    output = fopen("output.txt", "r");

    if (!output) {
        printf("1\n");
        return 0; // Exit with an error code
    }

    //judge's output
    FILE *answer;
    answer = fopen("answer.txt", "r");

    if (!answer) {
        printf("1\n");
        return 0; // Exit with an error code
    }
    // 0 means ac, else wa

    int n,s,number;
    bool flag=0;
    while (fscanf(input, "%d", &number) == 1) {
        if(!flag){
            n = number;
            flag=1;
        }
        else s = number;
    }

    double tomar, amar;

    while (fscanf(output, "%lf", &tomar) == 1) {
    }

    while (fscanf(answer, "%lf", &amar) == 1) {
    }

    if(abs(tomar-amar)<=eps) printf("0\n");
    else printf("1\n");


    // fclose(input);
    // fclose(output);
    // fclose(answer);
    return 0;
}