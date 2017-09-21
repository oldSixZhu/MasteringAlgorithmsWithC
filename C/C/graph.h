//
//  graph.h
//  C
//
//  Created by Mac on 2017/9/15.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include "list.h"
#include "set.h"

//结点
typedef struct AdjList_{
    void *vertex;
    Set adjacent;
    
}AdjList;

typedef struct Graph_{
    int vcount;
    int ecount;
    int (*match)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    List adjlists;
}Graph;

typedef enum VertexColor_ {
    white,gray,black
}VertexColor;

void graph_init(Graph *graph,int (*match)(const void *key1,const void *key2),void (*destroy)(void *data));

void graph_destroy(Graph *graph);
//将一个顶点插入图中
int graph_ins_vertex(Graph *graph,const void *data);
//将一条边插入图中
int graph_ins_edge(Graph *graph,const void *data1,const void *data2);
int graph_rem_vertex(Graph *graph,void **data);
int graph_rem_edge(Graph *graph,void *data1,void **data2);
//取出graph中由data指定的顶点的邻接表
int graph_adjlist(const Graph *graph,const void *data,AdjList **adjlist);
//判断由data2所指定的顶点是否与graph中由data1所指定的顶点邻接
int graph_is_adjacent(const Graph *graph,const void *data1,const void *data2);

#define graph_adjlists(graph) ((graph)->adjlists)
#define graph_vcount(graph) ((graph)->vcount)
#define graph_ecount(graph) ((graph)->ecount)

#endif /* graph_h */



























