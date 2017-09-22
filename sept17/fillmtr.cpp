#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, Q;
    cin>>T;
    while(T--){
        cin>>N>>Q;
        int arr[N+1];
        for(int i=1; i<=N; i++)
            arr[i]=-1;
        int m, n, val;
        int flag=0;
        arr[1]=0;
        int am[Q+1];
        int an[Q+1];
        int aval[Q+1];
        for(int i=0; i<Q; i++){
            cin>>m>>n>>val;
            am[i]=m; an[i]=n; aval[i]=val;
            if(m==n){
                if(val!=0){
                    flag=1;
                }
            }
            else if(m==1){
                if(arr[n]==-1)
                    arr[n]=val;
                else if(val!=arr[n])
                {
                    flag=1;
                }
            }
            else if(n==1){
                if(arr[m]==-1)
                    arr[m]=val;
                else if(val!=arr[m])
                {
                    flag=1;
                }
            }
        }

        int tempchk[N], mate[N];
        for(int i=0; i<N; i++)
            tempchk[i]=0;

        if(flag==0){
            for(int i=0; i<Q; i++){
                if(am[i]!=1 && an[i]!=1){
                    if(tempchk[am[i]]==0 && tempchk[an[i]]==0){
                        if(arr[am[i]]!=-1 && arr[an[i]]!=-1){
                            if(aval[i]!=abs(arr[am[i]]-arr[an[i]])){
                                flag=1;
                                break;
                            }
                        }
                        else if(arr[am[i]]==-1 && arr[an[i]]!=-1){
                            if(aval[i]==1){
                                if(arr[an[i]]==1)
                                    arr[am[i]]=0;
                                else
                                    arr[am[i]]=1;
                            }
                            else{
                                if(arr[an[i]]==1)
                                    arr[am[i]]=1;
                                else
                                    arr[am[i]]==0;
                            }
                        }
                        else if(arr[am[i]]!=-1 && arr[an[i]]==-1){
                            if(aval[i]==1){
                                if(arr[am[i]]==1)
                                    arr[an[i]]=0;
                                else
                                    arr[an[i]]=0;
                            }
                            else{
                                if(arr[am[i]]==1)
                                    arr[an[i]]=0;
                                else
                                    arr[an[i]]=0;
                            }
                        }
                        else if(arr[am[i]]==-1 &&  arr[an[i]]==-1){
                            if(aval[i]==1){
                                arr[am[i]]=1;
                                arr[an[i]]=0;
                                tempchk[am[i]]=1;
                                tempchk[an[i]]=1;
                                mate[am[i]]=an[i];
                                mate[an[i]]=am[i];
                            }
                            if(aval[i]==0){
                                arr[am[i]]=1;
                                arr[an[i]]=1;
                                tempchk[am[i]]=1;
                                tempchk[an[i]]=1;
                                mate[am[i]]=an[i];
                                mate[an[i]]=am[i];
                            }
                        }
                    }
                    else if(tempchk[am[i]]==1 && tempchk[an[i]]==0){
                        if(arr[an[i]]!=-1)
                        {
                            if(arr[an[i]]==0){
                                if(aval[i]==1){
                                    if(arr[am[i]]==1){
                                        tempchk[am[i]]=0;
                                    }
                                    else if(arr[am[i]]==0){
                                        tempchk[am[i]]=0;
                                        arr[am[i]]=1;
                                        if(tempchk[mate[am[i]]]==1){
                                            if(arr[mate[am[i]]]==0)
                                            {
                                                arr[mate[am[i]]]=1;
                                            }
                                            else
                                                arr[mate[am[i]]]=0;
                                        }
                                        else{
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(aval[i]==0){
                                    if(arr[am[i]]==0){
                                        tempchk[am[i]]=0;
                                    }
                                    else{
                                        tempchk[am[i]]=0;
                                        arr[am[i]]=0;
                                        if(tempchk[mate[am[i]]]==1){
                                            if(arr[mate[am[i]]]==0){
                                                arr[mate[am[i]]]=1;
                                            }
                                            else
                                                arr[mate[am[i]]]=0;
                                        }
                                        else{
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                            }
                            else{
                                
                                if(aval[i]==1){
                                    if(arr[am[i]]==0){
                                        tempchk[am[i]]=0;
                                    }
                                    else{
                                        tempchk[am[i]]=0;
                                        arr[am[i]]=0;
                                        if(tempchk[mate[am[i]]]==1){
                                            if(arr[mate[am[i]]]==0){
                                                arr[mate[am[i]]]=1;
                                            }
                                            else
                                                arr[mate[am[i]]]=0;
                                        }
                                        else{
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(aval[i]==0){
                                    if(arr[am[i]]==1){
                                        tempchk[am[i]]=0;
                                    }
                                    else if(arr[am[i]]==0){
                                        tempchk[am[i]]=0;
                                        arr[am[i]]=1;
                                        if(tempchk[mate[am[i]]]==1){
                                            if(arr[mate[am[i]]]==0)
                                            {
                                                arr[mate[am[i]]]=1;
                                            }
                                            else
                                                arr[mate[am[i]]]=0;
                                        }
                                        else{
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(aval[i]
                        }
                    }
                }
            }
        }
        if(flag==1)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    } 
    return 0;
}
