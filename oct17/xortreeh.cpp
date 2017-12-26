#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

int debug = 0;
ulli mod = 330301441;

ulli gcd(ulli a, ulli b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

void  lowest(ulli &den3, ulli &num3){
    ulli common_factor = gcd(num3, den3);

    den3 = den3 / common_factor;
    num3 = num3 / common_factor;
}

void addFract(ulli num1, ulli den1, ulli num2, ulli den2, ulli &num3, ulli &den3){
    den3 = gcd(den1, den2);
    den3= (den1*den2)/den3;
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
    lowest(den3, num3);
}

ulli modInverse(ulli a, ulli m){
    a = a%m;
    for(ulli x = 1; x < m; x++)
        if((a*x) % m == 1)
            return x;
}

/*string  toBase(ulli a, ulli base){
    string s;
    ulli ind = 0;
    while(a > 0){
        s[ind++] = (a % base) + '0';
        a/=base;
    }
    return s;
}*/

/*ulli xorSum(ulli a, ulli b, ulli base){
    string sa = toBase(a);
    string sb = toBase(b);
    
}*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ulli T;
    cin >> T;

    while(T--){
        ulli ans;
        ulli N, K, X;
        cin >> N >> K >> X;
        ulli arr[N];
        set<ulli> myset;

        for(ulli i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr+N);
        
        ulli count = 0;
        vector<ulli> numPres;
        ulli pro = 1;

        if(arr[0] == 0){
            while(arr[count] == 0){
                count++;         
            }
            numPres.push_back(pow(2, (N-count)));

            ulli j = 1, prevCount = count;
            ulli flag = 0;
            pro = pro*prevCount;
            while(count < N){

                if(arr[count] != j){

                    if(prevCount == count){
                        ulli val = pro * (pow(2, (N-count))-1);
                        numPres.push_back(val);
                        flag = 1;
                        break;
                    }

                    else{
                        ulli val = pro * (pow(2, N-count));
                        numPres.push_back(val);
                        pro= pro*(count - prevCount);
                        j++; prevCount = count++;

                    }
                }

                else{
                    count++;
                }
            }
            if(flag == 0){
                if(arr[count-1]!=j){
                    numPres.push_back(pro*pow(2, (N-count+1)));
                }

                else{
                    numPres.push_back(pro*pow(2, (N- count)));
                    pro = pro * (count - prevCount);
                    numPres.push_back(pro);
                }
            }
        }
        
        else{
            numPres.push_back(pow(2, (N)));
        }
        dout << "Printing numPres:" << endl;
        for(ulli i = 0; i < numPres.size(); i++){
            dout << "for " << i << " numpres:" << numPres[i] << endl;
        }
        
        vector<ulli>sum; 
        ulli tot_occurence = 0;

        if(K == 2){
            for(ulli i = 0; i < numPres.size(); i++){

                for(ulli j = 0; j < numPres.size(); j++){
                    ulli temp_sum = i^j, occurence; 

                    if(i == j){
                        occurence = numPres[i]*numPres[j];
                        
                    }

                    else{
                        occurence =numPres[i]*numPres[j];
                    }

                    if(temp_sum >= sum.size()){
                        sum.resize(temp_sum + 1);
                    }
                    sum[temp_sum] += occurence;
                    tot_occurence += occurence;
                }
            }
            dout << "printing temp_sum" << endl;
            for(ulli i = 0; i < sum.size(); i++){ 
                dout << "for " << i << " " << sum[i] << endl;
            }
            
            dout << "tot_occurence:" << tot_occurence << endl;
            ulli num1, num2, num3, den1, den2, den3;
            for(ulli i = 0; i < sum.size(); i++){

                if(i == 0){
                    num3 = 1;
                    den3 = 1;
                }
                
                else{
                    num1 = num3;
                    den1 = den3;
                    num2 = pow(i, (2*i)) * pow(sum[i], (3*i));
                    den2 = pow(tot_occurence, 3*i);
                    lowest(num2, den2);
                    addFract(num1, den1, num2, den2, num3, den3);
                }
                
            }
            ulli den4 = modInverse(den3, mod);
            ulli ans = ((num3%mod) * den4) % mod;
            cout << ans << endl;
        }

        /*else if(K == 3){
            for(ulli i = 0; i < numPres.size(); i++){

                for(ulli j = 0; j < numPres.size(); j++){

                    for(ulli  k = 0; k < numPres.size(); k++){
                        ulli temp_sum1 = xorSum(i,j, 3);
                        ulli temp_sum = xorSum(temp_sum1, k, 3);

                        ulli occurence = numPres[i]*numPres[j]*numPres[k];

                        if(temp_sum >= sum.size()){
                            sum.resize(temp_sum + 1);
                        }
                        sum[temp_sum] += occurence;
                        tot_occurence += occurence;
                    }
                }
            }
            dout << "printing temp_sum" << endl;
            for(ulli i = 0; i < sum.size(); i++){ 
                dout << "for " << i << " " << sum[i] << endl;
            }
            
            dout << "tot_occurence:" << tot_occurence << endl;
            ulli num1, num2, num3, den1, den2, den3;
            for(ulli i = 0; i < sum.size(); i++){

                if(i == 0){
                    num3 = 1;
                    den3 = 1;
                }
                
                else{
                    num1 = num3;
                    den1 = den3;
                    num2 = pow(i, (2*i)) * pow(sum[i], (3*i));
                    den2 = pow(tot_occurence, 3*i);
                    lowest(num2, den2);
                    addFract(num1, den1, num2, den2, num3, den3);
                }
                
            }
            ulli den4 = modInverse(den3, mod);
            ulli ans = ((num3%mod) * den4) % mod;
            cout << ans << endl;
        }*/

        else
            cout << "0" << endl;

    }
	return 0;
}
