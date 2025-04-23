#pragma once

enum class TypesOfCards
{
	trap,buff,spell
};

namespace {
	const size_t nameLen = 25;
	const size_t effectLen = 100;
}

class MagicCards
{
private:
	char name[::nameLen + 1] = "\0";
	char effect[::effectLen + 1] = "\0";
	TypesOfCards type = TypesOfCards(0);
public:
	MagicCards();
	MagicCards(const char* name,const char* effect,TypesOfCards type);

	const char* getName()const;
	const char* getEffect()const;
	TypesOfCards getType()const;
};

