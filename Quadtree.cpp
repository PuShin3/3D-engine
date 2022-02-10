#include "Quadtree.h"

Node::Node(vec2d _pos, int _data) {
	pos = _pos;
	data = _data;
}
Node::Node() {
	data = 0;
}

Quadtree::Quadtree() {
	topLeft = { 0, 0 };
	botRight = { 0, 0 };
	n = NULL;
	topLeftTree = NULL;
	topRightTree = NULL;
	botLeftTree = NULL;
	botLeftTree = NULL;
}

Quadtree::Quadtree(vec2d topL, vec2d botR) {
	n = NULL;
	topLeftTree = NULL;
	topRightTree = NULL;
	botLeftTree = NULL;
	botRightTree = NULL;
	topLeft = topL;
	botRight = botR;
}

void Quadtree::insert(Node* node) {
	if (node == NULL) return;

	if (!inBoundary(node->pos)) return;

	if (abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y)) {
		if (n == NULL) n = node;
		return;
	}
	if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topLeftTree = NULL) {
				topLeftTree = new Quadtree({ topLeft.x, topLeft.y },
					{ (topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2 });
			}
			topLeftTree->insert(node);
		}
		else {
			if (botLeftTree = NULL) {
				botLeftTree = new Quadtree({ topLeft.x, (topLeft.y + botRight.y) / 2 },
					{ (topLeft.x + botRight.x) / 2, botRight.y });
			}
			botLeftTree->insert(node);
		}
	}
	else {
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topRightTree = NULL) {
				topRightTree = new Quadtree({ (topLeft.x + botRight.x) / 2, topLeft.y },
					{ botRight.x, (topLeft.y + botRight.y) / 2 });
			}
			topRightTree->insert(node);
		}
		else {
			if (botRightTree = NULL) {
				botRightTree = new Quadtree({ (topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2 },
					{ topLeft.x, botRight.y });
			}
			botRightTree->insert(node);
		}
	}
}

Node* Quadtree::search(vec2d p) {
	if (!inBoundary(p)) return NULL;

	if (n != NULL) return n;

	if ((topLeft.x + botRight.x) / 2 >= p.x) {
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topLeftTree == NULL) return NULL;
			return topLeftTree->search(p);
		}
		else {
			if (botLeftTree == NULL) return NULL;
			return botLeftTree->search(p);
		}
	}
	else {
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topRightTree == NULL) return NULL;
			return topRightTree->search(p);
		}
		else {
			if (botRightTree == NULL) return NULL;
			return botRightTree->search(p);
		}
	}
}

bool Quadtree::inBoundary(vec2d p) {
	return (p.x >= topLeft.x &&
		p.x <= botRight.x && 
		p.y >= topLeft.y && 
		p.y <= botRight.y);
}