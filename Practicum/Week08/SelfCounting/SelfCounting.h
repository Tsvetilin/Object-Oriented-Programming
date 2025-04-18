#pragma once

class SelfCounting
{
private:
	const int const_val;

	static int liveObjects;
	static int createdObjects;

public:
	SelfCounting();
	SelfCounting(int const_val);

	SelfCounting(const SelfCounting& other);

	static int getLiveObjects();
	static int getCreatedObjects();

	~SelfCounting();
};
