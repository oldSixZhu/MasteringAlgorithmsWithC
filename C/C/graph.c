//
//  graph.c
//  C
//
//  Created by Mac on 2017/9/15.
//  Copyright © 2017年 oldSix. All rights reserved.
//

#include "graph.h"

#include <stdlib.h>
#include <string.h>

void graph_init(Graph *graph,int (*match)(const void *key1,const void *key2),void (*destroy)(void *data))
{
    graph->vcount = 0;
    graph->ecount = 0;
    graph->match = match;
    graph->destroy = destroy;
    list_init(&graph->adjlists, NULL);
    return;
}

void graph_destroy(Graph *graph)
{
    AdjList *adjlist;
    //删除每个邻接表结构并摧毁它的邻接表
    while (list_size(&graph->adjlists) > 0)
    {
        if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
        {
            set_destroy(&adjlist->adjacent);
            if (graph->destroy != NULL)
            {
                graph->destroy(adjlist->vertex);
            }
            free(adjlist);
        }
    }
    list_destroy(&graph->adjlists);
    memset(graph, 0, sizeof(Graph));
    return;
}

int graph_ins_vertex(Graph *graph,const void *data)
{
    ListElmt *element;
    AdjList *adjlist;
    int retval;
    //不允许插入重复的顶点
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data,((AdjList*)list_data(element))->vertex))
        {
            return 1;
        }
    }
    //插入
    if ((adjlist = (AdjList *)malloc(sizeof(AdjList))) == NULL)
    {
        return -1;
    }
    adjlist->vertex = (void *)data;
    set_init(&adjlist->adjacent, graph->match, NULL);
    if ((retval = list_ins_next(&graph->adjlists, list_tail(&graph->adjlists), adjlist)) != 0)
    {
        return retval;
    }
    
    graph->vcount++;
    return 0;
}

int graph_ins_edge(Graph *graph,const void *data1,const void *data2)
{
    ListElmt *element;
    int retval;
    //不允许插入两个顶点都不在图上的边
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data2,((AdjList *)list_data(element))->vertex))
        {
            break;
        }
    }
    if (element == NULL)
    {
        return -1;
    }
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data1,((AdjList *)list_data(element)) -> vertex))
        {
            break;
        }
    }
    if (element == NULL)
    {
        return -1;
    }
    //在邻接表第一个顶点后插入第二个顶点
    if ((retval = set_insert(&((AdjList *)list_data(element))->adjacent, data2)) != 0)
    {
        return retval;
    }
    graph -> ecount++;
    return 0;
}

int graph_rem_vertex(Graph *graph,void **data)
{
    ListElmt *element,*temp = NULL,*prev;
    AdjList *adjlist;
    int found;
    //遍历每个邻接表和包含的顶点
    prev = NULL;
    found = 0;
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        //不允许删除这个顶点，如果在邻接表中
        if (set_is_member(&((AdjList *)list_data(element))->adjacent, *data))
        {
            return -1;
        }
        if (graph->match(*data,((AdjList *)list_data(element))->vertex))
        {
            temp = element;
            found = 1;
        }
        if (!found)
        {
            prev = element;
        }
    }
    //若果顶点没有找到就返回
    if (!found)
    {
        return -1;
    }
    //如果邻接表不是空的，不允许删除顶点
    if (set_size(&((AdjList *)list_data(temp)) -> adjacent) > 0)
    {
        return -1;
    }
    //删除顶点
    if (list_rem_next(&graph->adjlists, prev, (void **)&adjlist)!= 0)
    {
        return -1;
    }
    *data = adjlist->vertex;
    free(adjlist);
    graph->vcount--;
    return 0;
}

int graph_rem_edge(Graph *graph,void *data1,void **data2)
{
    ListElmt *element;
    //找到第一个顶点的邻接表
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data1,((AdjList *)list_data(element))->vertex))
        {
            break;
        }
    }
    if (element == NULL)
    {
        return -1;
    }
    //删除第一个顶点邻接表的第二个顶点
    if (set_remove(&((AdjList *)list_data(element))->adjacent, data2) != 0)
    {
        return -1;
    }
    graph->ecount--;
    return 0;
}

int graph_adjlist(const Graph *graph,const void *data,AdjList **adjlist)
{
    ListElmt *element,*prev;
    //定位顶点的邻接表
    prev = NULL;
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data,((AdjList *)list_data(element))->vertex))
        {
            break;
        }
        prev = element;
    }
    if (element == NULL)
    {
        return -1;
    }
    *adjlist = list_data(element);
    return 0;
}

int graph_is_adjacent(const Graph *graph,const void *data1,const void *data2)
{
    ListElmt *element,*prev;
    prev = NULL;
    //定位第一个顶点的邻接表
    for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element))
    {
        if (graph->match(data1,((AdjList *)list_data(element))->vertex))
        {
            break;
        }
        prev = element;
    }
    if (element == NULL)
    {
        return 0;
    }
    return set_is_member(&((AdjList *)list_data(element))->adjacent, data2);
}






















