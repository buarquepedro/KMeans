#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <sstream>
#include "Kmeans.h"

using namespace std;

int main(int argc, char const *argv[]) {

	Kmeans kmeans(2);

	ifstream ifs("data/breast-cancer-mini.txt");
	vector<FeaturedVector> dataSet;
	signed int index = 0;
	string line;


	while (getline(ifs, line)) {
		stringstream buffer(line);
		vector<double> vetor;
		double feature;

		while (buffer >> feature) {
			if (buffer.peek() == ',') {
				buffer.ignore();
			}
			vetor.push_back(feature);
		}

		vetor.erase(vetor.begin());
		int targetClass = vetor.back();

		if (targetClass == 2) {
			targetClass = 0;
		} else {
			targetClass = 1;
		}

		vetor.pop_back();
		FeaturedVector featuredVector(vetor);
		featuredVector.setVectorIndex(index);
		featuredVector.setTargetClass(targetClass);
		dataSet.push_back(featuredVector);
		++index;
	}

	ifs.close();

	// for (FeaturedVector &f : dataSet) {
	// 	cout << setw(3) << f.getVectorIndex() << " - " << setw(24) << f.toString() << setw(5) << f.getTargetClass() << endl;
	// }

	kmeans.fit(dataSet);
	kmeans.displayClusters();
	cout << kmeans.getScore() << endl;

	return 0;
}
