#include <iostream>
#include <fstream>

namespace Constants
{
	const size_t NUMBER_COLORS = 3;
	const size_t FORMULA_RED = 65536;
	const size_t FORMULA_GREEN = 256;
	const size_t MAX_NUM_COLORS = 10;
}

struct Color
{
	int red, green, blue;
};

namespace ColorNM
{
	using namespace Constants;

	Color getColor(int temp)
	{
		Color c;
		c.red = temp / FORMULA_RED;
		temp %= FORMULA_RED;  
		c.green = temp / FORMULA_GREEN;
		c.blue = temp % FORMULA_GREEN;
		return c;
	}

	Color* readColors(std::ifstream& ifs, size_t& count)
	{
		Color* colors = new Color[MAX_NUM_COLORS];
		int temp;
		count = 0;

		while (ifs >> temp && count < MAX_NUM_COLORS) {
			ifs.get();
			colors[count++] = getColor(temp);
		}
		ifs.close();
		return colors;
	}

	Color* readColors(const char* filename, size_t& count)
	{
		if (!filename) return nullptr;
		std::ifstream ifs(filename);
		if (!ifs.is_open()) return nullptr;
		return readColors(ifs, count);
	}

	void WriteColors(std::ofstream& ofs, const Color* colors)
	{
		for (size_t i = 0; i < MAX_NUM_COLORS; i++)
		{
			std::cout << colors[i].red * FORMULA_RED + colors[i].green * FORMULA_GREEN + colors[i].blue << '|'; // last one also having |
		}
		ofs.close();
	}


	void WriteColors(const char* filename,const Color* colors)
	{
		if (!colors) return;
		if (!filename) return;
		std::ofstream  ofs(filename);
		WriteColors(ofs, colors);
	}

	void redColorCheckerFile(const Color* colors, size_t count)
	{
		if (!colors) return;
		std::ofstream ofs("red.txt");
		if (!ofs.is_open()) return;

		for (size_t i = 0; i < count; i++)
		{
			if (colors[i].red >= 250) {
				ofs << colors[i].red << ' ' << colors[i].green << ' ' << colors[i].blue << '\n';
			}
		}
		ofs.close();
	}
}

int main31414()
{
	using namespace ColorNM;

	size_t count;
	Color* colors = readColors("color.txt", count);

		redColorCheckerFile(colors, count);
		delete[] colors;  

	return 0;
}
