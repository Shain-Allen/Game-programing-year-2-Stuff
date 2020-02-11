#include "stdafx.h"
#include "Tilemap.h"

std::string Tilemap::mapPath = "levels";

Tilemap::Tilemap(unsigned numColumns, unsigned numRows, int** data)
	: numColumns(numColumns), numRows(numRows), data(data)
{
}

Tilemap::~Tilemap()
{
	for (int x = 0; x < numColumns; x++)
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
	return nullptr;
}

bool Tilemap::ReadIntegerVariable(std::ifstream& file, const std::string& name, int& variable)
{
	using namespace std;

	file.open;
	if (!file.is_open())
	{
		cout << "could not open file: " << name << endl;
		return;
	}

	string nextword;
	while (!file.eof())
	{
		if (getline(file, nextword).eof())
		{
			break;
		}

		if (nextword == name)
		{
			file >> variable;
		}
	}

}

int** Tilemap::ReadArrayVariable(std::ifstream& file, const std::string& name, unsigned columns, unsigned rows)
{
	return nullptr;
}
