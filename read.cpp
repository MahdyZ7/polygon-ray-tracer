#include "raytracing.hpp"

Vector readandconv(std::string line)
{
	std::stringstream str(line);
	std::string v0,v1,v2;
	float		f0,f1,f2;

	getline(str, v0, ' ');
	getline(str, v1, ' ');
	getline(str, v2, '\n');
	std::stringstream(v0) >> f0;
	std::stringstream(v1) >> f1;
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
	if (!inputFile) {
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}

	while (getline(inputFile, line))
	{
		if (line.empty())
			continue;
		Triangle tl;
		tl.v0 = readandconv(line);
		getline(inputFile, line);
		tl.v1 = readandconv(line);
		getline(inputFile, line);
		tl.v2 = readandconv(line);
		tri.push_back(tl);

	}

	inputFile.close();
	std::cout << "done\n";
	return tri;
}

Vector readandconvstl(std::string line)
{
	std::stringstream str(line);
	std::string v0,v1,v2;
	float		f0,f1,f2;

	getline(str, v0, ' ');
	getline(str, v1, ' ');
	getline(str, v2, '\n');
	std::stringstream(v0) >> f0;
	std::stringstream(v1) >> f1;
	std::stringstream(v2) >> f2;
	// Vector v(stof(v0),stof(v1),stof(v2));
	Vector v(f0,f1,f2);
	// Vector v(atof("10"),atof("10"),atof("10"));
	return (v);
}

std::vector<Triangle> readstl()
{
	// static int l;
	std::vector<Triangle> tri;
	std::ifstream inputFile("teapot.stl");
	std::string line, str;
	if (!inputFile) {
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	getline(inputFile, line);
	while (getline(inputFile, line))
	{
		if (line.empty() || line == "endsolid teapotouts*")
			continue;
		Triangle tl;
		line = line.substr(15);
		tl.norm = readandconvstl(line);
		getline(inputFile, line);
		getline(inputFile, line);
		line = line.substr(13);
		tl.v0 = readandconv(line);
		getline(inputFile, line);
		line = line.substr(13);
		tl.v1 = readandconv(line);
		getline(inputFile, line);
		line = line.substr(13);
		tl.v2 = readandconv(line);
		getline(inputFile, line);
		getline(inputFile, line);
		// std::cout << "NEW Tri: " << tl << std::endl;
		// std::cout << "***" << line << std::endl;
		// if (l == 2)
		// 	exit(1);
		// ++l;
		tri.push_back(tl);

	}

	inputFile.close();
	std::cout << "done\n";
	return tri;
}
