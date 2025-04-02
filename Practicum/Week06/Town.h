#ifndef _TOWN_H
#define _TOWN_H

class Town {
public:
	Town(size_t id);
	Town();

	void setId(size_t id);

	size_t getId() const;

private:
	size_t id;
};

#endif // !_TOWN_H
