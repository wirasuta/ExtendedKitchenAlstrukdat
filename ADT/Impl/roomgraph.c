// Body untuk listlinier.h
// Pandyaka Aptanagi / 13517003

#include <stdio.h>
#include <stdlib.h>
#include "../Header/roomgraph.h"

GRAPH CreateGraph (adrNode X){
	GRAPH G;
	FirstNodeGraph(G) = X;
	return G;
}

adrNode AlokNodeGr (int ID){
	adrNode P = (adrNode) malloc(sizeof(RoomNode));
	if (P != NULL) {
		RoomNumber(P) = ID;
		Trail(P) = Nil;
		NextNode(P) = Nil;
	}
	return P;
}

void DealokNodeGr (adrNode P){
	free(P);
}

adrEdgeNode AlokEdgeNode (GRAPH G, POINT TransitTile, POINT DestTile, int IDNext){
	adrEdgeNode P = (adrEdgeNode) malloc(sizeof(EdgeNode));
	if (P != NULL) {
		adrNode NextR = SearchNode(G, IDNext);
		TransitTile(P) = TransitTile;
		DestTile(P) = DestTile;
		NextRoom(P) = NextR;
		NextTile(P) = Nil;
	}
	return P;
}

void DealokEdgeNode (adrEdgeNode P){
	free(P);
}

adrNode SearchNode (GRAPH G, int X){
	adrNode Pg;
	Pg = FirstNodeGraph(G);
	while(Pg != Nil && X != RoomNumber(Pg)){
		Pg = NextNode(Pg);
	}
	return Pg;
}

adrEdgeNode SearchEdgeNode (GRAPH G, POINT TransitTile, int ID, int IDNext){
	adrNode P = SearchNode(G, ID);
	adrEdgeNode PTrail = Trail(P);
	if (PTrail!=Nil) {
		while (PTrail != Nil && NEQ(TransitTile(PTrail),TransitTile)) {
			PTrail = NextTile(PTrail);
		}
	}
	return PTrail;
}

void addEdgeNode(adrNode *Pn, adrEdgeNode newEdgeNode){
	adrEdgeNode PTrail = Trail(*Pn);
	if (PTrail!=Nil) {
		while (NextTile(PTrail) != Nil) {
			PTrail = NextTile(PTrail);
		}
	}
	if (PTrail == Nil) {
		Trail(*Pn) = newEdgeNode;
	} else {
		NextTile(PTrail) = newEdgeNode;
	}
}
