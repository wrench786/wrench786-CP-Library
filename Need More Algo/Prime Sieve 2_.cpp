#include<iostream>
using namespace std;

int prime[100000];
bool arr[1000001];
void call(){
    int i,j;
    arr[0]=arr[1]=true;
    for(long long i=2;i*i<=1000001;i++){
        if(arr[i]==false){
            for(long long j=i*i;j<=1000001;j+=i){
                arr[j] = true;
            }
        }
    }
    for(i=2,j=0;i<=1000001;i++){
        if(arr[i]==false){
            prime[j]=i;
            j++;
        }
    }
}

int main()
{
    int n,x;
    cin>>n;
    call();
    while(n--){
        cin>>x;
        cout<<prime[x-1]<<endl;
    }
}
