/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "tepokpramuka_type.h"
#include "point.h"

GRAPH CreateGraph (adrNode X);

adrNode AlokNodeGr (int ID);

void DealokNodeGr (adrNode P);

adrEdgeNode AlokEdgeNode (GRAPH G, POINT TransitTile, POINT DestTile, int IDNext);

void DealokEdgeNode (adrEdgeNode P);

adrNode SearchNode (GRAPH G, int X);

adrEdgeNode SearchEdgeNode (GRAPH G, POINT TransitTile, int ID,  int IDNext);

void addEdgeNode(adrNode *Pn, adrEdgeNode newEdgeNode);

#endif
