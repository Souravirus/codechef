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

struct cycle{
    vector<lli>edges;
    lli nodeConNext;
    lli edgeNext;
    lli nodeConPrev;
    lli edgePrev;//redundant
    lli diameter;
    vector<lli>distance;
};

lli minIntDist(lli minv, lli minNext, cycle part){
    lli minIntNode , maxIntNode, minDist1, maxDist1, clockDist, antiDist;
    if(minv < minNext){
        minIntNode = minv;
        maxIntNode = minNext;
    }

    else{
        minIntNode = minNext;
        maxIntNode = minv;
    }

    if(minIntNode != 1)
        minDist1 = part.distance[minIntNode]; 
    else
        minDist1 = 0;

    maxDist1 = part.distance[maxIntNode];

    clockDist = maxDist1 - minDist1;
    antiDist = (part.distance[1] - maxDist1) + minDist1;
    
    if(clockDist < antiDist)
        return clockDist;
    else
        return antiDist;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli T;
    cin >> T;

    while (T--){
        lli N, Q;
        cin >> N >> Q;
        cycle cycarr[N+1];
        vector<lli> extDistance(N+1);

        for(lli i = 1; i <= N; i++){
            lli nodes;
            cin >> nodes;
            int temp;


            cycarr[i].edges.resize(nodes+1);

            for(lli j = 1; j <= nodes; j++){
                cin >> cycarr[i].edges[j];
            }

        }//ok

        lli next;

        for(lli i = 1; i <= N; i++){
            if(i == N) next = 1;
            else next = i+1;
            
            lli node1, node2, edge;
            cin >> node1 >> node2 >> edge; 
            cycarr[i].nodeConNext = node1;
            cycarr[i].edgeNext = edge;
            cycarr[next].nodeConPrev = node2;

        }//ok
                
        for (lli i = 1; i <= N; i++){
            lli count = 0;
            lli size  = cycarr[i].edges.size();
            cycarr[i].distance.resize(size);

            for(lli j = 1; j < size; j++){
                if(j == size-1) next = 1;
                else next = j+1;

                count += cycarr[i].edges[j];
                cycarr[i].distance[next] = count;
            }
            //do one thing 
            lli clock = 0;
            lli cheema = cycarr[i].nodeConPrev;
            clock += cycarr[i].edges[cheema];
            cheema++;
            if(cheema > size-1) cheema = 1;
            while(cheema != cycarr[i].nodeConNext){
                clock += cycarr[i].edges[cheema];
                cheema ++ ;
                if(cheema > size -1) cheema = 1;
            }

            lli diameter = min(clock , cycarr[i].distance[1]-clock);
            if(i == N) next = 1;
            else next = i + 1;
            extDistance[next]=diameter; 
            dout << "next:" <<next <<"extDist:" << extDistance[next]<< endl;
            cycarr[i].diameter = diameter;
        }//ok

        lli count = 0;

        for(lli i = 1; i <= N; i++){
            if(i == N)next = 1;
            else next = i+1;
            //dout << "next:" <<next <<"extDist:" << extDistance[next]<< endl;
            dout << "edgenext:" << i << " " << cycarr[i].edgeNext << endl;
            if(i != 1)
                extDistance[next] += extDistance[i] + cycarr[i].edgeNext;
            else
                extDistance[next]+= cycarr[i].edgeNext;
            dout << "next:" <<next <<"extDist:" << extDistance[next]<< endl;
        }//salicious

        lli minNode, maxNode, minDist1, maxDist1, clockDist, antiDist, tDist, side, maxv, minv, minIntNode, maxIntNode, minConDist[2], maxConDist[2];

        for(lli i = 1; i <= Q; i++){
            tDist = 0;
            cin >> minv >> minNode >> maxv >> maxNode;

            if(minNode > maxNode){
                swap(maxNode, minNode);
                swap(maxv, minv);
            }
            
            lli minNext = cycarr[minNode].nodeConNext;
            lli maxPrev = cycarr[maxNode].nodeConPrev;
            lli minPrev = cycarr[minNode].nodeConPrev;
            lli maxNext = cycarr[maxNode].nodeConNext;

            if(minv != minPrev && !cycarr[minNode].distance.empty()){
                minConDist[0] =  minIntDist(minv, minPrev, cycarr[minNode]);
                dout << "minConDist[0]:" << minConDist[0] << endl;
            }
            else
                minConDist[0] = 0;

            if(minv != minNext && !cycarr[minNode].distance.empty()){
               minConDist[1] = minIntDist(minv, minNext, cycarr[minNode]); 
               dout << "minConDist[1]:" << minConDist[1] << endl;
            }
            else
                minConDist[1] = 0;
            
            if(maxv != maxPrev && !cycarr[maxNode].distance.empty()){
                maxConDist[0] = minIntDist(maxv, maxPrev, cycarr[maxNode]);
                dout << "maxConDist[0]:" << maxConDist[0] << endl;
            }
            
            else 
                maxConDist[0] = 0;

            if(maxv != maxNext && !cycarr[maxNode].distance.empty())
            {
                maxConDist[1] = minIntDist(maxv, maxNext, cycarr[maxNode]);
                dout << "maxConDist[1]:" << maxConDist[1] << endl;
            }
            
            else
                maxConDist[1] = 0;

            if(minNode != 1) 
                minDist1 = extDistance[minNode];
            else
                minDist1 = 0;

            maxDist1 = extDistance[maxNode];

            clockDist = maxDist1 - minDist1; 
            dout << "clockDist : " << clockDist << endl;
            antiDist = (extDistance[1] - maxDist1) + minDist1;
            dout << "antclockDist : " << antiDist << endl;

            lli tclockDist = clockDist + minConDist[1] + maxConDist[0] - cycarr[minNode].diameter;
            dout << "tclockDist:" << tclockDist << endl;
            lli tantiDist = antiDist + minConDist[0] + maxConDist[1] - cycarr[maxNode].diameter;
            dout << "tantiClockdist: " << tantiDist << endl;
            if(tclockDist > tantiDist)
                cout  << tantiDist << endl;
            else
                cout << tclockDist << endl;
        } // end badiloop
    }
    
	return 0;
}
