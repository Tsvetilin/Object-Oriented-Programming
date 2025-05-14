#ifndef _MAGICCARD_H
#define _MAGICCARD_H

constexpr size_t MAX_CARD_NAME_LEN = 25;
constexpr size_t MAX_EFFECT_LEN = 100;

enum class CardType {
	trap,
	buff,
	spell
};

class MagicCard {
public:
	MagicCard(const char* newName, CardType newType, const char* newEffect);
	MagicCard();

	void setName(const char* newName);
	void setCardType(CardType newType);
	void setEffect(const char* newEffect);

	const char* getName() const;
	CardType getType() const;
	const char* getEffect() const;

	const void printMagicCardInfo();

private:
	char name[MAX_CARD_NAME_LEN + 1];
	CardType type;
	char effect[MAX_EFFECT_LEN + 1];
};

#endif // !_MAGICCARD_H