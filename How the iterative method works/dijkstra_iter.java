import java.util.*;

class Graph
{
 int nodes;
 int edges;
 int grph[][];
 
 void accept()
 {
	 int n;
  Scanner sc=new Scanner(System.in);
  System.out.println("Number of nodes : ");
  nodes = sc.nextInt();
    grph = new int[nodes][nodes];
  System.out.println("Enter the adjencency matrix :");

  for(int i = 0; i < nodes; i++)
   for(int j = 0; j < nodes; j++){
	System.out.println("("+(i+1)+","+(j+1)+")");
	n=sc.nextInt();
if(n==0) grph[i][j] = 9999;
 else grph[i][j] = n;
   }  
 }
}

class Main {
 
 static void dijk(Graph g, int src, int des)
 {
  int distance[] = new int[g.nodes];
  int previous[] = new int[g.nodes];
  String path[] = new String[g.nodes];
  for(int i = 0; i < g.nodes; i++)
  {
   distance[i] = 9999;
   previous[i] = -1;
   path[i] = "";
  }
  distance[src] = 0;
  for(int i = 0; i < g.nodes; i++)
  {
   for(int j = 0; j < g.nodes; j++)
   {
    if(distance[i] + g.grph[i][j] < distance[j])
    {
     distance[j] = distance[i] + g.grph[i][j];
     previous[j] = i;
    }
   }
  }
  for(int i = 0; i < g.nodes; i++)
  {
   int current = i;
   do
   {
    path[i] = "-" + (current + 1) + path[i];
    current = previous[current];
   }
   while(current != -1);
   path[i] = path[i].substring(1, path[i].length());
  }
   System.out.println("The shortest path from "+(src+1)+" node to "+(des+1)+" node is :");
  System.out.println();
  
   if(des != src)
   {
    System.out.println("Distance for node " + (des + 1) + " is:");
    System.out.print("Path: " + path[des]);
    System.out.println("\nDistance: " + distance[des]);
	System.out.println("");
    
   }
  
 }
 
 public static void main(String args[]) 
 {
	 Scanner sc=new Scanner(System.in);
  Graph g = new Graph();
  g.accept();
  System.out.println("Enter the Starting node: ");
  int a=sc.nextInt();
  for(int b=1;b<=g.nodes;b++)
  dijk(g, (a-1),(b-1));
 }
}

