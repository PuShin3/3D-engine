#pragma once
#ifndef _QUADTREE_H_
#define _QUADTREE_H_
#endif
#include "Struct.h"
#include <math.h>

struct Node{
	vec2d pos;
	int data;
	Node(vec2d _pos, int _data);
	Node();
};

struct Quadtree {
	vec2d topLeft;
	vec2d botRight;

	Node *n;
	Quadtree *topLeftTree;
	Quadtree *topRightTree;
	Quadtree* botLeftTree;
	Quadtree* botRightTree;

public:
	Quadtree();
	Quadtree(vec2d topL, vec2d botR);
	void insert(Node*);
	Node* search(vec2d);
	bool inBoundary(vec2d);
};