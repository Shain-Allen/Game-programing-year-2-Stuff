#include "stdafx.h"
#include "Tilemap.h"

std::string Tilemap::mapPath = "Assets\\levels\\";

Tilemap::Tilemap(unsigned numColumns, unsigned numRows, int** data)
	: numColumns(numColumns), numRows(numRows), data(data)
{
}

Tilemap::~Tilemap()
{
	for (unsigned int x = 0; x < numColumns; x++)
	{
		delete[] data[x];
		data[x] = nullptr;
	}

	delete[] data;
	data = nullptr;
}

unsigned Tilemap::GetWidth() const
{
	return numColumns;
}

unsigned Tilemap::GetHeight() const
{
	return numRows;
}

int Tilemap::GetCellValue(unsigned column, unsigned row) const
{
	return data[column][row];
}

Tilemap* Tilemap::CreateTilemapFromFile(const std::string& filename)
{
	using namespace std;
	ifstream file;

	file.open(mapPath + filename);

	if (!file.is_open())
	{
		cout << "No file found" << endl;
		return nullptr;
	}

	int rows;
	int columns;
	int** mapdata;

	if (!ReadIntegerVariable(file, "width", columns))
		return nullptr;;
	if (!ReadIntegerVariable(file, "height", rows))
		return nullptr;;
	mapdata = ReadArrayVariable(file, "data", columns, rows);
	if (mapdata == nullptr)
		return nullptr;;

	Tilemap* tilemap = new Tilemap(columns, rows, mapdata);

	return tilemap;
}

bool Tilemap::ReadIntegerVariable(std::ifstream& file, const std::string& name, int& variable)
{
	using namespace std;

	string nextword;
	file >> nextword;

	if (nextword == name)
	{
		file >> variable;
		cout << nextword << ": " << variable << endl;
		return true;
	}

	cout << "no " << name << endl;
	return false;
}

int** Tilemap::ReadArrayVariable(std::ifstream& file, const std::string& name, unsigned columns, unsigned rows)
{
	using namespace std;

	string nextword;
	file >> nextword;

	if (nextword == name)
	{

		int** newData;

		newData = new int*[columns];

		for (unsigned int i = 0; i < columns; i++)
		{
			newData[i] = new int[rows];
		}

		for (unsigned int y = 0; y < rows; y++)
		{
			for (unsigned int x = 0; x < columns; x++)
			{
				file >> newData[x][y];
				cout << newData[x][y];
			}
			cout << endl;
		}

		return newData;
	}

	cout << "no " << name << endl;
	return nullptr;
}
