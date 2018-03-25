#include<stdio.h>
#define n 5


int g[n][n]={
{0,3,0,0,0},
{3,0,10,0,2},
{0,10,0,5,6},
{0,0,1,0,8},
{0,2,6,8,0}};




int check(){
	int i,j,k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			if(g[i][j]!=g[j][i])
			k++;
		}
	}
	return k;
}



int cost[n];//cost taken to get to this node so far.
int from[n];//where this node has come from 
int visited[n];//if this node is visited or not
int distance[n];//cost to get from this node to the next.

void dijkstra(int start){
	int i,j,nxt,state=0;
	
	
	
	
	
	for(j=0;j<n;j++){
		
		distance[j]=g[start][j];//set distance from the start to the next node 
		
		}
	
visited[start]=1;	//visited node is 1


	
	
//messing with the cost and checking if minimum or not
//finding lowest cost to get there
for(i=0;i<n;i++){
	if(distance[i]!=0&& cost[i]>cost[start]+distance[i])
	{	cost[i]=cost[start]+distance[i];
	
		//setting from for that nxt guys
		from[i]=start;
	
	}
}




nxt=0;
//to find the heir 	 nxt
	for(i=0;i<n;i++){
		if(visited[i]==0&&cost[i]!=999)
			nxt=i;
	}
	
	for(i=0;i<n;i++){
		if(visited[i]==0&&cost[i]!=0&&cost[i]<cost[nxt])
			nxt=i;
	}
	
	




	//to check if all visited or not
	for(i=0;i<n;i++)
	{
		if (visited[i]==0)
		{
			state++;
		
		}
	}
	
	//now go to the next element
	
	
	if(state!=0)
	dijkstra(nxt);
	else
		return;
	
}

void main(){
int i;
int y=check();
int start=0;

//setting cost of untouched to infinity
	
	for(i=0;i<n;i++)
	{	cost[i]=999;
		from[i]=0;
		visited[i]=0;
}//put cost to get there from the start node for all guys as infinity.
	


cost[start]=0;	
	
if(y==0){
dijkstra(start);
  
for(i=0;i<n;i++){
	printf("The path from %d is to %d and cost for that path is %d\n",i,from[i],cost[i]);
}
}
else
	printf("Incorrect graph");






}