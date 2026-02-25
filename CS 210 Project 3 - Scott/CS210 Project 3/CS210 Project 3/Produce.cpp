#include "Produce.h"
#include <string>

Produce::Produce() {
	name = "NoName";
	count = 0;
}

Produce::Produce(string initName) {
	name = initName;
	count = 1;
}

void Produce::SetName(string newName) {
	name = newName;
}

string Produce::GetName() {
	return name;
}

void Produce::AddCount() {
	count += 1;
}

int Produce::GetCount() {
	return count;
}

void Produce::PrintProduct() {
	cout << GetName() << " " << GetCount() << endl;
}