#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "constants.h"

/**
 * Asks the user for a file to load.
 * @author Ricky Hempel
 * @param fileName   A string containing the file to open.
 * @date 04/28/2017
 * @return void
 */
void getFileName(char fileName[]);

/**
 * Opens a file to read in a graph.
 * @author Ricky Hempel
 * @param fileName   A string containing the file to open.
 * @date 04/28/2017
 * @return A FILE* object containing a stream to the opened file.
 */
FILE* openFile(char fileName[]);

int main(int argc, char* argv[])
{
  char fileName[1000];

  /* If a filename was passed at runtime, copy it to the fileName var. */
  if(argc > 1)
    {
      strcpy(fileName, argv[1]);
    }
  
  FILE* file;
  
  int graphVertexSize = 0;
  int MSTVertexSize = 0;

  char graphVertexNames[NUM_VERTICES][VERT_NAME_LEN];
  char MSTVertexNames[NUM_VERTICES][VERT_NAME_LEN];

  char graphEdges[NUM_VERTICES][NUM_EDGES][2][VERT_NAME_LEN];
  int graphEdgeSize[NUM_VERTICES] = {0};

  char MSTEdges[NUM_VERTICES][NUM_EDGES][2][VERT_NAME_LEN];
  int MSTEdgeSize[NUM_VERTICES] = {0};

  char vert1[VERT_NAME_LEN];
  char vert2[VERT_NAME_LEN];
  char weight[VERT_NAME_LEN];

  /* Check if file was passed at runtime. Get the file to load if not. */
  if(argc == 1)
    {
      getFileName(fileName);
    }
  file = openFile(fileName); /* Try to open the file. */

  /* Read the graph from the file. */
  readData(graphVertexNames,&graphVertexSize,graphEdges,graphEdgeSize,file);
  fclose(file);

  /* Print the input graph before we modify it. */
  printf("Input Graph:\n");
  printGraph(graphVertexNames,graphVertexSize,graphEdges,graphEdgeSize);
  printf("\n");

  /* Prime the MST graph before entering the while loop. */
  /* Find the smallest edge connected to the first vertex in the input graph. */
  strcpy(vert1,graphVertexNames[0]);
  strcpy(vert2,graphEdges[0][getMinEdge(0,graphEdges,graphEdgeSize)][0]);
  strcpy(weight,graphEdges[0][getMinEdge(0,graphEdges,graphEdgeSize)][1]);

  /* Add the edge to the MST. */
  addEdge(vert1,vert2,weight,MSTVertexNames,&MSTVertexSize,MSTEdges,
	  MSTEdgeSize);

  /* Remove the edge from the input graph. */
  removeEdge(vert1,vert2,weight,graphVertexNames,graphVertexSize,graphEdges,
	     graphEdgeSize);

  /* Master while loop to find and add the remaining edges in the MST. */
  while(graphVertexSize != MSTVertexSize)
    {
      int i;
      int locSize = 0;
      int locVert[NUM_VERTICES] = {-1};
      int locEdge[NUM_VERTICES] = {-1};
      int min[NUM_VERTICES] = {-1};
      int minLoc = -1;
      int minVal = -1;

      /* Find the location in the input graph of all vertices in the MST . */
      for(i = 0; i < MSTVertexSize; i++)
	{
	  int vertexLoc = findVertIndex(MSTVertexNames[i],graphVertexSize,
					graphVertexNames);
	  locVert[locSize] = vertexLoc;
	  locSize++;
	}

      /* Find all minimal connected edges. */
      for(i = 0; i < locSize; i++)
	{
	  int minLoc = getMinEdge(locVert[i],graphEdges,graphEdgeSize);
	  locEdge[i] = minLoc;
	  min[i] = atoi(graphEdges[locVert[i]][minLoc][1]);
	}

      /* Find the minimal edge. */
      for(i = 0; i < locSize; i++)
	{
	  if((minLoc == -1 || min[i] < minVal) && min[i] != 0)
	    {
	      minLoc = i;
	      minVal = min[i];
	    }
	}

      /* Prep for adding the edge. */
      strcpy(vert1,graphVertexNames[locVert[minLoc]]);
      strcpy(vert2,graphEdges[locVert[minLoc]][locEdge[minLoc]][0]);
      strcpy(weight,graphEdges[locVert[minLoc]][locEdge[minLoc]][1]);

      /* Add edge to MST, remove from graph. */
      addEdge(vert1,vert2,weight,MSTVertexNames,&MSTVertexSize,MSTEdges,
	      MSTEdgeSize);
      removeEdge(vert1,vert2,weight,graphVertexNames,graphVertexSize,
		 graphEdges,graphEdgeSize);

      /* Remove any edges that would cause a cycle. */
      preventCycles(graphVertexNames,graphVertexSize,graphEdges,graphEdgeSize,
		    MSTVertexNames,MSTVertexSize);
    }

  /* Print the MST. */
  printf("MST Graph:\n");
  printGraph(MSTVertexNames,MSTVertexSize,MSTEdges,MSTEdgeSize);
      
  return 0;
}

void getFileName(char fileName[])
{
  printf("Enter graph file name: ");
  scanf("%999s",fileName);

  return;
}

FILE* openFile(char fileName[])
{
  FILE* file;
  file = fopen(fileName,"r");

  /* Make sure we opened the file. Retry if not. */
  while(file == NULL)
    {
      printf("Can't open file.\n");
      getFileName(fileName);
      file = fopen(fileName,"r");
    }

  return file;
}