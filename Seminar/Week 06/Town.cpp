#include "Town.h"
#include<iostream>

Town::Town(size_t id) {
	setId(id);
}

Town::Town() {
	this->id = 0;
}

void Town::setId(size_t id) {
	this->id = id;
}

size_t Town::getId() const {
	return this->id;
}
