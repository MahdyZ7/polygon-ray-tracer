#include "raytracing.hpp"

Vector readandconv(std::string line)
{
	std::stringstream str(line);
	std::string v0,v1,v2;
	float		f0,f1,f2;

	getline(str, v0, ' ');
	getline(str, v1, ' ');
	getline(str, v2, ' ');
	std::stringstream(v0) >> f0;
	std::stringstream(v2) >> f1;
	std::stringstream(v2) >> f2;
	// Vector v(stof(v0),stof(v1),stof(v2));
	Vector v(f0,f1,f2);
	// Vector v(atof("10"),atof("10"),atof("10"));
	return (v);
}

std::vector<Triangle> readfile()
{
	std::vector<Triangle> tri;
	std::ifstream inputFile("part.txt");
	std::string line, str;
	uint size;
	if (!inputFile) {
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}

	while (getline(inputFile, line))
	{
		if (line.empty())
			continue;
		Triangle tl;
		getline(inputFile, line);
		tl.p0 = readandconv(line);
		getline(inputFile, line);
		tl.p1 = readandconv(line);
		getline(inputFile, line);
		tl.p2 = readandconv(line);
		tri.push_back(tl);
	}

	inputFile.close();
	std::cout << "done\n";
	return tri;
}
