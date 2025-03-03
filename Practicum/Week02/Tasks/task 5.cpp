#include <iostream>
#include <cstring>
#include <fstream>
//to be continued

namespace Constants
{
	const size_t MAX_NAME_SIZE = 32;
	const size_t MAX_DEVICE_COUNT = 100;

}



namespace DeviceandWarehouseNS
{ 
	using namespace Constants;

	enum class Kind
	{
		TV, SMARTPHONE, LAPTOP, PC, CAMERA
	};

	struct Device
		{
		char name[MAX_NAME_SIZE];
		int stock;
		double price;
		Kind kind;
		char provider[MAX_NAME_SIZE];
		};
	
	struct Warehouse
	{
		Device devices[MAX_DEVICE_COUNT];
		char nameOfOwner[MAX_NAME_SIZE];
	};

	Device createDevice()
	{
		Device d;
		int deviceKind;
		std::cin >> d.name >> d.stock >> d.price >> deviceKind >>d.provider;
		d.kind = (Kind)deviceKind;
		return d;
	}
	Warehouse createWarehouse()
	{
		Warehouse w;
		std::cin >> w.nameOfOwner;
		char c;
		for (size_t i = 0; i < MAX_DEVICE_COUNT; i++)
		{
			w.devices[i]=createDevice();
			std::cout << "If you have entered enough press e, else press any leter";
			std::cin >> c;
			if (c == 'e')break;
		}
		return w;
	}
	Warehouse addDeviceinWarehouse(const Device& d, Warehouse& w)
	{
		int i = 0;
		while (w.devices[i++].name[0] && MAX_DEVICE_COUNT >= i);
		strcpy_s(w.devices[i].name, MAX_NAME_SIZE, d.name);
		w.devices[i].stock = d.stock;
		w.devices[i].price = d.price;
		w.devices[i].kind = d.kind;
		strcpy_s(w.devices[i].provider, MAX_NAME_SIZE, d.provider);
		return w;
	}
	
	void writeInFileKind(std::ofstream& ofs, const Warehouse& w, const Kind k)
	{
		int i = 0;
		ofs << "Devices with kind " << (int) k << std::endl;
		while (w.devices[i].name[0] && MAX_DEVICE_COUNT >= i)
		{
			if(w.devices[i].kind==k)
				{
				ofs << "Device number " << i << std::endl;
				ofs << "Device name " << w.devices[i].name<<std::endl;
				ofs << "Device price " << w.devices[i].price << std::endl;
				i++;
				}
		}
		ofs << "Owner name " << w.nameOfOwner << std::endl;
	}

	void writeInFileKind(const char* filename, const Warehouse& w,const Kind k)
	{
		if (!filename) return;
		std::ofstream ofs(filename);
		if (!ofs.is_open()) return;
		return writeInFileKind(ofs, w, k);
	}

	void writeInFile(const char* filename, const Warehouse& w)
	{
		while (!filename) return;

	}
}

int main()
{

	return 0;
}
