#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const double eps = 1e-4;

int arr[1000000];
int p[1000000];
int j[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    // input file
    int n,i=1, number;
    bool flag=0;
    while (fscanf(input, "%d", &number) == 1) {
        n = number;
    }

    //participants output
    int n_par;
    i=1;
    flag=0;
    while (fscanf(output, "%d", &number) == 1) {
        if(!flag){
            n_par = number;
            flag=1;
        }
        else{
            p[i++] = number;
        }
    }

    // while (fscanf(output, "%lf", &tomar) == 1) {
    // }


    //judges output
    int n_judge = n;
    for(int i=1;i<=n;i++){
        j[i] = i;
    }

    // while (fscanf(answer, "%lf", &amar) == 1) {
    // }

    if(n_par!=n_judge) printf("1\n");
    else{
        bool flagggg=0;
        for(int i=1;i<=n_par;i++){
            if(p[i]!=j[i]){
                flagggg=1;
                
            }
        }
        if(flagggg) printf("1\n");
        else printf("0\n");
    }

    // if(abs(tomar-amar)<=eps) printf("0\n");
    // else printf("1\n");


    // fclose(input);
    // fclose(output);
    // fclose(answer);
    return 0;
}